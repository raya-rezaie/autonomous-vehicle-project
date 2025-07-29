#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>         
#include <arpa/inet.h>
#define PORT 8080

int main()
{
    int sock = 0;
    struct sockaddr_in serv_addr;
    char * message = "Hello from client";
    char buffer[1024] = {0};
    sock = socket(AF_INET , SOCK_STREAM ,0);
    if (sock <0 )
    {
        perror("socket failed");
        return 1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
        if (inet_pton(AF_INET, "192.168.163.1", &serv_addr.sin_addr) <= 0) {
            perror("connection failed");
            return 1;
}
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        return 1;
    }
    send(sock , message , strlen(message) , 0);
    printf("message sent\n");
    int valread = read(sock , buffer , sizeof(buffer));
    if(valread > 0)
    {
        printf("message from server is %s\n" , buffer);
    }
    close(sock);
    return(0);
}