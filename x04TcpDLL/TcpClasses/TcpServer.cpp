#include "TcpServer.h"

#pragma comment(lib, "Ws2_32.lib")
#pragma warning(disable:4996)

TcpServer::TcpServer()
{
	//1. Initial Winsock
	int iResult;
	iResult = WSAStartup(m_sockVersion, &m_wsaData);//initiate use of WS2_32.dll
	if (iResult != 0) {
		printf("1. WSAStartup failed: %d\n", iResult);
	}
	printf("1. WSAStartup successed.\n");

	m_sockVersion = MAKEWORD(2, 2);
	m_listenSocket = NULL;
	m_clientSocket = NULL;
	m_addr = {};
	memset(m_recvBuf, 0, sizeof(m_recvBuf));
	memset(m_sendBuf, 0, sizeof(m_sendBuf));
}

TcpServer::~TcpServer()
{
	closesocket(m_listenSocket);
	closesocket(m_clientSocket);
}

void TcpServer::createSocket()
{
	//TODO: consider input argument

	//2. Create a socket
	m_listenSocket = INVALID_SOCKET;
	m_listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_listenSocket == INVALID_SOCKET) {
		printf("2. Error at socket(): %ld\n", WSAGetLastError());
		WSACleanup();
		return;
	}
	printf("2. socket successed.\n");
}
void TcpServer::bindSocket(const char* address, WORD port)
{
	//3.a. Bind the socket
	m_addr.sin_family = AF_INET;
	m_addr.sin_addr.s_addr = inet_addr(address);
	m_addr.sin_port = htons(port);
	int iResult = bind(m_listenSocket, (SOCKADDR*)&m_addr, sizeof(m_addr));
	if (iResult == SOCKET_ERROR) {
		printf("3.a. bind failed: %d\n", WSAGetLastError());
		WSACleanup();
		return;
	}
	printf("3.a. bind successed.\n");
}
void TcpServer::listenSocket()
{
	//3.b. Listen on the socket
	if (listen(m_listenSocket, SOMAXCONN) == SOCKET_ERROR) {
		printf("3.b. listen failed: %d\n", WSAGetLastError());
		closesocket(m_listenSocket);
		return;
	}
	printf("3.b. listen successed.\n");
}
void TcpServer::acceptConnection()
{
	//3.c. Accept a connection
	m_clientSocket = INVALID_SOCKET;
	m_clientSocket = accept(m_listenSocket, NULL, NULL);
	if (m_clientSocket == INVALID_SOCKET) {
		printf("3.c. accept failed: %d\n", WSAGetLastError());
		closesocket(m_listenSocket);
		WSACleanup();
		return;
	}
	printf("3.c. accept successed.\n");
}
void TcpServer::sendData(const char * data)
{
	int iResult;

	iResult = send(m_clientSocket, data, (int)strlen(data), 0);
	if (iResult == SOCKET_ERROR) {
		printf("4. send failed: %d\n", WSAGetLastError());
		closesocket(m_clientSocket);
		WSACleanup();
		return;
	}
	printf("4.a. send successed: %d\n", iResult);

	//iResult = shutdown(m_clientSocket, SD_SEND);
	//if (iResult == SOCKET_ERROR) {
	//	printf("4.b. shutdown sending failed: %d\n", WSAGetLastError());
	//	closesocket(m_clientSocket);
	//	WSACleanup();
	//	return;
	//}
	//printf("4.b. shutdown sending successed.\n");
}
char* TcpServer::recvData()
{
	int iResult;

	do {
		iResult = recv(m_clientSocket, m_recvBuf, DEFAULT_BUFLEN, 0);
		if (iResult > 0) {
			printf("4.a. Bytes received: %d\n", iResult);
		}
		else if (iResult == 0) printf("4.a. Connection closing...\n");
		else {
			printf("4.a. recv failed: %d\n", WSAGetLastError());
			closesocket(m_clientSocket);
			WSACleanup();
			return (char*)"";
		}
	} while (iResult > 0);

	return m_recvBuf;
}