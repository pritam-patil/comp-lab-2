#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<signal.h>
#include<fcntl.h>

int listenfd;	//server socket address

void startServer(char *port)
{
    struct addrinfo hints, *res, *p;

    memset (&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;			//used for giving hint about what type of socket's needed
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
	getaddrinfo( NULL, port, &hints, &res);	//when AI_PASSIVE flag and NULL node is given, returns in res, wild-card address that can be 
											//used by servers typically to treat IPv4 nd v6 addresses same
    for (p = res; p!=NULL; p=p->ai_next)	//check in list of socket addresses 
    {
        listenfd = socket (p->ai_family, p->ai_socktype, 0);
        if (listenfd == -1) continue;
        if (bind(listenfd, p->ai_addr, p->ai_addrlen) == 0) break;	//if bound to one then break
    }
    freeaddrinfo(res);
    listen (listenfd, 1000);		//server is started now
}
//client connection
void respond(int client)
{
    char msg[10000];
    int  bytes_read;

    memset((void*)msg, (int)'\0', 10000);

    bytes_read=recv(client, msg, 10000, 0); //recv max 10000 bytes starting with 0 from the client
    printf("%s", msg);						//prints the HTTP request header
    send(client,"It works!!!",11,0);		//send the response back
    shutdown (client, SHUT_RDWR);         //All further send and recieve operations are DISABLED...
    close(client);
}

int main(int argc, char* argv[])
{
    struct sockaddr_in clientaddr;
    socklen_t addrlen;
    char PORT[6];
    strcpy(PORT,argv[1]);		//argument 1 as port number

    printf("Server started at port no. %s\n",PORT);
    startServer(PORT);			//start the server

	int client;
    while (client)
    {
        addrlen = sizeof(clientaddr);
        client= accept (listenfd, (struct sockaddr *) &clientaddr, &addrlen);	//accept connection from client(browser)
        respond(client);					//respond to client
    }
    return 0;
}
