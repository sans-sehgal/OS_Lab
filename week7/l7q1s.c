#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "shared_mem.c"

int main()
{
	
	struct shared_mem *share;
	void *shared_memory;
	int shmid;
	shmid=shmget(1234,sizeof(struct shared_mem),0666|IPC_CREAT);
	shared_memory=shmat(shmid,(void*)0,0);
	if(shared_memory==(void*)-1)
	{
		printf("error!\n");
		exit(1);
	}
	printf("memory attached!\n");

	share=(struct shared_mem*)shared_memory;
	int running=1;
	while(running)
	{
		if(share->written_by_you)
		{
			printf("written by you was...\n");
			printf("%s\n", share->buff);
			sleep(1);
			share->written_by_you=0;
		}
	}
}