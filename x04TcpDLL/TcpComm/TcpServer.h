#pragma once

#include "TcpSocket.h"

class TcpServer
{
public:
	TcpServer(const char* ip, int port);
	~TcpServer();
	void waitForConnected();
	void close();
	void sendData(const char* data);
	std::string recvData();

	// these functions mustbe after connection established
	void setMessageCallback(void (*callback_function)(messageStruct*));
	void removeMessageCallback();
	void setErrorCallback(void (*callback_function)(errorStruct*));
	void removeErrorCallback();

private:
	std::string ip;
	int port;
	WSADATA wsaData;
	SOCKET tcpServer;
	sockaddr_in addr;
	TcpSocket tcpClient;

	void initSocket();

};

