#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

pthread_mutex_t lock;
int i,n1,n2,n3,n4,n5,n6,n7,n8,n9,n10;
int a=0;

char buf[100];
void * fun(void * mes)
{

    char *name = (char *)mes;
    pthread_mutex_lock(&lock);
        for(i=a;name[i]!='\0';i++)
        {
            buf[i]=name[i];
        }
        a=a+9;
    pthread_mutex_unlock(&lock);
    
    return NULL;
}

int main()
{
char result[1000];
    char n1[10]="deeksha...";
    char n2[10]="swati....";
    char n3[10]="sanket...";
    char n4[10]="Shubham..";
    char n5[10]="shivani..";
    char n6[10]="ailla....";
    char n7[10]="Karim.....";
    char n8[10]="Sravya...";    
    char n9[10]="Azar.....";
    char n10[10]="Sanket...";


    pthread_t t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;

    pthread_mutex_init(&lock,NULL);

    pthread_create(&t1,NULL,fun,(void*)n1);
    pthread_create(&t2,NULL,fun,(void*)n2);
    pthread_create(&t3,NULL,fun,(void*)n3);
    pthread_create(&t4,NULL,fun,(void*)n4);
    pthread_create(&t5,NULL,fun,(void*)n5);
    pthread_create(&t6,NULL,fun,(void*)n6);
    pthread_create(&t7,NULL,fun,(void*)n7);
    pthread_create(&t8,NULL,fun,(void*)n8);
    pthread_create(&t9,NULL,fun,(void*)n9);
    pthread_create(&t10,NULL,fun,(void*)n10);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);
    pthread_join(t6, NULL);
    pthread_join(t7, NULL);
    pthread_join(t8, NULL);
    pthread_join(t9, NULL);
    pthread_join(t10, NULL);

   
    for(int i=0;buf[i]!='\0';i++)
    {
        printf("%c",buf[i]);
    }
    strcpy(result,n1);
strcat(result,n1);
strcat(result,n2);
strcat(result,n3);
strcat(result,n4);
strcat(result,n5);
strcat(result,n6);
strcat(result,n7);
strcat(result,n8);
strcat(result,n9);
strcat(result,n10);
printf("result is %s",result);

    pthread_mutex_destroy(&lock);

    return 0;
}
