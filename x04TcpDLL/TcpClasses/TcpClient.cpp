#include "TcpClient.h"

#pragma comment(lib, "Ws2_32.lib")
#pragma warning(disable:4996)

TcpClient::TcpClient()
{
	//1. Initial Winsock
	int iResult;
	iResult = WSAStartup(m_sockVersion, &m_wsaData);//initiate use of WS2_32.dll
	if (iResult != 0) {
		printf("1. WSAStartup failed: %d\n", iResult);
	}
	printf("1. WSAStartup successed.\n");

	m_sockVersion = MAKEWORD(2, 2);
	m_connectSocket = NULL;
	m_addr = {};
	memset(m_recvBuf, 0, sizeof(m_recvBuf));
	memset(m_sendBuf, 0, sizeof(m_sendBuf));
}

TcpClient::~TcpClient()
{
	closesocket(m_connectSocket);
}

void TcpClient::createSocket()
{
	//TODO: consider input argument

	//2. Create a socket
	m_connectSocket = INVALID_SOCKET;
	m_connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_connectSocket == INVALID_SOCKET) {
		printf("2. Error at socket(): %ld\n", WSAGetLastError());
		WSACleanup();
		return;
	}
	printf("2. socket successed.\n");
}

void TcpClient::connectServer(const char* address, WORD port)
{
	//3. Connect to a Server
	m_addr.sin_family = AF_INET;
	m_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	m_addr.sin_port = htons(27016);
	int iResult = connect(m_connectSocket, (SOCKADDR*)&m_addr, sizeof(m_addr));
	if (iResult == SOCKET_ERROR) {
		closesocket(m_connectSocket);
		m_connectSocket = INVALID_SOCKET;
	}
	if (m_connectSocket == INVALID_SOCKET) {
		printf("3. connect failed: %d\n", WSAGetLastError());
		WSACleanup();
		return;
	}
	printf("3. connect successed.\n");
}

void TcpClient::sendData(const char* data)
{
	int iResult;

	iResult = send(m_connectSocket, data, (int)strlen(data), 0);
	if (iResult == SOCKET_ERROR) {
		printf("4. send failed: %d\n", WSAGetLastError());
		closesocket(m_connectSocket);
		WSACleanup();
		return;
	}
	printf("4.a. send successed: %d\n", iResult);

	iResult = shutdown(m_connectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("4.b. shutdown sending failed: %d\n", WSAGetLastError());
		closesocket(m_connectSocket);
		WSACleanup();
		return;
	}
	printf("4.b. shutdown sending successed.\n");
}
char* TcpClient::recvData()
{
	int iResult;

	do {
		iResult = recv(m_connectSocket, m_recvBuf, DEFAULT_BUFLEN, 0);
		if (iResult > 0) {
			printf("4.a. Bytes received: %d\n", iResult);
		}
		else if (iResult == 0) printf("4.a. Connection closing...\n");
		else {
			printf("4.a. recv failed: %d\n", WSAGetLastError());
			closesocket(m_connectSocket);
			WSACleanup();
			return (char*)"";
		}
	} while (iResult > 0);

	return m_recvBuf;
}