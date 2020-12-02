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
	void setIpAddress(std::string ip);
	void setPort(int port);
	void setHostName(std::string hostname);
	//�û�������������
	void setUserPasswd
	(
		_In_ std::string user,
		_In_ std::string passwd
	);
	void setFromandTo
	(
		_In_ std::string from,
		_In_ std::string sendto
	);
	void setSubjectandMsg
	(
		_In_ std::string subject,
		_In_ std::string Msg,
		_In_ unsigned MsgSize
	);
	void addRcpto(std::string rcpto);
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
	std::string ipAddress;
	int port;

	std::string Base64Uname;
	std::string username;
	std::string Base64Passwd;
	std::string Passwd;
	std::string from;
	std::string sendTo;
	std::string subject;
	std::string Msg;
	std::string HostName="root";

	unsigned long MsgSize = 0;
	std::vector<std::string> Tolist;
	int* MSocket;
	TCPSocket* S;
};
#endif
