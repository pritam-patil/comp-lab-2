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

#define CONNMAX 1000
#define BYTES 1024

int listenfd, clients[CONNMAX];
//start server
void startServer(char *port)
{
    struct addrinfo hints, *res, *p;

    memset (&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
	getaddrinfo( NULL, port, &hints, &res);
    for (p = res; p!=NULL; p=p->ai_next)
    {
        listenfd = socket (p->ai_family, p->ai_socktype, 0);
        if (listenfd == -1) continue;
        if (bind(listenfd, p->ai_addr, p->ai_addrlen) == 0) break;
    }
    freeaddrinfo(res);
	listen (listenfd, 1000);
}

//client connection
void respond(int n)
{
    char msg[1000];
    int bytes_read;

    memset( (void*)msg, (int)'\0', 1000 );

	bytes_read=recv(clients[n], msg, 1000, 0);
	if(bytes_read)
    {
        printf("%s", msg);
        send(clients[n],"It Works !!!",11,0);
    }
    //Closing SOCKET
    shutdown (clients[n], SHUT_RDWR);         //All further send and recieve operations are DISABLED...
    close(clients[n]);
    clients[n]=-1;
}

int main(int argc, char* argv[])
{
    struct sockaddr_in clientaddr;
    socklen_t addrlen;
    
    //Default Values PATH = ~/ and PORT=333000
    char PORT[6];
    strcpy(PORT,argv[1]);

    int slot=0;

    printf("Server started at port no. %s\n",PORT);
    // Setting all elements to -1: signifies there is no client connected
    int i;
    for (i=0; i<CONNMAX; i++)
        clients[i]=-1;
    startServer(PORT);

    // ACCEPT connections
    while (1)
    {
        addrlen = sizeof(clientaddr);
        clients[slot] = accept (listenfd, (struct sockaddr *) &clientaddr, &addrlen);

            if ( fork()==0 )
            {
                respond(slot);
                exit(0);
            }
        while (clients[slot]!=-1) slot = (slot+1)%CONNMAX;
    }
    return 0;
}
