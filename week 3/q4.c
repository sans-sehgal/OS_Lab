#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pidfather,pidson;
	pidfather=fork();
	if(pidfather==0)
	{	
		pidson=fork();
		if(pidson==0)
		{
			printf("pid of 3rd before second dead %d\n" , getppid());
			sleep(10);
			printf("pid of 3rd after second dead %d\n" , getppid());

		}
		else
		{
			printf("middle child pid%d\n", getpid());
			sleep(1);
			printf("killing middlle process now\n");
			exit(0);
		}
	}
	else  
	{
		
		printf("grandad process pid %d\n" , getpid());
		sleep(20);
		
		printf("grandad still here !");
	}
}