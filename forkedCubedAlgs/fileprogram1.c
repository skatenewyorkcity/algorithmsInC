#include<stdio.h>
void filecopy(FILE *, FILE *);  /* function prototype */

int main()
{
FILE *fp;
        if ((fp = fopen("num.dat", "r")) == NULL)
          { printf("\tcannot open file\n\n" );
           return 1; }
        else {
           filecopy(fp, stdout);
           fclose(fp);
        }
return 0;
}

void filecopy(FILE *ifp, FILE *ofp)
{
   long int c[10], c_read[10], i = 0;
   while((fscanf(ifp, "%ld", c)) != EOF)   /* EOF = End Of File */ 
      {c_read[i] = *c;  
       printf("%ld\n\n", c_read[i]);
       ++i;}
return;
}
