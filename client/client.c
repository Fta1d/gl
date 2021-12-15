#include "header.h"

static int sockfd;

void send_mssg(char **mssg)
{   
    char buff[MAX];
   
    strcpy(buff, mssg[1]);
    strcat(buff, " ");

    for (size_t i = 2; mssg[i] != NULL; ++i)
    {
        strcat(buff, mssg[i]);
        strcat(buff, " ");
    }
    
    write(sockfd, buff, sizeof(buff));
}
   
int ush_connect(char *addrs)
{
    int connfd;
    char IP[100];
    char SERV_PORT[100]; 
    struct sockaddr_in servaddr, cli;
   
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    
    int i = 0, y = 0;
    while (addrs[i] != ':')
    {
        IP[i] = addrs[i];
        ++i;
    }
    IP[i] = '\0';
    ++i;
    
    while (addrs[i] != '\0')
    {
        SERV_PORT[y] = addrs[i];
        ++i;
        ++y;
    }
    SERV_PORT[y] = '\0';
    
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(IP);
    servaddr.sin_port = htons(atoi(SERV_PORT));
   
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Connection with the server failed...\n");
        return 0;
    }
    else
        printf("Connected to the server..\n");

    return 1;
}