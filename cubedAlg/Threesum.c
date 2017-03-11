#include<stdio.h>
#include<time.h>
#include<sys/file.h>

long int count (long int *a); /* function prototype */

int main()
{

  long int arr[1300], i = 0;

  FILE *fp;
  fp = fopen("numbers.dat", "r");

  while(i < 1300)
  {
    fscanf(fp, "%ld", arr);
    arr[i] = *arr;
    ++i;
  }

  printf("%ld\n", count(&arr[0])); 
  
  fclose(fp);

return 0;
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
   printf("\n\nThe execution time was: %f", z);

   return counting;
}
