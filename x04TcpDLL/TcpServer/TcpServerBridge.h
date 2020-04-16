#pragma once

#include "TcpServer.h"


#ifdef __cplusplus
extern "C" {
#endif

namespace Server {
	extern APIENTRY TcpServer* CreateInstance();
	extern APIENTRY void DisposeInstance(TcpServer* pServerInstance);
	extern APIENTRY void CreateSocket(TcpServer* pServerInstance);
	extern APIENTRY void BindSocket(TcpServer* pServerInstance, const char* address, WORD port);
	extern APIENTRY void ListenSocket(TcpServer* pServerInstance);
	extern APIENTRY void AcceptConnection(TcpServer* pServerInstance);
	extern APIENTRY void SendData(TcpServer* pServerInstance, const char* data);
	extern APIENTRY char* RecvData(TcpServer* pServerInstance);
}

#ifdef __cplusplus
}
#endif