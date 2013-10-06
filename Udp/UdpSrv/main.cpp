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
	// build socket
	SOCKET sockSrv = socket(AF_INET, SOCK_DGRAM, 0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);
	// bind ip address to the sockSrv;
	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	
	// receive data from client
	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR); // must be init
	char recvBuf[255];

	recvfrom(sockSrv, recvBuf, 255, 0, (SOCKADDR*)&addrClient, &len);
	printf("Client:%s\n", recvBuf);
	closesocket(sockSrv);
	WSACleanup();
	
}