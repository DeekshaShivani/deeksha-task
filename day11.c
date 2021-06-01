#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void * array(void* arg)
{
int *arr=(int*)arg;
int i,sum=0;
	for (i=0;i<10;i++)
	{
	sum+=arr[i];
	
	}
	printf("sum of %d\n",sum);
}
int main()
{
int a[10]={1,2,3,4,5,6,7,8,9,1};


int b[10]={1,3,1,1,3,1,1,1,1,2};
int c[10]={1,15,1,1,3,5,9,1,6,2};
int d[10]={1,1,4,2,3,4,5,7,1,5};



pthread_t t1,t2,t3,t4;

pthread_create(&t1,NULL,array,(void*)a);
pthread_create(&t2,NULL,array,(void*)b);
pthread_create(&t3,NULL,array,(void*)c);
pthread_create(&t4,NULL,array,(void*)d);

pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t3,NULL);
pthread_join(t4,NULL);
return 0;
}

