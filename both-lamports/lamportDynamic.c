#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

#define CPU 10

pthread_t tid[CPU];		//max 10 threads..change CPU value, if you want more
pthread_mutex_t critical;	//accessing the critica section..lock is required
int total;		//total processors

struct PROCESSOR
{
	int clk,incr,id;		//each processor has it's own id, clk value nd increment
};
struct PROCESSOR p[CPU],sender;


void* increment(void *proc)
{
	struct PROCESSOR*current=(struct PROCESSOR*)proc;
	while(1)
	{
		sleep(2);			//you need to increment this , if your processor is fast, in order to get o/p right
		printf("Incrementing Processor %d's clk from [%d o'clock] ",current->id,current->clk);
		current->clk+=current->incr;			//increment current processor's clk
		printf("to [%d o'clock]\n",current->clk);
	}
}

void *sync(void* processor)
{
	pthread_t interval;
	pthread_create(&interval,NULL,&increment,processor);
	struct PROCESSOR*current=(struct PROCESSOR*)processor;
	while(1)
	{
		sleep(5);				//you need to increment this , if your processor is fast, in order to get o/p right
		pthread_mutex_lock(&critical);	//lock ..so that only thread should access this section at a time
		if(sender.id!=current->id)
			if(sender.clk>current->clk)	//sync required
			{
				printf("Processor %d(at [%d o'clock]) got message from Processor %d(at [%d o'clock]),so sync'ing Processor %d...\n",current->id,current->clk,sender.id,sender.clk,current->id);
				current->clk=sender.clk+1;//sync
				printf("Processor %d's clock sync'd to [%d o'clock]\n",current->id,current->clk);	//sync done
			}
			else		//no sync required
			{
				printf("Processor %d(at [%d o'clock]) got message from Processor %d(at [%d o'clock]),so no sync'ing required...\n",current->id,current->clk,sender.id,sender.clk);
			}
		sender.id=current->id;	//make current processor as sender
		//print before unlocking---only one change to get all the o/p correct
		printf("Now Processor %d sends msg at [%d o'clock]\n",current->id,current->clk);	//send message
		pthread_mutex_unlock(&critical);	//remove lock
		//printf("Now Processor %d sends msg at [%d o'clock]\n",current->id,current->clk);	//send message
	}
	pthread_join(interval,NULL);
}

int main(int argc,char *argv[])
{
	int i;
	sender.id=1;		//processor 1 as current sender
	sender.clk=0;
	sender.incr=atoi(argv[1]);
	pthread_create(&tid[0],NULL,&sync,&sender);	//thread for processor 1
//	pthread_join(tid[0],NULL);
	for(i=1;i<(total=argc-1);i++)	//for successive senders
	{
		p[i].clk=0;
		p[i].incr=atoi(argv[i+1]);
		p[i].id=i+1;
		pthread_create(&tid[i],NULL,&sync,&p[i]);
	}
	for(i=0;i<total;i++)
		pthread_join(tid[i],NULL);		//join each thread
}
