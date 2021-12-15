#include "header.h"

static int PORT = 8080;
static int sockfd;

void func(int connfd)
{
    char buff[MAX];

    read(connfd, buff, sizeof(buff));
    printf("From client: %s\n", buff);
     
}

void start_server(void) {
    int connfd, len;
    struct sockaddr_in servaddr, cli;
   
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
   
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
   
    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
        printf("Socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");
   
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);
   
    connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
    if (connfd < 0) {
        printf("Server accept failed...\n");
        exit(0);
    }
    else
        printf("Server accept the client...\n");
   
    func(connfd);
   
}

void stop_server(void) {
    close(sockfd);
    printf("Server stoped\n");
}

void set_port(char *prt) {
    PORT = atoi(prt);
}