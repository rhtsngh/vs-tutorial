#include "pch.h"
#include "TcpSocketBridge.h"

//=========================================================
// TcpSocket APIs
//=========================================================
extern "C" API TcpSocket * ClientCreateInstance(const char* ip, int port)
{
    return new TcpSocket(ip, port);
}

extern "C" API void ClientDisposeInstance(TcpSocket * pClientInstance)
{
    if (pClientInstance != NULL)
    {
        delete pClientInstance;
        pClientInstance = NULL;
    }
}

extern "C" API void ClientConnectToHost(TcpSocket * pClientInstance)
{
    pClientInstance->connectToHost();
}

extern "C" API void ClientDisconnectFromHost(TcpSocket * pClientInstance)
{
    pClientInstance->disconnectFromHost();
}

extern "C" API void ClientSendData(TcpSocket * pClientInstance, const char* data)
{
    pClientInstance->sendData(data);
}

extern "C" API std::string ClientRecvData(TcpSocket * pClientInstance)
{
    return pClientInstance->recvData();
}


extern "C" API bool ClientIsConnected(TcpSocket * pClientInstance)
{
    return pClientInstance->isConnected();
}

extern "C" API void ClientSetMessageCallback(TcpSocket * pClientInstance, void (*callback_function)(messageStruct*))
{
    return pClientInstance->setMessageCallback(callback_function);
}

extern "C" API void ClientRemoveMessageCallback(TcpSocket * pClientInstance)
{
    return pClientInstance->removeMessageCallback();
}

extern "C" API void ClientSetErrorCallback(TcpSocket * pClientInstance, void (*callback_function)(errorStruct*))
{
    return pClientInstance->setErrorCallback(callback_function);
}

extern "C" API void ClientRemoveErrorCallback(TcpSocket * pClientInstance)
{
    return pClientInstance->removeErrorCallback();
}




