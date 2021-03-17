#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>

int read_count=0;
sem_t semaphore,mutex,db;
int data=1;

void* read(void* args)
{
	sem_wait(&mutex);
	read_count++;
	if(read_count==1)
		sem_wait(&db);
	sem_post(&mutex);
	printf("Data read by semaphore %d is %d \n", (*(int*)args),data);

	sem_wait(&mutex);
	read_count--;
	
	if(read_count==0)
		sem_post(&db);
	sem_post(&mutex);
	//printf("here now\n");
}

void* write(void *args)
{
	sem_wait(&db);
	data=data*2;
	printf("writer %d changed value of data from %d to %d\n", (*(int*)args),data/2,data);
	sem_post(&db);


}
int main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	//sem_t semaphore,mutex,db;
	sem_init(&semaphore,0,10);
	sem_init(&mutex,0,1);
	sem_init(&db,0,1);

	pthread_t readers[10],writers[5];
	for(int i=0; i<10; i++)
		pthread_create(&readers[i], NULL,read,(void*)&arr[i]);
	for(int i=0; i<5; i++)
		pthread_create(&writers[i], NULL,write,(void*)&arr[i]);
	

	for(int i=0; i<10;i++)
	{
		//yprintf("%d joined\n", i);
		pthread_join(readers[i],NULL);
		
	}
	for(int i=0; i<5;i++)
		pthread_join(writers[i],NULL);

	//printf("came here\n");
	return 0;
}
