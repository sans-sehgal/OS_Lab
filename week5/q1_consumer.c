#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
	int pipe_fd;
	int buffer[4];
	pipe_fd=open("myfifo", O_RDONLY);
	if(pipe_fd==-1)
		printf("fifo cannot be openend!\n");

	int res;
	int x;
	int i=0;
	do{
	res=read(pipe_fd, &x, sizeof(int) );
	buffer[i]=x;
	i++;
	}while(res>0);
	if(res==-1)
		printf("read error in pipe\n");
	else
		for(int i=0; i<4;i++)
			printf(" %d " ,buffer[i]);


}