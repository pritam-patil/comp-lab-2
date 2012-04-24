#include "sorting.h"
#include<rpc/rpc.h>
#include<stdio.h>
#include<stdlib.h>
		
int comp(const int *a,const int *b)
{
	return (*a-*b);
}

Array *sort_1(Array *input,CLIENT *c)
{
	int i,j,temp;
	qsort(input->num,input->size,sizeof(int),(__compar_fn_t)comp);
	return input;
}

Array *sort_1_svc(Array *input,struct svc_req *svc)
{
	CLIENT *c;
	return (sort_1(input,c));
}
