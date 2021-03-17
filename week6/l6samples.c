#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//sender code

struct message
{
	long int msg_type;
	char buff[100];
};

int main()
{
	struct message msg;
	int msgid;
	int running =1;
	msgid=msgget(1234, 0666|IPC_CREAT);
	if(msgid==-1)
	{
		printf("error creating message queue!\n");
		exit(1);
	}

	while(running)
	{
		char buff[100];
		printf("enter message to send\n");
		scanf("%s" , buff);
		strcpy(msg.buff,buff);
		int x=msgsnd(msgid, (void*)&msg, 100,0);
		if(x==-1)
			printf("failed to send message!\n");


		if(strncmp(msg.buff,"end" ,3)==0)
		{	
			printf("%s\n" , buff);
			running=0;
		}
	}
	printf("this shouldn't be printed\n");
}