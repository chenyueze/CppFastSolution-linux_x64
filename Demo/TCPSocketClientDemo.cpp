#include"TCPSocket.h"
//client 测试代码
//连接回调函数
void io(int so, struct sockaddr_in ain)
{
	//发送消息
	unsigned long i = TCPSend(so, "connect success!\n", sizeof("connect success!\n"));
	if (i == -1)
	{
		return;
	}

	//收发函数，收不到数据就不发送直接返回
	string sendstr = "\nclient recv!\n";
	char rbuff[100];

	unsigned long ssize = sendstr.length();
	unsigned long rsize = sizeof(rbuff);
	i = TCPRecvSend(so, sendstr.c_str(), ssize, rbuff, rsize);
	if (i != __SUCCESS)
	{
		cout << " rs error " << i;
		return;
	}
	cout << rbuff;
}

int main
(
	_In_ int argv,
	_In_ char*argc[]
)
{
	//用于获取错误值
	unsigned long backNum = 0;
	//使用但单例模式初始化对象
	TCPSocket* s=TCPSocket::getInterface(1080, "127.0.0.1", backNum);
	//如果初始化失败
	if (s == NULL)
	{
		cout << "init error " << backNum;
		return 0;
	}

	int y = 0;
	//向服务端发起连接
	int i=s->TCPConnect(io,y);
	if (i != __SUCCESS)
	{
		cout << "connect error " << i<<" "<<y;
		 s->TCPClose();
		return 0;
	}
	//回调函数执行完毕后关闭套接字
	i = s->TCPClose();
	if (i != __SUCCESS)
	{
		cout << "close error" << i;
		return 0;
	}
	return 0;
}