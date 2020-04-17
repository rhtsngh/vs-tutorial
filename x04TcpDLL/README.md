# TcpDLL
> Simple TcpServer & TcpClient DLLs.

## Sub-projects:
 - [TcpClasses](./TcpClasses): bases on [x02TcpServerClient](../x02TcpServerClient), cuts the sample programme into functions and gather into a class.
 - [TcpServer](./TcpServer) & [TcpClient](./TcpClient): bases on [TcpClasses](./TcpClasses), export class methods to DLL APIs through a bridge layer.
 - [ServerApplication](./ServerApplication) & [ClientApplication](./ClientApplication): Applications that loading created DLLs to test communication.

## How to export DLL:
 - These DLLs are exported for C#. Therefore, it is recommended to be exported through a bridge(use a pair .h/.c for each lib class) follow this instruction [如何在C#中使用C++ Class DLL](http://johnniebooks.blogspot.com/2010/11/cc-class-dll.html)

## Refer QTcpServer & QTcpSocket:

### [QTcpServer](https://doc.qt.io/qt-5/qtcpserver.html) [QTcpServer use](https://www.bogotobogo.com/Qt/Qt5_QTcpServer_Client_Server.php):
 - listen
 - close
 - nextPendingConnection
 - isListening

### [QTcpSocket](https://doc.qt.io/qt-5/qtcpsocket.html) [QTcpSocket use](https://www.bogotobogo.com/Qt/Qt5_QTcpSocket.php):
 - connectToHost
 - disconnectFromHost
 - write
 - readAll
 - close
 - waitForConnected
 - waitForDisconnected
 - waitForBytesWritten
 - waitForReadyRead
 - bytesAvailable

### SIGNALs:
 - connected
 - disconnected
 - error
 - stateChanged

## Potential reference source to build Async Tcp + Callback:
 - [OmarAflak/Asynchronous-Socket-Class-C-Windows](https://github.com/OmarAflak/Asynchronous-Socket-Class-C-Windows)
 - [Asynchronous Multicast Callbacks with Inter-Thread Messaging](https://www.codeproject.com/Articles/1092727/Asynchronous-Multicast-Callbacks-with-Inter-Thread)

## Potential reference source to build Multiple Connections/Clients:
 - [TCP Winsock: accept multiple connections/clients](https://stackoverflow.com/questions/15185380/tcp-winsock-accept-multiple-connections-clients)