#include<stdio.h>
#include<unistd.h>

int main() {
   int n;
   int pipefds[n];
   int returnstatus;
   
   char writemessages[n][30];

    int i;

    for(i=0;i<n;i++)
    {
       printf("Enter a string %d:",i+1);
       scanf(" %[^\n]",writemessages[i]);
    }
   
   char readmessage[30];
   returnstatus = pipe(pipefds);
   
   if (returnstatus == -1) {
      printf("Unable to create pipe\n");
      return 1;
   }
   
   
   printf("Writing to pipe - Message 1 is %s\n", writemessages[0]);
   write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
   read(pipefds[0], readmessage, sizeof(readmessage));
   printf("Reading from pipe – Message 1 is %s\n", readmessage);
   printf("Writing to pipe - Message 2 is %s\n", writemessages[1]);
   write(pipefds[1], writemessages[1], sizeof(writemessages[1]));
   read(pipefds[0], readmessage, sizeof(readmessage));
   printf("Reading from pipe – Message 2 is %s\n", readmessage);
   
   
   printf("Writing to pipe - Message 1 is %s\n", writemessages[2]);
   write(pipefds[1], writemessages[2], sizeof(writemessages[2]));
   read(pipefds[0], readmessage, sizeof(readmessage));
   printf("Reading from pipe – Message 1 is %s\n", readmessage);
  
  printf("Writing to pipe - Message 1 is %s\n", writemessages[3]);
   write(pipefds[1], writemessages[3], sizeof(writemessages[3]));
   read(pipefds[0], readmessage, sizeof(readmessage));
   printf("Reading from pipe – Message 1 is %s\n", readmessage);
   
   }
  
   return 0;
}
