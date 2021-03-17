#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
int main(int argc, char const *argv[])
{
	printf("in parent process\n");
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		execl(argv[1],"q1",NULL);
	}
	else
	{
		wait(NULL);

	}
	return 0;
}