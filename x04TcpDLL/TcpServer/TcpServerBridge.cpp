#include "pch.h"
#include "TcpServerBridge.h"

extern "C" APIENTRY TcpServer * Server::CreateInstance()
{
    return new TcpServer();
}

extern "C" APIENTRY void Server::DisposeInstance(TcpServer * pServerInstance)
{
    if (pServerInstance != NULL)
    {
        delete pServerInstance;
        pServerInstance = NULL;
    }
}

extern "C" APIENTRY void Server::CreateSocket(TcpServer * pServerInstance)
{
    pServerInstance->createSocket();
}
extern "C" APIENTRY void Server::BindSocket(TcpServer * pServerInstance, const char* address, WORD port)
{
    pServerInstance->bindSocket(address, port);
}
extern "C" APIENTRY void Server::ListenSocket(TcpServer * pServerInstance)
{
    pServerInstance->listenSocket();
}
extern "C" APIENTRY void Server::AcceptConnection(TcpServer * pServerInstance)
{
    pServerInstance->acceptConnection();
}
extern "C" APIENTRY void Server::SendData(TcpServer * pServerInstance, const char* data)
{
    pServerInstance->sendData(data);
}
extern "C" APIENTRY char* Server::RecvData(TcpServer * pServerInstance)
{
    return pServerInstance->recvData();
}