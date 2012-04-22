#include "search.h"
#include<stdlib.h>

void prog_search_1(char *host,File *f)
{
	CLIENT *c;
	int i;
	c=clnt_create(host,PROG_SEARCH,VER_SEARCH,"udp");
	if(c==NULL)
		exit(1);

	if(searchfile_1(f,c))
		printf("200 : Response OK[File Found]\n");
	else
		printf("Error 404 : File not Found\n");
	clnt_destroy(c);
}	

int main(int argc,char *argv[])
{
	int i;
	char *host=argv[1];
	File f;
	strcpy(f.name,argv[2]);
	prog_search_1(host,&f);
	return 0;
}
