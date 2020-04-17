#pragma once

#include "DllExportImport.h"
#include "TcpSocket.h"

#ifdef __cplusplus
extern "C" {
#endif

	extern API TcpSocket* ClientCreateInstance(const char* ip, int port);
	extern API void ClientDisposeInstance(TcpSocket* pClientInstance);

	extern API void ClientConnectToHost(TcpSocket* pClientInstance);
	extern API void ClientDisconnectFromHost(TcpSocket* pClientInstance);
	extern API void ClientSendData(TcpSocket* pClientInstance, const char* data);
	extern API char* ClientRecvData(TcpSocket* pClientInstance);

	extern API bool ClientIsConnected(TcpSocket* pClientInstance);
	extern API void ClientSetMessageCallback(TcpSocket* pClientInstance, void (*callback_function)(messageStruct*));
	extern API void ClientRemoveMessageCallback(TcpSocket* pClientInstance);
	extern API void ClientSetErrorCallback(TcpSocket* pClientInstance, void (*callback_function)(errorStruct*));
	extern API void ClientRemoveErrorCallback(TcpSocket* pClientInstance);

#ifdef __cplusplus
}
#endif

