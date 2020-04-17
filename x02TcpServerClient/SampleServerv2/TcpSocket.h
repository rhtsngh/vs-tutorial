#pragma once

#include <iostream>
#include <WinSock2.h>

#define DEFAULT_BUFLEN 1024

struct messageStruct;
struct errorStruct;

class TcpSocket
{
public:
	TcpSocket(const char * ip, int port);
	TcpSocket() {};
	~TcpSocket();

	int connectToHost();
	void disconnectFromHost();
	void sendData(const char * data);
	char * recvData();
	bool isConnected();
	void setSocket(const SOCKET& establishedSocket);

	void setMessageCallback(void (*callback_function)(messageStruct*));
	void removeMessageCallback();
	void setErrorCallback(void (*callback_function)(errorStruct*));
	void removeErrorCallback();

private:
	std::string ip;
	int port;
	WSADATA wsaData;
	SOCKET tcpSocket;
	sockaddr_in addr;
	char buffer[DEFAULT_BUFLEN];
	bool connected;

	void initParameters();
	void initSocket();

	void (*callback)(messageStruct*);
	HANDLE thread;
	bool thread_started;
	void startThread();

	static DWORD messageThread(LPVOID param) {
		TcpSocket* client = (TcpSocket*)param;
		client->startThread();
		return 0;
	}

	bool errorWhileReceiving;
	bool errorWhileSending;
	void (*callbackError)(errorStruct*);
	bool isReceivingFailed(int result);
	bool isSendingFailed(int result);
};

struct messageStruct
{
	std::string message;
	messageStruct(std::string message) : message(message) {}
};

struct errorStruct
{
	int code;
	std::string message;
	errorStruct(int code, std::string message) : code(code), message(message) {}
};


