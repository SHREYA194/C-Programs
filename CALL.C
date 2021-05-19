#include<stdio.h>
#include<conio.h>
void swapval(int n1,int n2);
void swapref(int *m1,int *m2);
void main()
{
 int n1,n2,*m1,*m2;
 clrscr();
 printf("enter values n1,n2:");
 scanf("%d %d",&n1,&n2);
 swapval(n1,n2);
 printf("\nenter values of *m1,*m2:");
 scanf("%d %d",m1,m2);
 swapref(m1,m2);
 getch();
}
void swapval(int n1,int n2)
{
 int temp;
 temp=n1;
 n1=n2;
 n2=temp;
 printf("\n swap n1: %d\n swap n2:%d",n1,n2);
}
void swapref(int *m1,int*m2)
{
int *temp;
temp=m1;
m1=m2;
m2=temp;
printf("\n values after swapping \nm1:%d \nm2:%d",*m1,*m2);
}


