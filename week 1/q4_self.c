#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
 
int main()
{
	int in=open("q2.c" , O_RDONLY);
	int out=open("test.c",O_CREAT|O_WRONLY, S_IRUSR|S_IXOTH|S_IWUSR);

	if(in==-1)
		write(2,"open error!",11);
	char c;
	while(read(in,&c,sizeof(c))>0)
	{
		write(out,&c, sizeof(c));
	}
	close(in);
	close(out);
}