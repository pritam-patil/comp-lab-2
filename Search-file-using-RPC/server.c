#include "search.h"
#include<rpc/rpc.h>
#include<stdio.h>
#include<stdlib.h>
		
double * searchfile_1(File *f, CLIENT *cl)
{
	FILE *fp=fopen(f->name,"r");
	fclose(fp);
	return (double*)fp;
}

double * searchfile_1_svc(File *f, struct svc_req *svr)
{
	CLIENT *c;
	return (searchfile_1(f,c));
}

