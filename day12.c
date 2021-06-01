#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>



void* thread_float(void* f) 
{  
    float a=0.1,b=0.1;
    for(int i=0;i<10;i++)
    {
        printf("Float:%.1f\n",a);
        a=a+b;
    }
}

void* thread_char(void* c) 
{
    char ch='a';
    for(int i=0;i<26;i++)
    {
        printf("Character:%c\n",ch);
        ch=ch+1;
    }   
    
}
void * thread_integer(void* in)
{
    int i;
    for(i=1;i<52;i++)
    {
        printf("Integer:%d\n",i);
    }
}

int main()
{
    pthread_t t1,t2,t3;

    pthread_create(&t1,NULL,thread_float,NULL);
    pthread_create(&t2,NULL,thread_char,NULL);
    pthread_create(&t3,NULL,thread_integer,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    return 1;
}
