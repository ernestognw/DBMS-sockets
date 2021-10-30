/*
	C ECHO client example using sockets
*/
#include <stdio.h>      //printf
#include <string.h>     //strlen
#include <sys/socket.h> //socket
#include <arpa/inet.h>  //inet_addr
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[1000], server_reply[2000];

    //Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        printf("NO SE PUDO CREAR EL SOCKET");
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    //Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }

    puts("Connected\n");

    //mandar el username al servidor

    printf("Introduzca username : ");
    scanf("%s", message);
    //Send some data
    if (send(sock, message, strlen(message), 0) < 0)
    {
        puts("Send failed");
        return 1;
    }

    //mandar el password
    int contador = 0;
    while (contador < 3)
    {
        printf("Introduzca password : ");
        scanf("%s", message);
        //Send some data
        if (send(sock, message, strlen(message), 0) < 0)
        {
            puts("Send failed");
            return 1;
        }
        //recibir el resultado

        if (recv(sock, server_reply, 2000, 0) < 0)
        {
            puts("recv failed");
            return 1;
        }

        //si el resultado no es correcto volver a intentar

        if (strcmp(server_reply, "Username or password is incorrect... Try again...") == 0)
        { //si si son iguales, el mensaje que me manda el servidor
            puts(server_reply);
            contador++;
            if (contador == 3)
            {
                puts("Number of tries exceeded");
                return 1; //error
            }
        }
        else if (strcmp(server_reply, "Welcome") == 0)
        { // si el servidor manda como mensaje welcome
            puts("Weolcome to the database");
            break;
        }
        else
        {
            puts("Message not recognized...");
            return 1;
        }
    }

    while (1)
    {

        //Send some data
        if (send(sock, message, strlen(message), 0) < 0)
        {
            puts("Send failed");
            return 1;
        }

        //Receive a reply from the server
        if (recv(sock, server_reply, 2000, 0) < 0)
        {
            puts("recv failed");
            break;
        }

        puts("Server reply :");
        puts(server_reply);
    }

    close(sock);
    return 0;
}