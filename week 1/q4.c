#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
int main(int argc, char const *argv[])
{
	// char c;
	if(argc!=3)
	{
		printf("You need to provide 2 files names as input args\n");
		exit(1);
	}
	FILE *in, *out;// file descriptors

	in = (FILE*)fopen(argv[1], "r");
	out = (FILE*)fopen(argv[2], "w+");

	// while(fgetc == 1)
	// 	write(out, &c, 1);
	while(1)
	{
		if(feof(in))
			break;
		fputc(fgetc(in), out);
	}
	fclose(in);
	fclose(out);
	return 0;
}