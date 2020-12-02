#pragma once
#ifndef UDPSOCKET_H
#define UDPSOCKET_H

#include"DefHead.h"

#include<sys/socket.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>

#include<cstring>
#include<unistd.h>
#include<iostream>


class  UDPSocket
{
public:
	//function
	//���캯����ʼ��UDPSocket�׽���
	explicit UDPSocket();
	explicit UDPSocket
	(
		_In_ int port,
		_In_ std::string ip,
		_Inout_ unsigned long& back
	);

	explicit UDPSocket
	(
		_In_ int port,
		_In_ unsigned long ip,
		_Inout_ unsigned long& back
	);

	int SocketInit();

	int UDPRecvfrom
	(
		_Inout_ char* recvBuff,
		_Inout_ unsigned long recvSize
	);

	int UDPSendto
	(
		_In_ const char* sendBuff,
		_In_ unsigned long sendSize
	);

	~UDPSocket();

	//set����
	void setPort(_In_ int Port);
	void setIp(_In_ std::string ip);

	//static function
	//����ģʽ�ӿ�����
	static UDPSocket* getInterface
	(
		_In_ int port,
		_In_ std::string ip,
		_Inout_ unsigned long& back
	);
	static UDPSocket* getInterface
	(
		_In_ int port,
		_In_ unsigned long ip,
		_Inout_ unsigned long & back
	);


	//����˼����󶨺��������˼�������
	int UDPbind();

	//�ر��׽���,���ʧ�ܷ���ԭʼWINAPI WSAGetLastError()��������ֵ
	int UDPClose();

private:
	//var
	static UDPSocket* __Inter;
	//�˿���ip
	int port;
	std::string ip;
	unsigned long UIP;
	//�׽�����addr�ṹ��
	int MSocket;
	struct sockaddr_in addr_in;
};
#endif	//UDPSocket_H
