#include<stdio.h>
#include<conio.h>
void main()
{
 int i,k,j,z;
 clrscr();
  printf("\n entre row:");
  scanf("%d",&z);
  for(i=1;i<=z;i++)
  {
   for(k=1;k<=i;k++)
   {
    printf("*");
   }
   for(j=0;j<(2*z-2*i);j++)
   {
    printf("#");
   }
   for(k=1;k<z-i;k++)
   {
    printf("*");
   }
   printf("\n");
  }
 getch();
}
