#include "pch.h"
#include "TcpClientBridge.h"

extern "C" API TcpClient * Client::CreateInstance()
{
    return new TcpClient();
}

extern "C" API void Client::DisposeInstance(TcpClient * pClientInstance)
{
    if (pClientInstance != NULL)
    {
        delete pClientInstance;
        pClientInstance = NULL;
    }
}

extern "C" API void Client::CreateSocket(TcpClient * pClientInstance)
{
    pClientInstance->createSocket();
}
extern "C" API void Client::ConnectServer(TcpClient * pClientInstance, const char* address, WORD port)
{
    pClientInstance->connectServer(address, port);
}
extern "C" API void Client::SendData(TcpClient * pClientInstance, const char* data)
{
    pClientInstance->sendData(data);
}
extern "C" API char* Client::RecvData(TcpClient * pClientInstance)
{
    return pClientInstance->recvData();
}