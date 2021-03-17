#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include "shared_mem.c"

int main()
{
	struct shared_mem* share;
	int shmid;
	void *shared_memory;
	shmid=shmget(1234, sizeof(struct shared_mem) , 0666|IPC_CREAT);
	if(shmid==-1)
		printf("error creating memory space\n");

	shared_memory=shmat(shmid, (struct shared_mem*)share, 0);
	if(shared_memory==(void*)-1)
		printf("shmat failed\n");

	share=(struct shared_mem*)shared_memory;

	int running=1;
	while(running)
	{
		while(share->written_by_you==1)
		{
			printf("waiting for client\n");
			sleep(1);
		}
		char buff[100];
		printf("enter some text\n");
		scanf("%s" , buff);
		strcpy(share->buff,buff);
		share->written_by_you=1;
	}


}