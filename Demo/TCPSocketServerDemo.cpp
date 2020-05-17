#include"TCPSocket.h"
//server测试代码
//监听回调函数
void callbackListen(int S, struct sockaddr_in addrin)
{
	//设置接受数据缓冲区
	char buff[100];
	unsigned long buffsize = sizeof(buff);
	unsigned long i=TCPRecv(S, buff, buffsize);
	//如果接受失败
	if (i == -1)
	{
		return;
	}
	else
		cout << buff;

	//发收函数
	string sendstr = "\nthis is server\n";
	char recvstr[100];

	unsigned long ssize = sendstr.length();
	unsigned long rsize = 100;
	i = TCPSendRecv(S, sendstr.c_str(), ssize, recvstr, rsize);
	if (i == -1)
	{
		return;
	}
	else
	{
		cout << recvstr;
	}
}

int main
(
	_In_ int argv,
	_In_ char*argc[]
)
{
	//用于获取错误值变量
	unsigned long y = 0;
	//单例模式初始化对象
	TCPSocket* s = TCPSocket::getInterface(1080, "127.0.0.1", y);
	//如果出错
	if (s == NULL)
	{
		cout << "socket init error " << y;
		return 0;
	}
	//绑定
	y=s->TCPbind();
	if (y == __ERROR)
	{
		cout << "bind error ";
		s->TCPClose();
		return 0;
	}
	//监听开始，要传入一个非类对象成员函数作为回调函数
	y = s->TCPListen(callbackListen, 5);
	if (y != __SUCCESS)
	{
		cout << "listen error " << y;
		s->TCPClose();
		return 0;
	}
	y=s->TCPClose();
	if (y != __SUCCESS)
	{
		cout << "close error " << y;
		return 0;
	}
	return 0;
}