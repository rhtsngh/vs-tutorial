# TcpComm: Tcp communication DLL built on VC+

## Usage
 - DLL includes `TcpSocket`(Tcp Client library) & `TcpServer`(Tcp Server Library).
 - `TcpSocket` supports methods:
    - `connectToHost()`: after initialize the TcpSocket object with Ip & Port, it is able to use this function.
    - `disconnectFromHost()`
    - `sendData(const char * data)`
    - `recvData()`: this function does a polling to obtain incoming message.(synchronoues method)
    - `isConnected()`: check whether the socket is still connected to server.
    - `setMessageCallback(&FUNCTION)`: to obtain the incoming message by asynchronous way. Whenever it receives a message, your `FUNCTION` is triggered. The returned message from TcpSocket object(input of `FUNCTION`) follow the struct `messageStruct`.
    - `setErrorCallback(&FUNCTION)`: is similar to `setMessageCallback`
 - `TcpServer` supports methods:
    - `sendData(const char * data)`, `recvData()`, `setMessageCallback(&FUNCTION)`, `setErrorCallback(&FUNCTION)` are similar to the ones of `TcpSocket`.
    - `waitForConnected()`: this function does a polling to obtain one connection.

**Using samples**:
 - [Server](../ServerApplication)
 - [Client](../ClientApplication)

## Used techniques/libraries:
 - VC+ Winsock2 library
 - thread + callback
 - dll exporting for C#

## Future works:
 - make asynchronoeus accept-connection for TcpServer
 - make multi-connection for TcpServer
 - implement design patterns: `Pimpl` & `Singleton`



