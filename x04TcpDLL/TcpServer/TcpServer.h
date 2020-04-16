#pragma once

#include <iostream>
#include <WinSock2.h>
#include "Header.h"

#define DEFAULT_BUFLEN 1024

	class APIENTRY TcpServer
	{
	public:
		TcpServer();
		~TcpServer();

		void createSocket();
		void bindSocket(const char* address, WORD port);
		void listenSocket();
		void acceptConnection();
		void sendData(const char* data);
		char* recvData();

	private:
		WSADATA m_wsaData;
		WORD m_sockVersion;
		SOCKET m_listenSocket;
		SOCKET m_clientSocket;
		sockaddr_in m_addr;
		WORD m_port;
		char m_recvBuf[DEFAULT_BUFLEN];
		char m_sendBuf[DEFAULT_BUFLEN];
	};


