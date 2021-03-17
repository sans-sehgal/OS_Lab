#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <wait.h>

int main()
{
	pid_t pid;
	printf("this is a parent\n");
	
	pid=fork();
	if(pid<0)
		printf("error!");
	else if(pid==0)
	{	
		sleep(1);
		printf("this is a child process!\n");
		printf("child %d\n" , getppid());
	}
	else
	{
		wait(NULL);
		printf("this is the parent process\n");
		printf("%d\n" , pid);
	}

}
