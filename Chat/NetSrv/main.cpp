#include <WINSOCK2.H>
#include <stdio.h>

int main(void)
{
	// º”‘ÿsocketø‚
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	
	wVersionRequested = MAKEWORD( 1, 1 );
	
	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 )
	{
		return 0;
	}
	if ( LOBYTE( wsaData.wVersion ) != 1 ||
        HIBYTE( wsaData.wVersion ) != 1 ) 
	{
		WSACleanup( );
		return 0; 
	}
	SOCKET sockSrv = socket(AF_INET, SOCK_DGRAM, 0);

	sockaddr_in addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(ADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	char recvBuf[100];
	char sendBuf[100];
	char tempBuf[200];

	SOCKADDR_IN addrClient;
	int len = sizeof(SOCKADDR);

	while(1)
	{
		recvfrom(sockSrv, recvBuf, 100, 0, (SOCKADDR*)&addrClient, &len);
		if('q' == recvBuf[0])
		{
			sendto(sockSrv, "q", strlen("q") + 1, 0, (SOCKADDR*)&addrClient, len);
			printf("Chat end!\n");
			break;
		}
		sprintf(tempBuf, "Client%s say:%s", inet_ntoa(addrClient.sin_addr), recvBuf);
		printf("%s\n", tempBuf);
		printf("Please input data:\n");
		gets(sendBuf);
		sendto(sockSrv, sendBuf, strlen(sendBuf) + 1, 0, (SOCKADDR*)&addrClient, len);
	}
	closesocket(sockSrv);
	WSACleanup();

	return 0;
}