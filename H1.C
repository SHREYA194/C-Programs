#include<stdio.h>
#include<conio.h>
void main()
{
 int l[10],c[10],i,n,p=0,j;
 clrscr();
 printf("enter number of check points:");
 scanf("%d",&n);
 printf("\n enter rates:");
 for(i=0;i<n;i++)
 {
  scanf("%d",&c[i]);
  for(j=i+1;j<=i+1;j++)
  {
   l[i]=j;
    p=p+c[i]*l[i];
  }
 }
 printf("\n  cost:%d",p);
getch();
}



