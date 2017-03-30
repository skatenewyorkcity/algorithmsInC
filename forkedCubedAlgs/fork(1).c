#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

main()
{ 
  int pid;
  int state;
 
  pid = fork();     /* child process created */

 
  if (pid == 0)     /*begin the child*/
    { printf("Child says my pid = %d and my parent's pid = %d\n", getpid(), getppid());

      _exit(0);     /*child process ends*/   
    }

  /* Now back to the parent code */
  if (pid < 0)
    { fprintf(stderr, "\tfork failed\n\n");
      exit(1);
    }

  printf("Parent says child pid = %d\n", pid);

  wait(&state);     /* wait for the child process to end */
  printf("The state value is: %d\n ", state);

  return;
}
