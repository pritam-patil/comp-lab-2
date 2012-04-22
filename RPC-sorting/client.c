#include "sorting.h"
#include<stdlib.h>

void prog_sort_1(char *host,Array *input)
{
	CLIENT *c;
	int i;
	double *status;
	c=clnt_create(host,PROG_SORT,VER_SORT,"udp");
	if(c==NULL)
		exit(1);

	input=sort_1(input,c);
	clnt_destroy(c);
	
	printf("Sorted array :");
	for(i=0;i<input->size;i++)
		printf("\t %d ",input->num[i]);
	
}	

int main(int argc,char *argv[])
{
	int i;
	char *host=argv[1];
	Array input;
	input.size=argc-2;
	for(i=0;i<input.size;i++)
		input.num[i]=atoi(argv[i+2]);

	prog_sort_1(host,&input);
	return 0;
}