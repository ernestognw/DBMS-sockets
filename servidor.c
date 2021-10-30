/*
	C socket server example
*/

#include <stdio.h>
#include <string.h> //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

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

    umask(027);

    int x;
    for (x = sysconf(_SC_OPEN_MAX); x >= 0; x--)
    {
        close(x);
    }
}

int main(int argc, char *argv[])
{
    deamonize();
    int socket_desc, client_sock, c, read_size, read_size2;
    struct sockaddr_in server, client;
    char client_message[2000];
    char client_user[30];
    char client_password[20];
    char correctUser[] = "Karina";
    char correctPassword[] = "123456";

    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    //Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");

    //Listen
    listen(socket_desc, 3);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);

    //accept connection from an incoming client
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c);
    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }
    puts("Connection accepted");

    int contador = 0;
    while (contador < 3)
    {
        //1. recibir el usuario
        read_size = recv(client_sock, client_user, 30, 0);
        //2. recibir password
        read_size2 = recv(client_sock, client_password, 20, 0);

        if (read_size == 0)
        {
            // puts("Client disconnected");
            // // fflush(stdout);
            return 1;
        }
        else if (read_size == -1)
        {
            // perror("recv failed");
            return 1;
        }

        //3. checar si son correctos
        if (strcmp(client_user, correctUser) == 0 && strcmp(client_password, correctPassword) == 0)
        {
            //3.1 SISI continuar con las instrucciones del menú
            write(client_sock, "Welcome", strlen("Welcome"));
            break;
            //3.2 SINO
        }
        else
        {

            write(client_sock, "Username or password is incorrect... Try again...", strlen("Username or password is incorrect... Try again..."));
            //3.2.1 Sumar al contador
            contador++;
            //3.2.2 Checar si el contador ya se paso
            if (contador = 3)
            {
                return 1;

                //3.2.3 Regresar al inicio
            }
        }

        ////////// ESTO SIRVE PARA CUANDO QUIERAN ESTABLECER COMUNICACION Y DAR INSTRUCCIONES DE INSERTAR ETC /////

        //Receive a message from client
        // while( (read_size = recv(client_sock , client_message , 2000 , 0)) > 0 )
        // {
        // 	//Send the message back to client
        // 	write(client_sock , client_message , strlen(client_message));
        // }
    }

    return 0;
}
