#include "TcpServer.h"

#pragma comment(lib, "Ws2_32.lib")
#pragma warning(disable:4996)

TcpServer::TcpServer(const char* ip, int port) : tcpClient()
{
	this->ip = ip;
	this->port = port;
	initSocket();
}
TcpServer::~TcpServer()
{
	close();
}
void TcpServer::initSocket()
{
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("1. WSAStartup failed: %d\n", iResult);
	}
	printf("1. WSAStartup successed.\n");

	this->tcpServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (tcpServer == INVALID_SOCKET) {
		printf("2. establish server failed: %d\n", WSAGetLastError());
		WSACleanup();
		return;
	}
	printf("2. establish server successed.\n");

	this->addr.sin_family = AF_INET;
	this->addr.sin_addr.s_addr = inet_addr(ip.c_str());
	this->addr.sin_port = htons(port);
	iResult = bind(tcpServer, (SOCKADDR*)&addr, sizeof(addr));
	if (iResult == SOCKET_ERROR) {
		printf("3.a. bind failed: %d\n", WSAGetLastError());
		WSACleanup();
		return;
	}
	printf("3.a. bind successed.\n");
}
void TcpServer::waitForConnected()
{
	if (listen(tcpServer, SOMAXCONN) == SOCKET_ERROR) {
		printf("3.b. listen failed: %d\n", WSAGetLastError());
		WSACleanup();
		return;
	}
	else printf("3.b. listen successed.\n");

	SOCKET acceptedSocket;
	acceptedSocket = accept(tcpServer, NULL, NULL);
	if (acceptedSocket == INVALID_SOCKET) {
		printf("3.c. accept failed: %d\n", WSAGetLastError());
		WSACleanup();
		return;
	}
	printf("3.c. accept successed.\n");

	tcpClient.setSocket(acceptedSocket);
}
void TcpServer::close()
{
	if (tcpClient.isConnected()) tcpClient.disconnectFromHost();
	closesocket(tcpServer);
	WSACleanup();
	printf("Server is closed.\n");
}
void TcpServer::sendData(const char* data)
{
	tcpClient.sendData(data);
}
char* TcpServer::recvData()
{
	return (char*)tcpClient.recvData();
}

void TcpServer::setMessageCallback(void (*callback_function)(messageStruct*))
{
	tcpClient.setMessageCallback(callback_function);
}
void TcpServer::removeMessageCallback()
{
	tcpClient.removeMessageCallback();
}
void TcpServer::setErrorCallback(void (*callback_function)(errorStruct*))
{
	tcpClient.setErrorCallback(callback_function);
}
void TcpServer::removeErrorCallback()
{
	tcpClient.removeErrorCallback();
}