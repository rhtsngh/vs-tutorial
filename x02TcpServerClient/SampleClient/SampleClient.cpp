// SampleClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Reference source: [connect function](https://docs.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-connect)

#include <iostream>
#include <stdio.h>
#include <WinSock2.h>
#include <WS2tcpip.h> //Q: What is this lib used for?

#pragma comment(lib, "Ws2_32.lib")
#pragma warning(disable:4996)
#define DEFAULT_PORT "27015"
#define DEFAULT_BUFLEN 512

int main(int argc, char** argv)
{
    std::cout << "Hello World! This is Client.\n";

	//1. Initial Winsock
	WSADATA wsaData;
	WORD sockVersion = MAKEWORD(2, 2);
	int iResult;
	iResult = WSAStartup(sockVersion, &wsaData);
	if (iResult != 0) {
		printf("1. WSAStartup failed: %d\n", iResult);
		return 1;
	}
	printf("1. WSAStartup successed.\n", iResult);

	//2. Create a socket
	SOCKET ConnectSocket = INVALID_SOCKET;
	ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ConnectSocket == INVALID_SOCKET) {
		printf("2.b. Error at socket(): %ld\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	printf("2.b. socket successed.\n", iResult);

	//3. Connect to a Server
	sockaddr_in clientService;
	clientService.sin_family = AF_INET;
	clientService.sin_addr.s_addr = inet_addr("127.0.0.1");
	clientService.sin_port = htons(27015);
	iResult = connect(ConnectSocket, (SOCKADDR*)&clientService, sizeof(clientService));
	if (iResult == SOCKET_ERROR) {
		closesocket(ConnectSocket);
		ConnectSocket = INVALID_SOCKET;
	}
	if (ConnectSocket == INVALID_SOCKET) {
		printf("3. connect failed: %d\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	printf("3. connect successed.\n");

	//4. Send/Receive data
	const char* sendbuf = "this is a test message";
	char recvbuf[DEFAULT_BUFLEN];
	iResult = send(ConnectSocket, sendbuf, (int)strlen(sendbuf), 0);
	if (iResult == SOCKET_ERROR) {
		printf("4. send failed: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}
	printf("4.a. send successed: %d\n", iResult);

	iResult = shutdown(ConnectSocket, SD_SEND);
	if (iResult == SOCKET_ERROR) {
		printf("4.b. shutdown sending failed: %d\n", WSAGetLastError());
		closesocket(ConnectSocket);
		WSACleanup();
		return 1;
	}
	printf("4.b. shutdown sending successed.\n");

	do {
		iResult = recv(ConnectSocket, recvbuf, DEFAULT_BUFLEN, 0);
		if (iResult > 0) printf("4.c. Bytes received: %d\n", iResult);
		else if (iResult == 0) printf("4.c. Connection closed\n");
		else printf("4.c. recv failed: %d\n", WSAGetLastError());
	} while (iResult > 0);

	//5. Disconnect
	closesocket(ConnectSocket);
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
