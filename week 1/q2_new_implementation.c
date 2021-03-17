#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int no_of_lines;
	int count;
	int in;
	char ch;
	char line[100]="";
	for(int i=1; i<=2; i++)
	{
		in=open(argv[i],O_RDONLY);
		if(in==-1)
			write(2,"file does not exist",19);
		else
		{
			printf("Reading file %s\n", argv[i] );
			while(read(in,&ch,sizeof(ch))>0)
			{
				if(ch!='\n' && ch!='\0')
				{
					strncat(line,&ch,1);
				}
				else
				{
					no_of_lines++;
					count++;
					printf("Line %d: %s\n",no_of_lines,line );
					line[0]='\0';
				}
				if(count==20)
				{
					count=0;
					char c;
					printf("press any key to continue or q to quit");
					scanf("%c" , &c);
					if(c=='q')
						break;

				}
			}
		}

	}
}
