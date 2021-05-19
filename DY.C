#include <stdio.h>
#include <conio.h>
#include <limits.h>

void make_a_change_dynamic(int num,int d[],int rate);
int min(int x,int y);

void main()
{
    int num, rate, i=0;
    int d[4];
    clrscr();
    printf("Enter total number of distinct coins : ");
    scanf("%d",&num);
    printf("Enter rates of the coins : ");
    for(i=1;i<=num;i++) {
	scanf("%d",&d[i]);
    }

    printf("Enter rate that you want to make a change above coins : ");
    scanf("%d",&rate);

    make_a_change_dynamic(num,d,rate);

}

void make_a_change_dynamic(int num,int d[],int rate) {
    int c[10][10], i=0, j=0;
    for(i=1;i<=num;i++)
	c[i][0]=0;
    for(i=1;i<=num;i++) {
	for(j=1;j<=rate;j++) {
	    if(i==1 && (j<d[i]))
		c[i][j] = INT_MAX;
	    else if(i==1)
		c[i][j] = (1 + (c[1][j-d[1]]));
	    else if(j<d[i])
		c[i][j] = (c[i-1][j]);
	    else
		c[i][j] = min(c[i-1][j], 1 + c[i][j-d[i]]);
	}
    }
    for(i=1;i<=num;i++) {
	for(j=0;j<=rate;j++) {
	    printf("%d ",c[i][j]);
	}
	printf("\n");
    }
}

int min(int x,int y) {
    if(x<=y)
	return x;
    else
	return y;
}
