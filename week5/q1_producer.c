#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

//producer code

int main()
{
	int pipe_fd;
	int arr[]={1,2,3,4};
	int res=mkfifo("myfifo",0777);
	if(res!=0)
		printf("error creating pipe file \n");
	printf("opening fifo file to pass contents \n");
	pipe_fd=open("myfifo", O_WRONLY);
	if(pipe_fd==-1)
		printf("error opening fifo file \n");
	else
	{
		res=write(pipe_fd,arr, sizeof(arr));
		if(res==-1)
			printf("write error in pipe\n");
	}
	close(pipe_fd);
	printf("writing finished!\n");
}