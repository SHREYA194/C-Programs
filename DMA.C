#include<stdio.h>
#include<conio.h>
void main()
{
 int *n1,*n2,*add;
 clrscr();
 n1=(int *)malloc(sizeof(int));
 n2=(int *)malloc(sizeof(int));
 printf("enter values of n1 and n2:");
 scanf("%d %d",n1,n2);
 *add=*n1+*n2;
 printf("\n sum=%d",*add);
 free(n1);
 free(n2);
 getch();
}
