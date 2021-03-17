#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
struct shared_use
{
	char c;
	char next_char;
};
int main()
{
	void *shared_memory = (void *)0;
	int shmid;
	struct shared_use *stuff;
	char buffer;
	pid_t p;
	p = fork();
	if (p == -1)
	{
		fprintf(stderr,"fork failed!!\n");
		exit(EXIT_FAILURE);
	}
	else if (p == 0)
	{
		shmid = shmget((key_t)1234,sizeof(struct shared_use),0666|IPC_CREAT);
		if(shmid==-1)
		{
			fprintf(stderr,"shmget failed!!\n");
			exit(EXIT_FAILURE);
		}
		shared_memory = shmat(shmid,(void *)0,0);
		if(shared_memory == (void *)-1)
		{
			fprintf(stderr, "shmat failed\n");
			exit(EXIT_FAILURE);
		}
		stuff = (struct shared_use *)shared_memory;
		sleep(10);
		printf("current char: %c\n",stuff->c);
		stuff->c++;
		if(shmdt(shared_memory)==-1)
		{
			fprintf(stderr, "shmdt failed\n");
			exit(EXIT_FAILURE);
		}
		if(shmctl(shmid,IPC_RMID,0)==-1)
		{
			fprintf(stderr, "shmctl(IP_RMID) failed\n");
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);}
		else
		{
			shmid = shmget((key_t)1234,sizeof(struct shared_use),0666|IPC_CREAT);
			if(shmid==-1)
			{
				fprintf(stderr,"shmget failed!!\n");
				exit(EXIT_FAILURE);
			}
			shared_memory = shmat(shmid,(void *)0,0);
			if(shared_memory == (void *)-1)
			{
				fprintf(stderr, "shmat failed\n");
				exit(EXIT_FAILURE);
			}
			stuff = (struct shared_use *)shared_memory;
			char ch;
			printf("Enter a character: \n");
			scanf("%c",&ch);
			stuff->c = ch;
			printf("current char: %c\n",stuff->c);
			printf("Waiting for child process to change...\n");
			wait(NULL);
			printf("new char: %c\n",stuff->c);
			if(shmdt(shared_memory)==-1)
			{
				fprintf(stderr, "shmdt failed\n");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}
	}