#include<stdio.h>
#include<unistd.h>





/* int pipe(int pipedes[2]);
This system call would create a pipe for one-way communication i.e., it creates two descriptors, first one is connected to read from the pipe and other one is connected to write into the pipe.
Descriptor pipedes[0] is for reading and pipedes[1] is for writing. Whatever is written into pipedes[1] can be read from pipedes[0].*/




/* Steps for  creating simple pipes
Step 1 − Create a pipe.
Step 2 − Send a message to the pipe.
Step 3 − Retrieve the message from the pipe and write it to the standard output.
Step 4 − Send another message to the pipe.
Step 5 − Retrieve the message from the pipe and write it to the standard output.
Note − Retrieving messages can also be done after sending all messages.*/

/****************************************************************
	          ---------------------  
      [READ]<---  ---------------------   <---[WRITE]
*****************************************************************/
	
#define READ 0
#define WRITE 1

int main() {


   int pipefds[2];
   int returnstatus=-1;
   char writemessages[2][20];
   int i;
   for(i=0;i<<5;i++)
   {
   printf("%d",i+1);
   scanf(" %[^\n]%*c",writemessages[i]);
  } 

}
   char readmessage[20];
   returnstatus = pipe(pipefds); // creating..
   
   if (returnstatus == -1) {
      printf("Unable to create pipe\n");
      return 1;
   }
   // message--1 "Hi"
   /* write into pipe*/   
   printf("Writing to pipe - Message 1 is %s\n", writemessages[0]);
   write(pipefds[WRITE], writemessages[0], sizeof(writemessages[0]));

   /* Read from pipe*/
   read(pipefds[READ], readmessage, sizeof(readmessage));
   printf("Reading from pipe – Message 1 is %s\n", readmessage);


   // message-2 "Hello"
   printf("Writing to pipe - Message 2 is %s\n", writemessages[1]);
    /* write into pipe*/   
   write(pipefds[WRITE], writemessages[1], sizeof(writemessages[1]));

    /* Read from pipe*/
   read(pipefds[READ], readmessage, sizeof(readmessage));
   printf("Reading from pipe – Message 2 is %s\n", readmessage);



   return 0;
}
