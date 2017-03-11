#include<stdio.h>
int main()
{
  int c;
  FILE *fp, *ofp;
  ofp = fopen("/Users/lou/courses/CS451/numbers.out", "w");
  fp = fopen("/Users/lou/courses/CS451/numbers.dat", "r");
  while (fscanf(fp, "%d", &c) !=EOF)
    fprintf(ofp, "%d\n", c);
  fclose(fp);
  fclose(ofp);
return 0;
}

