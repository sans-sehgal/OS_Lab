#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int sum1=0,sum2=0;
void *even_sum(void *arg)
{
	sum1=0;
	int *arr=(int*)arg;
	for(int i=0; i<10; i++)
	{
		printf("%d\n" , arr[i]);
		if(arr[i]%2==0)
			sum1+=arr[i];
	}

	


}

void *odd_sum(void *arg)
{
	sum2=0;
	int *arr=(int*)arg;
	for(int i=0; i<10; i++)
		if(arr[i]%2!=0)
			sum2+=arr[i];


}

int main()
{
	pthread_t thread1,thread2;
	int *arr=(int*)calloc(10,sizeof(int));
	for(int i=0; i<10; i++)
		scanf("%d" , &arr[i]);

	pthread_create(&thread1, NULL, even_sum, (void*)arr);
	pthread_create(&thread2, NULL, odd_sum, (void*)arr);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("sum of even numbers is %d\n" , sum1);
	printf("sum of odd numbers is %d\n" , sum2);

}