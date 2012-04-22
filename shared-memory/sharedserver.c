#include<sys/shm.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/ipc.h>
#define SIZE 27
 main()
{
	key_t key;
	char *s;
	key=5678; //5678 is the name of the segment
	int shmid;  
	char *shm,c;


	//creating the shared memory
// size is size of the buffer 	
	if((shmid=shmget(key,SIZE,IPC_CREAT | 0666))<0)
	{
		printf("Error in creating the shared memory");
		perror("Error in creating the shared memory");
		exit(1);

	}
//shm will get pointer to the shared memory 
	//printf("identifier %d \n",shmid);
	if((shm=shmat(shmid,NULL,0))==(char*)-1)
	{
		perror("Error in attaching the shared memory to the data space");
		printf("error in shmat");
		exit(1);
	}
	printf("attached the segment to the dataspace\n");
//wrinting the data to the shared memory

	s=shm;
	for(c='a';c<='z';c++)
	{
	printf("%c \n",c);
	*s++=c;;
		
	}
	*s=NULL;
	while(*shm!='*')
	sleep(1);
	exit(0);
	
}
