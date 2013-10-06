#include <WINSOCK2.H>
#include <stdio.h>

int main(void)
{
	// 加载socket库
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
	
	SOCKET sockClient = socket(AF_INET, SOCK_DGRAM, 0);

	sockaddr_in addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); // 将点分十进制的字符串转换为U_long类型
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	char recvBuf[100];
	char sendBuf[100];
	char tempBuf[200];

	int len = sizeof(SOCKADDR);

	while(1)
	{
		printf("Please input data:\n");
		gets(sendBuf);
		sendto(sockClient, sendBuf, strlen(sendBuf) + 1, 0, (SOCKADDR*)&addrSrv, len);
		
		recvfrom(sockClient, recvBuf, 100, 0, (SOCKADDR*)&addrSrv, &len);

		if('q' == recvBuf[0])
		{
			sendto(sockClient, "q", strlen("q") + 1, 0, (SOCKADDR*)&addrSrv, len);
			printf("Chat end!\n");
			break;
		}
		sprintf(tempBuf, "Server%s say:%s", inet_ntoa(addrSrv.sin_addr), recvBuf); // 将地址转换为点分十进制表示的字符串
		printf("%s\n", tempBuf);
	}
	closesocket(sockClient);
	WSACleanup();

	return 0;
}