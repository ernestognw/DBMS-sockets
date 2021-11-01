#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <syslog.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include "./definitions.c"

static void daemonize()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
        exit(EXIT_FAILURE);

    if (pid > 0)
        exit(EXIT_SUCCESS);

    if (setsid() < 0)
        exit(EXIT_FAILURE);

    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);

    pid = fork();

    if (pid < 0)
        exit(EXIT_FAILURE);

    if (pid > 0)
        exit(EXIT_SUCCESS);

    int x;
    for (x = sysconf(_SC_OPEN_MAX); x >= 0; x--)
    {
        close(x);
    }
}

int authenticate(int sockfd)
{
    char username[MAX];
    char password[MAX];
    char correctUsername[] = "Karina";
    char correctPassword[] = "123456";
    int tries = 0;
    while (tries < 3)
    {
        recv(sockfd, username, MAX, 0);
        recv(sockfd, password, MAX, 0);

        if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0)
        {
            write(sockfd, PASSED_AUTH, strlen(PASSED_AUTH));
            return 1;
        }
        else
        {
            write(sockfd, FAILED_AUTH, strlen(FAILED_AUTH));
            tries++;
        }
    }
    return 0;
}

// Driver function
int main(int argc, char *argv[])
{
    printf("Starting daemonize\n");
    daemonize();

    int sockfd, connfd, len;
    SAIN servaddr, cli;

    // Socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Socket creation failed...\n");
        exit(1);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // Assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0)
    {
        printf("Socket bind failed...\n");
        exit(1);
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0)
    {
        printf("Listen failed...\n");
        exit(1);
    }
    else
        printf("Server listening...\n");
    len = sizeof(SAIN);

    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA *)&cli, (socklen_t *)&len);
    if (connfd < 0)
    {
        printf("Server accept failed...\n");
        exit(1);
    }
    else
        printf("Server accept the client...\n");

    // Function for chatting between client and server
    int authenticated = func(connfd);

    if (authenticated)
    {
        // TODO: Connect with DBMS and send messages
    }

    // After chatting close the socket
    close(sockfd);

    return 0;
}
