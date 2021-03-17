#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *fib(void* arg)
{
	int n=(*(int*)arg);
	int *arr=(int *)calloc(n,sizeof(int));
	arr[0]=0;
	arr[1]=1;
	for(int i=2;i<n; i++)
		arr[i]=arr[i-1]+arr[i-2];

	return arr;
}



int main()
{
	int n;
	printf("enter number of terms\n");
	scanf("%d" , &n);
	pthread_t thread1;
	int *arr;
	pthread_create(&thread1, NULL,fib,(void*)&n);
	pthread_join(thread1,(void*)&arr);
	for(int i=0;i<n; i++)
		printf("%d\n" ,arr[i]);

}