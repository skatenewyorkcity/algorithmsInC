#include<stdio.h>
int main()
{
  int c;
  FILE *fp;
  fp = fopen("numbers.dat", "r");
  while (fscanf(fp, "%d", &c) !=EOF)
    printf("%d\n", c);
  fclose(fp);
return 0;
}

