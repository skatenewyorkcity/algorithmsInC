#include<time.h>
#include<sys/file.h>
#include<stdio.h>
#define NUM 5

 void print_msg(char *);  /*function prototype*/

int  main()
{
     print_msg("hello world ");
     return 0; 
}

void print_msg(char *m)
{
     long int i, j;
     double x,y,z;
     x = clock();
     for(i=0; i < NUM; i++)
       { printf("%s", m);
         fflush(stdout); /*flush the output buffer to the standard output device*/
         for(j = 0; j < 1000000000; ++j); /*just to slow it down*/       

       }
     y =clock();
     z = (y - x)/CLOCKS_PER_SEC;

     printf("\n\n\tThe execution time was: %.15f",z);
	 printf("\n\n");
	 return;
}

