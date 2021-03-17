#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
	FILE *fptr=fopen("new.bin", "wb+");
	if(fptr==NULL)
		printf("couldn't open file!\n");
	for(int i=0; i<4; i++)
	{
		int x;
		printf("enter integer");
		scanf("%d" , &x);
		fwrite(&x, sizeof(int), 1, fptr);
	}

	fclose(fptr);

	fptr=fopen("new.bin", "rb");
	for(int i=0; i<4; i++)
	{
		int x;
		fread(&x, sizeof(x) , 1 , fptr);
		printf("writing integer: %d\n" , x);
	}
	fclose(fptr);
}