#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	printf("this is definitily parent\n");
	char *message;
	pid_t pid;
	int n;
	pid=fork();
	switch(pid)
	{
		case -1:
		{
			printf("fork failed\n");
			exit(1);
		}
		case 0:
		{
			printf("child process");
			message="this is child";
			n=5;
			break;
		}
		default:
		{
			//wait(NULL);
			printf("parent process\n");
			message="this is parent";
			n=3;
			break;
		}
	}
	for(;n>0;n--)
	{
		printf("%s\n", message);
		sleep(2);
	}
}