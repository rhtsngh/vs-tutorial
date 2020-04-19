#include "pch.h"
#include "TcpServerBridge.h"

//=========================================================
// TcpServer APIs
//=========================================================
extern "C" API TcpServer * ServerCreateInstance(const char* ip, int port)
{
    return new TcpServer(ip, port);
}

extern "C" API void ServerDisposeInstance(TcpServer * pServerInstance)
{
    if (pServerInstance != NULL)
    {
        delete pServerInstance;
        pServerInstance = NULL;
    }
}

extern "C" API void ServerWaitForConnected(TcpServer * pServerInstance)
{
    pServerInstance->waitForConnected();
}

extern "C" API void ServerClose(TcpServer * pServerInstance)
{
    pServerInstance->close();
}

extern "C" API void ServerSendData(TcpServer * pServerInstance, const char* data)
{
    pServerInstance->sendData(data);
}

extern "C" API std::string ServerRecvData(TcpServer * pServerInstance)
{
    return pServerInstance->recvData();
}


extern "C" API void ServerSetMessageCallback(TcpServer * pServerInstance, void (*callback_function)(messageStruct*))
{
    return pServerInstance->setMessageCallback(callback_function);
}

extern "C" API void ServerRemoveMessageCallback(TcpServer * pServerInstance)
{
    return pServerInstance->removeMessageCallback();
}

extern "C" API void ServerSetErrorCallback(TcpServer * pServerInstance, void (*callback_function)(errorStruct*))
{
    return pServerInstance->setErrorCallback(callback_function);
}

extern "C" API void ServerRemoveErrorCallback(TcpServer * pServerInstance)
{
    return pServerInstance->removeErrorCallback();
}