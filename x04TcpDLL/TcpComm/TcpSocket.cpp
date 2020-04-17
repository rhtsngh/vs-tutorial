#include "pch.h"
#include "TcpSocket.h"
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")
#pragma warning(disable:4996)

TcpSocket::TcpSocket(const char * ip, int port)
{
	this->ip = ip;
	this->port = port;
	this->connected = false;
	initParameters();
	initSocket();
}

TcpSocket::TcpSocket()
{
	connected = false;
	tcpSocket = INVALID_SOCKET;
	initParameters();
}

void TcpSocket::setSocket(const SOCKET& establishedSocket)
{
	tcpSocket = establishedSocket;
	connected = true;
	initParameters();
}

TcpSocket::~TcpSocket()
{
	if (connected) disconnectFromHost();
}

void TcpSocket::initParameters()
{
	memset(buffer, 0, sizeof(buffer));

	callback = NULL;
	thread = NULL;
	thread_started = false;

	callbackError = NULL;
	errorWhileReceiving = false;
	errorWhileSending = false;
}

void TcpSocket::initSocket()
{
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("1. WSAStartup failed: %d\n", iResult);
	}
	printf("1. WSAStartup successed.\n");

	tcpSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (tcpSocket == INVALID_SOCKET) {
		printf("2. establish socket failed: %d\n", WSAGetLastError());
		WSACleanup();
		return;
	}
	printf("2. establish socket successed.\n");

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	//InetPtonW(AF_INET, (PCWSTR)ip.c_str(), &addr.sin_addr.s_addr);
	addr.sin_addr.s_addr = inet_addr(ip.c_str());
}

int TcpSocket::connectToHost()
{
	int iResult = connect(tcpSocket, (SOCKADDR*)&addr, sizeof(addr));
	if (iResult == SOCKET_ERROR) {
		if (callbackError != NULL) {
			errorStruct error(WSAGetLastError(), "Error while connecting.");
			callbackError(&error);
		}
		else printf("3. connect failed: %d\n", WSAGetLastError());
		tcpSocket = INVALID_SOCKET;
	}
	else {
		connected = true;
		printf("3. socket connect successed.\n");
	}

	return iResult;
}

void TcpSocket::disconnectFromHost()
{
	if (thread_started) removeMessageCallback();
	removeErrorCallback();
	closesocket(tcpSocket);
	WSACleanup();
	connected = false;
	printf("Socket is disconnected.\n");
}

void TcpSocket::sendData(const char* data)
{
	int iResult = send(tcpSocket, data, (int)strlen(data), 0);
	if (isSendingFailed(iResult)) return;
	printf("4.a. send successed: %d\n", iResult);
}

char* TcpSocket::recvData()
{
	int iResult;

	iResult = recv(tcpSocket, buffer, DEFAULT_BUFLEN, 0);
	if (isReceivingFailed(iResult)) return NULL;

	return buffer;
}


void TcpSocket::setMessageCallback(void (*callback_function)(messageStruct*))
{
	callback = callback_function;
	thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)messageThread, this, 0, 0);
	thread_started = true;
}

void TcpSocket::removeMessageCallback()
{
	CloseHandle(thread);
	callback = NULL;
	thread_started = false;
}

void TcpSocket::startThread()
{
	while (1) {
		if (connected) {
			char* data = recvData();

			if (!errorWhileReceiving)
			{
				messageStruct message(buffer);
				callback(&message);
			}
		}
	}
}


void TcpSocket::setErrorCallback(void (*callback_function)(errorStruct*))
{
	callbackError = callback_function;
}

void TcpSocket::removeErrorCallback()
{
	callbackError = NULL;
}

bool TcpSocket::isReceivingFailed(int result)
{
	if (result == 0 || result < 0)
	{
		if (callbackError != NULL)
		{
			errorStruct error(WSAGetLastError(), "Error while receiving.");
			callbackError(&error);
		}
		else printf("4.c. recv failed: %d\n", WSAGetLastError());
		connected = false; //Q: What should we do after connected=false?
		errorWhileReceiving = true;
		return true;
	}
	return false;
}

bool TcpSocket::isSendingFailed(int result)
{
	if (result == SOCKET_ERROR)
	{
		if (callbackError != NULL)
		{
			errorStruct error(WSAGetLastError(), "Error while sending.");
			callbackError(&error);
		}
		else printf("4.a. send failed: %d\n", WSAGetLastError());
		connected = false;
		errorWhileSending = true;
		return true;
	}
	return false;
}

bool TcpSocket::isConnected()
{
	return connected;
}