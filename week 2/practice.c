#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>


void printdir(char *path, int depth)
{
	DIR *dp;
	struct dirent *entry;
	struct stat buf;

	if((dp=opendir(path))==NULL)
	{	
		printf("open failed!");
		exit(1);
	}
	else
	{
		chdir(path);
		while((entry=readdir(dp))!=NULL)
		{
			lstat(entry->d_name,&buf);
			if(S_ISDIR(buf.st_mode))
			{
				if(strcmp(entry->d_name,".")==0 || strcmp(entry->d_name,".."))
					continue;
				printf("%s\n", entry->d_name);
			}
			else
			{
				printf("%s\n", entry->d_name);
			}
			printdir(entry->d_name,depth+4);

		}
	} 
	chdir("..");
	closedir(dp);
}

int main(int argc, char const *argv[])
{
	printdir("/home/sanskar/desktop",0);	
}