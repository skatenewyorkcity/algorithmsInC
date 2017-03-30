#include<stdio.h>
#include<time.h>
#include<sys/file.h>

/*V*/
#include<unistd.h>
#include<stdlib.h>
/*A*/

long int count (long int *a); /* function prototype */

/*V*/

long int count2 (long int *a); /* function prototype */

/*A*/

int main()
{

/*V*/

int pid;
int state;

/*A*/

  long int arr[2300], i = 0;

  FILE *fp;
  fp = fopen("numbers.dat", "r");

  while(i < 2300)
  {
    fscanf(fp, "%ld", arr);
    arr[i] = *arr;
    ++i;
  }

/*V*/

pid = fork();	/* child process created */

if (pid == 0)     /*begin the child*/
    { printf("Child says my pid = %d and my parent's pid = %d\n", getpid(), getppid());

  printf("%ld\n", count2(&arr[0])); 

      _exit(0);     /*child process ends*/
    }

/*A*/

/*V*/

  /* Now back to the parent code */
  if (pid < 0)
    { fprintf(stderr, "\tfork failed\n\n");
      exit(1);
    }

  /*V*/
 
  else{

  printf("Parent process invoked & child process invoked.\nWaiting for child process to finish...\n\n");

  printf("%ld\n", count(&arr[0]));

  }

  /*A*/


  printf("Parent says child pid = %d\n", pid);

  wait(&state);     /* wait for the child process to end */
  printf("The state value is: %d\n ", state);

/*A*/

  fclose(fp);

return 0;
}

long int count2 (long int *a)
{ int N = 2300; 
  int counting = 0;

  double x, y, z;
  x = clock();

/*V*/

  FILE *fpp;
  fpp = fopen("fPrintNumbers.dat", "w");

/*A*/

  int i;
  for ( i = 0; i < N; ++i)
   { 
      int j;
      for ( j = i+1; j < N; ++j)
      { 
        int k;
        for ( k = j+1; k < N; ++k)
        {
          if ((a[i]+a[j]+a[k]) == 0)
          { 
            /*printf("%ld %ld %ld \n", a[i], a[j], a[k]);*/
 
            /*V*/

            fprintf(fpp,"%ld %ld %ld \n", a[i], a[j], a[k]);          

            /*A*/
	
            counting++;
          }
        }
      } 
   }

  /*V*/

  fclose(fpp);

  printf("\nChild process finished, values printed to 'fPrintNumbers.dat'");

  /*A*/

   /*return counting;*/

   y = clock();
   z = (y - x)/CLOCKS_PER_SEC; 
   printf("\n\nChild process execution time (in seconds) was: %f", z);

   return counting;
}

long int count (long int *a)
{ int N = 1300;
  int counting = 0;

  double x, y, z;
  x = clock();

  int i;
  for ( i = 0; i < N; ++i)
   {
      int j;
      for ( j = i+1; j < N; ++j)
      {
        int k;
        for ( k = j+1; k < N; ++k)
        {
          if ((a[i]+a[j]+a[k]) == 0)
          {
            printf("%d %d %d \n", a[i], a[j], a[k]);
            counting++;
          }
        }
      }
   }
   /*return counting;*/

   y = clock();
   z = (y - x)/CLOCKS_PER_SEC;
   printf("\n\nParent process execution time (in seconds) was: %f", z);

   return counting;
}

