#pragma once

#include "TcpClient.h"

#ifdef __cplusplus
extern "C" {
#endif

namespace Client {
	extern API TcpClient* CreateInstance();
	extern API void DisposeInstance(TcpClient* pClientInstance);
	extern API void CreateSocket(TcpClient* pClientInstance);
	extern API void ConnectServer(TcpClient* pClientInstance, const char* address, WORD port);
	extern API void SendData(TcpClient* pClientInstance, const char* data);
	extern API char* RecvData(TcpClient* pClientInstance);
}

#ifdef __cplusplus
}
#endif
