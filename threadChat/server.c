#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

int serverSock;

start(char *port)
{
	struct sockaddr_in add;
	serverSock=socket(AF_INET,SOCK_STREAM,0);
	if(serverSock==-1)
		printf("Error in socket creation");
 	bzero((char *) &add, sizeof(add));
    add.sin_family = AF_INET;
    add.sin_addr.s_addr = INADDR_ANY;
    add.sin_port = htons(atoi(port));
//-----------Binding of Socket ---------------------//
    if (bind(serverSock, (struct sockaddr *) &add,
         sizeof(add)) < 0) 
        error("ERROR on binding");
//----------- Listening to the socket---------------------//
     listen(serverSock,5);
     printf("Server started");
}

main(int argc,char *argv[])
{
	start(argv[1]);
	return 0;
}
