// SampleServer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Reference source: [accept function](https://docs.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-accept)
// referenced processes: [Getting Started with Winsock](https://docs.microsoft.com/en-us/windows/win32/winsock/getting-started-with-winsock)

#include <iostream>
#include <stdio.h>
#include <WinSock2.h>
#include <WS2tcpip.h> //Q: What is this lib used for?

#pragma comment(lib, "Ws2_32.lib")
#pragma warning(disable:4996)
//#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

int main(int argc, char* argv[])
{
	std::cout << "Hello World!\n";

	//1. Initial Winsock
	WSADATA wsaData;//contains information about the Windows Sockets implementation
	WORD sockVersion = MAKEWORD(2, 2);//version 2.2 of Winsock
	int iResult;
	iResult = WSAStartup(sockVersion, &wsaData);//initiate use of WS2_32.dll
	if (iResult != 0) {
		printf("1. WSAStartup failed: %d\n", iResult);
		return 1;
	}
	printf("1. WSAStartup successed.\n");

	//2. Create a socket
	SOCKET ListenSocket = INVALID_SOCKET;
	ListenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ListenSocket == INVALID_SOCKET) {
		printf("2.b. Error at socket(): %ld\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	printf("2.b. socket successed.\n");

	//3. Prepare to obtain Client connection
	//3.a. Bind the socket
	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr("127.0.0.1");
	service.sin_port = htons(27016);
	iResult = bind(ListenSocket, (SOCKADDR*)&service, sizeof(service));
	if (iResult == SOCKET_ERROR) {
		printf("3.a. bind failed: %d\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	printf("3.a. bind successed.\n");

	//3.b. Listen on the socket
	if (listen(ListenSocket, SOMAXCONN) == SOCKET_ERROR) {
		printf("3.b. listen failed: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}
	printf("3.b. listen successed.\n");

	//3.c. Accept a connection
	SOCKET ClientSocket;
	ClientSocket = INVALID_SOCKET;
	ClientSocket = accept(ListenSocket, NULL, NULL);
	if (ClientSocket == INVALID_SOCKET) {
		printf("3.c. accept failed: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
		return 1;
	}
	printf("3.c. accept successed.\n");

	//4. Send/Receive data
	char recvbuf[DEFAULT_BUFLEN];
	int iSendResult;
	do {
		iResult = recv(ClientSocket, recvbuf, DEFAULT_BUFLEN, 0);
		if (iResult > 0) {
			printf("4.a. Bytes received: %d\n", iResult);

			// Echo the buffer back to the sender
			iSendResult = send(ClientSocket, recvbuf, iResult, 0);
			if (iSendResult == SOCKET_ERROR) {
				printf("4.b. send failed: %d\n", WSAGetLastError());
				closesocket(ClientSocket);
				WSACleanup();
				return 1;
			}
			printf("4.b. Bytes sent: %d\n", iSendResult);

			iResult = shutdown(ClientSocket, SD_SEND);
			if (iResult == SOCKET_ERROR) {
				printf("4.c. shutdown sending failed: %d\n", WSAGetLastError());
				closesocket(ClientSocket);
				WSACleanup();
				return 1;
			}
			printf("4.c. shutdown sending successed.\n");
		}
		else if (iResult == 0) printf("4.a. Connection closing...\n");
		else {
			printf("4.a. recv failed: %d\n", WSAGetLastError());
			closesocket(ClientSocket);
			WSACleanup();
			return 1;
		}
	} while (iResult > 0);

	//5. Disconnect
	closesocket(ClientSocket);
	WSACleanup();
	printf("5. closesocket successed.\n");

	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
