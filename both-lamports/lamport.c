/*====This is Lamport Algorithm for clock sync of two processor---*/

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

int cl1,cl2;
pthread_t tid[2];	//id of two thread created for each processor
pthread_mutex_t critical;	//for critical region
int sender=1;		//processor 1 is default sender

void* increment1(void *inc)		//incrementing clock 1
{
	sleep(2);
	cl1+=*(int*)inc;
	printf("Comp1's clk at %d\n",cl1);
}

void *clock1(void* inc)		//for checking the sync between sender and receiver
{
	pthread_t interval;
	pthread_create(&interval,NULL,&increment1,inc);
	while(1)
	{
		sleep(3);
		pthread_mutex_lock(&critical);	//lock so as only one processor should access this section
		if(sender==2 && cl1<cl2)	//check for sync
		{
			printf("Comp 1(at %d) got message from comp2(at %d),so sync'ing comp1...\n",cl1,cl2);
			printf("comp1 clock sync'd to %d\n",cl1=cl2+1);//do sync
		}
		sender=1;
		pthread_mutex_unlock(&critical);//unlock the section
		printf("Now comp1 sends msg at %d\n", cl1);
	}
	pthread_join(interval,NULL);
}

void* increment2(void *inc)//incrementing clock 2
{
	sleep(2);
	cl2+=*(int*)inc;
	printf("Comp2's clk at %d\n",cl2);
}


void* clock2(void* inc)
{
	pthread_t interval;
	pthread_create(&interval,NULL,&increment2,inc);
	while(1)
	{
		sleep(3);
		pthread_mutex_lock(&critical);
		if(sender==1 && cl2<cl1)
		{
			printf("Comp 2(at %d) got message from comp1(at %d), sync'ing comp2...\n",cl2,cl1);
			printf("comp2 clock sync'd to %d\n",cl2=cl1+1);
		}
		sender=2;
		pthread_mutex_unlock(&critical);
		printf("Now comp2 sends msg at %d\n", cl2);
	}
	pthread_join(interval,NULL);
}



int main(int argc,char *argv[])
{
	int inc[2];
	cl1=cl2=0;
	inc[0]=atoi(argv[1]);
	inc[1]=atoi(argv[2]);
	
	pthread_create(&tid[0],NULL,&clock1,&inc[0]);	//create two threads
	pthread_create(&tid[1],NULL,&clock2,&inc[1]);
	
	pthread_join(tid[0],NULL);	//join them
	pthread_join(tid[1],NULL);
}
