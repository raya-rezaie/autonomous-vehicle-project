#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
int main()
{
    int sockfd;
    struct sockaddr_in  serv_addr;
    char buffer[1024];
    char *message = "Hello from UDP client";
    sockfd = socket(AF_INET , SOCK_DGRAM , 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET , "192.168.163.1" , &serv_addr.sin_addr);
    sendto(sockfd, message, strlen(message), 0,
    (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    printf("Message sent to server\n");

    socklen_t len = sizeof(serv_addr);
    int n = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0,
                     (struct sockaddr*)&serv_addr, &len);
    if (n > 0) {
        buffer[n] = '\0';
        printf("Received: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}