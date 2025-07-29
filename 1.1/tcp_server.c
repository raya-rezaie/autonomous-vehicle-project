#define _WINSOCK_DEPRECATED_NO_WARNINGS  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>   
#include <ws2tcpip.h>   
#pragma comment(lib, "ws2_32.lib") 
#define PORT 8080
int main(int argc , char const * argv[])
{

    WSADATA wsa;
    SOCKET server_fd , new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("WSAStartup failed");
        return 1;
    }
    if ((server_fd = socket(AF_INET , SOCK_STREAM,0)) == INVALID_SOCKET)
    {
        printf("socket failed:%d\n" , WSAGetLastError());
        WSACleanup();
        return 1; 
    } 
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if(bind(server_fd , (struct sockaddr *)&address , sizeof(address)) < 0)
    {
        printf("bind failed:%d\n" , WSAGetLastError());
        closesocket(server_fd);
        WSACleanup();
        return 1;        
    }
    listen(server_fd , 3);
    
    if ( listen(server_fd , 3) == SOCKET_ERROR)
    {
        printf("listen failed:%d\n" , WSAGetLastError());
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }
    printf("server listening on port:%d\n" , PORT);

    while (1) {
    new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen);
    if (new_socket == INVALID_SOCKET) {
        printf("accept failed: %d\n", WSAGetLastError());
        break;
    }

    printf("Connected with %s:%d\n",
        inet_ntoa(address.sin_addr),
        ntohs(address.sin_port));

    int valread;
    do {
        valread = recv(new_socket, buffer, sizeof(buffer) - 1, 0);
        if (valread > 0) {
            buffer[valread] = '\0';
            printf("Received: %s\n", buffer);
        }
    } while (valread > 0);

    closesocket(new_socket);  
}

}