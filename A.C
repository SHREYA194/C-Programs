#include<stdio.h>
#include<conio.h>
void main()
{
int a[100],x,i,n;
clrscr();
printf("enter n:");
scanf("%d",&n);
printf("enter :");
for(i=0;i<n;i++)
{
 scanf("%d",&a[i]);
}
printf("enter x:");
scanf("%d",&x);
for(i=0;i<n;i++)
{
 if(a[i]>=x)
 {
  printf("\nyes");
 }
 else
 {
  printf("\nno");
 }
}
getch();
}
