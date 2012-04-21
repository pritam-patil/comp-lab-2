#include "sorting.h"
#include<stdlib.h>

void prog_sort_1(char *host,Array unsorted)
{
	CLIENT *c;
	int i;
	double *status;
	c=clnt_create(host,PROG_SORT,VER_SORT,"udp");
	if(c==NULL)
		exit(1);
	
	status=sort_1(&unsorted,c);
	clnt_destroy(c);
	if(*status)
	{
		printf("Sorted array :");
		for(i=0;i<unsorted.size;i++)
			printf("\t %d ",unsorted.num[i]);
	}
	else
		printf("Error in RPC");
}	

int main(int argc,char *argv[])
{
	int i;
	char *host=argv[1];
	Array unsorted;
	unsorted.size=argc-2;
	for(i=0;i<unsorted.size;i++)
		unsorted.num[i]=atoi(argv[i+2]);
		
	prog_sort_1(host,unsorted);
	return 0;
}
