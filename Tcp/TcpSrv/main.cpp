#include <WINSOCK2.H>
#include <stdio.h>

void main()
{
	// 加载socket库
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	
	wVersionRequested = MAKEWORD( 1, 1 );
	
	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 )
	{
		return;
	}
	if ( LOBYTE( wsaData.wVersion ) != 1 ||
        HIBYTE( wsaData.wVersion ) != 1 ) 
	{
		WSACleanup( );
		return; 
	}
	/* The WinSock DLL is acceptable. Proceed. */
	// 建立套接字
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY); // htol 转换为网络字节序
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000); // 转换U_shot成网络字节序
	// 绑定ip地址和端口到socket
	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
    // 监听，
	listen(sockSrv, 5);
	// 进入死循环
	printf("Server has been started.\n");
	// 记录客户端的地址字信息
	SOCKADDR_IN addrClient;
	// 套接字的长度
	int len = sizeof(SOCKADDR);
	
	while(1)
	{
		// 等待接收客户的连接进入
		SOCKET sockConn = accept(sockSrv, (SOCKADDR*)&addrClient, &len);
		char sendBuf[255];
		sprintf(sendBuf, "Welcome %s to www.sunxin.org", 
			inet_ntoa(addrClient.sin_addr));
		send(sockConn, sendBuf, strlen(sendBuf)+1, 0);
		char recvBuf[255];
		recv(sockConn, recvBuf, 255, 0);
		printf("%s\n", recvBuf);
		// close the connected socket
		closesocket(sockConn);
	}
	// clean socket lib to release the resource
	WSACleanup();
}