#pragma once

#include "DllExportImport.h"
#include "TcpServer.h"

#ifdef __cplusplus
extern "C" {
#endif

	extern API TcpServer* ServerCreateInstance(const char* ip, int port);
	extern API void ServerDisposeInstance(TcpServer* pServerInstance);

	extern API void ServerWaitForConnected(TcpServer* pServerInstance);
	extern API void ServerClose(TcpServer* pServerInstance);
	extern API void ServerSendData(TcpServer* pServerInstance, const char* data);
	extern API std::string ServerRecvData(TcpServer* pServerInstance);

	extern API void ServerSetMessageCallback(TcpServer* pServerInstance, void (*callback_function)(messageStruct*));
	extern API void ServerRemoveMessageCallback(TcpServer* pServerInstance);
	extern API void ServerSetErrorCallback(TcpServer* pServerInstance, void (*callback_function)(errorStruct*));
	extern API void ServerRemoveErrorCallback(TcpServer* pServerInstance);

#ifdef __cplusplus
}
#endif

