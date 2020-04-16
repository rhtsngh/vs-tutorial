# TcpDLL
> Simple TcpServer & TcpClient DLLs.

## Sub-projects:
 - [TcpClasses](./TcpClasses): bases on [x02TcpServerClient](../x02TcpServerClient), cuts the sample programme into functions and gather into a class.
 - [TcpServer](./TcpServer) & [TcpClient](./TcpClient): bases on [TcpClasses](./TcpClasses), export class methods to DLL APIs through a bridge layer.
 - [ServerApplication](./ServerApplication) & [ClientApplication](./ClientApplication): Applications that loading created DLLs to test communication.


## Referenced structure for Library
[如何在C#中使用C++ Class DLL](http://johnniebooks.blogspot.com/2010/11/cc-class-dll.html)
