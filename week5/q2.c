#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
	char *data="i am here";
	
	int fptr1;
	fptr1=open("write.c", O_WRONLY);  //file to write data into from pipe
	int fd[2];
	int n;
	char ch;
	pid_t pid;
	pipe(fd);
	pid=fork();
	if(pid==0)
	{
		close(fd[1]); //close writing end
		while(read(fd[0],&ch,1)>0)
		{
			
			printf("now wrting into write.c ...\n");
			write(fptr1, &ch , sizeof(ch));
		}
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		write(fd[1] , data , strlen(data));
		printf("write success!\n");
		close(fd[1]);
		wait(NULL);
	}

} 