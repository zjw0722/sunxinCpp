#include <WINSOCK2.H>
#include <stdio.h>

void main()
{
	// º”‘ÿsocketø‚
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
	// load lib success
	
	// build socket
	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);
	// connect to server
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	char recvBuf[255];
	recv(sockClient, recvBuf, 255, 0);
	printf("server:%s\n", recvBuf);
	send(sockClient, "This is zhang san.", strlen("This is zhang san.") + 1, 0);

	closesocket(sockClient);
	WSACleanup();
}