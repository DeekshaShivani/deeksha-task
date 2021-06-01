#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
pthread_mutex_t lock_mutex;
pthread_cond_t condition_var;
void *odd();
void *even();
int count=0;
#define NUM 4

void *odd()
{
while(1){

pthread_mutex_lock(&lock_mutex);
if(count%2!=0)
{

pthread_cond_wait(&condition_var,&lock_mutex);

}
printf("inc\n");
count++;
printf("thread1:%d\n",count);

pthread_cond_signal(&condition_var);

if(count >= NUM)
{
 pthread_mutex_unlock(&lock_mutex);
 
 return(NULL);

}
pthread_mutex_unlock(&lock_mutex);
printf("unlock\n");
}
}


void *even()
{
while(1)
{

pthread_mutex_lock(&lock_mutex);
if(count%2==0)
{

pthread_cond_wait(&condition_var,&lock_mutex);

}
count++;
printf("thread2:%d\n",count);

pthread_cond_signal(&condition_var);

if(count>=NUM)
{

 pthread_mutex_unlock(&lock_mutex);
 return(NULL);
}
pthread_mutex_unlock(&lock_mutex);

}
}


int main()
{
pthread_t thread1,thread2;

pthread_mutex_init(&lock_mutex,NULL);

pthread_create(&thread1,NULL, &odd,NULL);
pthread_create(&thread2,NULL, &even,NULL);
pthread_join(thread1, NULL);
pthread_join(thread2, NULL);
pthread_mutex_destroy(&lock_mutex);
return 0;
}
