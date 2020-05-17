#ifndef SMTPSOCKET_H
#define SMTPSOCKET_H

#include"Base64.h"
#include"TCPSocket.h"
#include"DefHead.h"
#include<vector>

class SMTPSocket
{
public:
	explicit SMTPSocket();
	//����˽�����Ե�set����
	void setIpAddress(string ip);
	void setPort(int port);
	void setHostName(string hostname);
	//�û�������������
	void setUserPasswd
	(
		_In_ string user,
		_In_ string passwd
	);
	void setFromandTo
	(
		_In_ string from,
		_In_ string sendto
	);
	void setSubjectandMsg
	(
		_In_ string subject,
		_In_ string Msg,
		_In_ unsigned MsgSize
	);
	void addRcpto(string rcpto);
	//��ʼ�����¼����
	int SMTPInit();
	int Login();
	//�ʼ�����
	int SendMail();
	int SendMailAll();
	//���ӹرպ���
	int SMTPQuit();

	static SMTPSocket*  __Inter;
	static SMTPSocket* getInterface();
	~SMTPSocket();

private:
	string ipAddress;
	int port;

	string Base64Uname;
	string username;
	string Base64Passwd;
	string Passwd;
	string from;
	string sendTo;
	string subject;
	string Msg;
	string HostName="root";
	
	unsigned long MsgSize = 0;
	vector<string> Tolist;
	int* MSocket;
	TCPSocket* S;
};
#endif

