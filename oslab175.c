#include <stdio.h>
#include<unistd.h>

int main()
{
  int pipefds[2];
  int returnstatus;
  int pid;
  char writemsge[2][20]={"HI","Hello"};
  char readmsge[20];
  returnstatus =pipe(pipefds);
  
  if (returnstatus==-1)
  {
    printf("Unable to create pipe\n");
    return 1;
  }
  pid=fork();

  //child process
  if(pid>0)
  {
    read(pipefds[0],readmsge,sizeof(readmsge));
    printf("Child process -Reading from pipe-Message1 is %s\n",readmsge);
   
    read(pipefds[0],readmsge,sizeof(readmsge));
    printf("Child process - Reading from pipe-Message2 is %s\n",readmsge);
  }
  else
  //parent process 
  {
    printf("Parent process -writing to pipe -Message1 is %s\n",writemsge[0]);
    write(pipefds[1],writemsge[0],sizeof(writemsge[0]));
    printf("Parent process -Writing to pipe - Message2  is %s\n",writemsge[1]);
    write(pipefds[1],writemsge[1],sizeof(writemsge[1]));
  }
  return 0;
}
