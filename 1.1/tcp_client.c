#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>         
#include <arpa/inet.h>
#include <time.h>
#define PORT 8080
void print_current_time(const char * label)
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    printf("%s: %s\n", label, buffer);
}

int main()
{
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    print_current_time("Connection start time");
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
    char * message = "Hello from client\n";
    int total_chunks = 10;
    for (int i=0 ; i<total_chunks ; i++)
    {
        send(sock,message,strlen(message),0);
        usleep(300000);
    }
    printf("message sent\n");
   /*int valread = read(sock , buffer , sizeof(buffer));
    if(valread > 0)
    {
        printf("message from server is %s\n" , buffer);
    }*/
    close(sock);

    print_current_time("Connection end time");

    return(0);
}