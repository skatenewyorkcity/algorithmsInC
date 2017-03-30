#include<stdio.h>
void filecopy(FILE *, FILE *);  /* function prototype */

int main()
{
FILE *fp;
        if ((fp = fopen("numbers.dat", "r")) == NULL)
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
   char c;
   while((c = getc(ifp)) != EOF)   /* EOF = End Of File */ 
      putc(c, ofp);                /* putc is a put character function */ 
return;
}
