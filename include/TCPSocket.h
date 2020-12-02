#ifndef TCPSocket_H
#define TCPSocket_H

#include"DefHead.h"

#include<sys/socket.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>

#include<string>
#include<unistd.h>
#include<iostream>

//���ͺ��������ʧ�ܾͷ�����ϸ��Ϣ,�ɹ���Ϊ__SUCCESS
int TCPSend
(
	_In_ int  nsocket,
	_In_ std::string buff,
	_In_ unsigned long buffsize
);

//���պ��������ʧ�ܾͷ�����ϸ��Ϣ,�ɹ���Ϊ__SUCCESS
extern unsigned long TCPRecv
(
	_In_  int  nsocket,
	_In_ char* buff,
	_In_ unsigned long buffsize
);

//���պ��������ʧ�ܾͷ�����ϸ��Ϣ,�ɹ���Ϊ__SUCCESS
extern unsigned long TCPSendRecv
(
	_In_ int nsocket,
	_In_ std::string sbuff,
	_In_ unsigned long& sbuffsize,
	_Inout_ char* rbuff,
	_Inout_ unsigned long& rbuffsize
);

//�շ�����,���ʧ�ܾͷ�����ϸ��Ϣ,�ɹ���Ϊ__SUCCESS
extern unsigned long TCPRecvSend
(
	_In_ int nsocket,
	_In_ std::string sbuff,
	_In_ unsigned long& sbuffsize,
	_Inout_ char* rbuff,
	_Inout_ unsigned long& rbuffsize
);

class  TCPSocket
{
public:
	//function
	//���캯����ʼ��TCPSocket�׽���
	explicit TCPSocket();
	explicit TCPSocket
	(
		_In_ int port,
		_In_ unsigned long ip,
		_Inout_ unsigned long& back
	);
	explicit TCPSocket
	(
		_In_ int port,
		_In_ std::string ip,
		_Inout_ unsigned long& back
	);
	int SocketInit();
	~TCPSocket();

	//set����
	void setPort(_In_ int Port);
	void setIp(_In_ unsigned long ip);
	void setIp(_In_ std::string ip);

	//static function
	//����ģʽ�ӿ�����
	static TCPSocket* getInterface
	(
		_In_ int port,
		_In_ std::string ip,
		_Inout_ unsigned long& back
	);
	//����ģʽ���ʽӿ�
	static TCPSocket* getInterface
	(
		_In_ int port,
		_In_ unsigned long ip,
		_Inout_ unsigned long& back
	);
	//����˼����󶨺��������˼�������
	int TCPbind();
	//��������ʹ�ûص�����
	//��̬������ǳ�Ա�ص���������ʹ�ô˺���
	int TCPListen
	(
		_In_ void(*callback)(int, struct sockaddr_in),
		_In_ int ListenNum
	);
	//�ͻ��˷��������׽��֣�ʹ�ûص�����
	int TCPConnect
	(
		_In_ void (*callback)(int,struct sockaddr_in),
		_In_ int& back
	);
	int* TCPConnect
	(
		_In_ int& back
	);
	//�ر��׽���,���ʧ�ܷ���ԭʼWINAPI WSAGetLastError()��������ֵ
	int TCPClose();

private:
	//var
	static TCPSocket* __Inter;
	//�˿���ip
	int port;
	std::string ip;
	unsigned long UIP;
	//�׽�����addr�ṹ��
	int MSocket;
	struct sockaddr_in addr_in;
};
#endif	//TCPSocket_H
