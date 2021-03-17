#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

int palin(char *a)
{
	int start=0;
	int end=strlen(a);
	end--;
	while(start<=end)
	{
		if(a[start]==a[end])
		{
			start++;
			end--;
		}
		else
			return 0;
	}
	return 1;
}

struct message
{
	long int msg_type;
	char buff[100];
};

int main()
{
	char buff[100];
	int running=1;
	long int type=0;
	struct message msg;
	int msgid;
	msgid=msgget(1234,0666|IPC_CREAT);
	if(msgid==-1)
		printf("error in creation\n");
	while(running)
	{
		if(msgrcv(msgid, (void*) &msg, 100,type,0)==-1)
			printf("message receive failed\n");
		
		printf("Message was %s\n" , msg.buff);


		
		if(strncmp(msg.buff,"end",3)==0)
			running=0;
		else
			if(palin(msg.buff))
				printf("is a palindrom!\n");
			else
				printf("not a palindrome!\n");

	}


	if(msgctl(msgid,IPC_RMID,0)==-1)
	{
		printf("IPC_RMID FAILED!\n");
		exit(1);
	}
}