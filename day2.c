#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

float Temp=27.00;

pthread_mutex_t lock1=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock3=PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t cond1=PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2=PTHREAD_COND_INITIALIZER;

//LCD
void * lcd(void * arg)
{
    char *thead_id=(char *)arg;
    pthread_mutex_lock(&lock1);
    while(1)
    {
        pthread_cond_wait(&cond1,&lock1);
        printf("Temperature at Present:%f\n",Temp);
        if(Temp>45)
        {
            pthread_mutex_unlock(&lock1);
            pthread_exit(NULL);
        }
        pthread_mutex_unlock(&lock1);
        sleep(1);
    }
    return NULL;
}
//MONITOR
void * monitor(void * arg)
{
    char *thead_id=(char *)arg;
    pthread_mutex_lock(&lock2);
    while(1)
    {
        pthread_cond_wait(&cond1,&lock2);
        if(Temp<45.00 && Temp>27.00)
        {
            printf("Under control...\n");
            pthread_mutex_unlock(&lock2);
        }
        else
        {
            printf("Out of Control...\n");
            pthread_mutex_lock(&lock3);
            pthread_cond_signal(&cond2);
            pthread_mutex_unlock(&lock3);
            pthread_mutex_unlock(&lock2);
            pthread_exit(NULL);
        }
        sleep(1);
    }
    return NULL;
}
//SENSOR
void * sensor(void * arg)
{
    int Timer=0;
    char *thead_id=(char *)arg;
    while(1)
    {
        if(Timer>5)
        {
            Timer=0;
            printf("Timer Reached 5 and Event in Sensor\n");
            pthread_mutex_lock(&lock1);
            Temp=Temp+5.00;
            pthread_cond_broadcast(&cond1);
            pthread_mutex_unlock(&lock1);
        }
        Timer++;
        sleep(1);
    }
    return NULL;
}

//main
int main()
{
    printf("Main Starting....\n");
    pthread_t t1,t2,t3;
    pthread_create(&t1,NULL,sensor,NULL);
    pthread_create(&t2,NULL,lcd,NULL);
    pthread_create(&t3,NULL,monitor,NULL);

    pthread_mutex_lock(&lock3);
    while (1)
    {
        pthread_cond_wait(&cond2,&lock3);
        pthread_cancel(t1);
        pthread_mutex_unlock(&lock3);
        break;
    }
    printf("Main Ending\n");

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);

}
