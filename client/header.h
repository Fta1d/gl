#ifndef HEADER_DOT_H
#define HEADER_DOT_H

#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
#define MAX 1000


int ush_connect(char *addrs);
void send_mssg(char **mssg);



#endif // HEADER_DOT_H
