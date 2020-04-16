# TcpDLL
> Simple TcpServer & TcpClient DLLs.

## Sub-projects:
 - [TcpClasses](./TcpClasses): bases on [x02TcpServerClient](../x02TcpServerClient), cuts the sample programme into functions and gather into a class.
 - [TcpServer](./TcpServer) & [TcpClient](./TcpClient): bases on [TcpClasses](./TcpClasses), export class methods to DLL APIs through a bridge layer.
 - [ServerApplication](./ServerApplication) & [ClientApplication](./ClientApplication): Applications that loading created DLLs to test communication.

## How to export DLL:
 - These DLLs are exported for C#. Therefore, it is recommended to be exported through a bridge(use a pair .h/.c for each lib class) follow this instruction [如何在C#中使用C++ Class DLL](http://johnniebooks.blogspot.com/2010/11/cc-class-dll.html)

