#pragma once
#include <iostream>
#include <WinSock2.h>
#include "Header.h"

#define DEFAULT_BUFLEN 1024

class API TcpClient
{
public:
	TcpClient();
	~TcpClient();

	void createSocket();
	void connectServer(const char* address, WORD port);
	void sendData(const char* data);
	char* recvData();

private:
	WSADATA m_wsaData;
	WORD m_sockVersion;
	SOCKET m_connectSocket;
	sockaddr_in m_addr;
	WORD m_port;
	char m_recvBuf[DEFAULT_BUFLEN];
	char m_sendBuf[DEFAULT_BUFLEN];
};

