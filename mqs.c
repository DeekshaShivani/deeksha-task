#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define SERVER_QUEUE_NAME   
#define QUEUE_PERMISSIONS 0660
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 4096
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10

int main (int argc, char **argv)
{
    mqd_t qd_server, qd_client;   
    long token_number = 1; 

    printf ("Server: Hello, World!\n");

    typedef struct Req
    {
        char qname[50];
        int cmd;
        char data[4096];
    } Req;

    Req buf;

    struct mq_attr attr;

    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;
    mq_unlink(SERVER_QUEUE_NAME);
    if ((qd_server = mq_open (SERVER_QUEUE_NAME, O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
        perror ("Server: mq_open (server)");
        exit (1);
    }
    char in_buffer [MSG_BUFFER_SIZE];
    char out_buffer [MSG_BUFFER_SIZE];

    while (1) {
        if (mq_receive (qd_server, (char *) &buf, 4096, NULL) == -1) {
            perror ("Server: mq_receive");
            exit (1);
        }
        printf("Received qname:%s\n",buf.qname);
        printf("REceived data:%s\n",buf.data);
        printf("Received cmd:%d\n",buf.cmd);


    } 
}
