#define _WINSOCK_DEPRECATED_NO_WARNINGS  
#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib") 
#define PORT 8080
int main()
{
    WSADATA wsa;
    SOCKET sockfd;
    struct sockaddr_in server_addr, client_addr;
    int client_len = sizeof(client_addr);
    char buffer[1024];
    WSAStartup(MAKEWORD(2, 2), &wsa);
    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    bind(sockfd ,(struct  sockaddr*)&server_addr ,sizeof(server_addr));
    printf("UDP server listening on port:%d\n", PORT);
    while(1)
    {
        int rcv = recvfrom(sockfd , buffer , sizeof(buffer) -1, 0 , (struct sockaddr*)&client_addr , &client_len ) ;
        if ( rcv> 0 )
        {
            buffer[rcv]  = '\0';
            printf("recieved:%s\n" , buffer);
            sendto(sockfd, "Hello from UDP server", 23, 0,
            (struct sockaddr*)&client_addr, client_len);
        }
    }
    closesocket(sockfd);
    WSACleanup();
    return 0;
}