#include "sorting.h"
#include<rpc/rpc.h>
#include<stdio.h>
#include<stdlib.h>


int comp(const int *a,const int *b)
{
	return (*a-*b);
}		

double *sort_1(Array *unsorted,CLIENT *c)
{
	int i;
	for(i=0;i<unsorted->size;i++)
		printf(" % d ", unsorted->num[i]);
		
	qsort(unsorted->num,unsorted->size,sizeof(int),comp);
	return &i;
}
double *sort_1_svc(Array *unsorted,struct svc_req *svc)
{
	CLIENT *c;
	return (sort_1(unsorted,c));
}


