#include <stdio.h>
#include <conio.h>

double knapsack(int n,int val[],int wei[],int knap);

void main() {
    int n,i,j,value[10],weight[10],knap;
    double vbyw[10],temp,tempv,tempw,ans;
    clrscr();

    printf("Enter number of objects : ");
    scanf("%d",&n);
    printf("Enter values of %d objects : ",n);
    for(i=0;i<n;i++) {
	scanf("%d ",&value[i]);
    }
    printf("Enter weights of %d objects : ",n);
    for(i=0;i<n;i++) {
	scanf("%d ",&weight[i]);
    }

    printf("v/w = ");
    for(i=0;i<n;i++) {
	vbyw[i] = value[i] / weight[i];
	printf("%f ",vbyw[i]);
    }

    printf("Enter maximum weight of knapsack : ");
    scanf("%d",&knap);

    for(i=0;i<n;i++) {
	for(j=i+1;j<n;j++) {
	    if(vbyw[i] > vbyw[j]) {
		temp = vbyw[i];
		vbyw[i] = vbyw[j];
		vbyw[j] = temp;

		tempv = value[i];
		value[i] = value[j];
		value[j] = tempv;

		tempw = weight[i];
		weight[i] = weight[j];
		weight[j] = tempw;
	    }
	    else {
		continue;
	    }
	}
    }

    ans = knapsack(n,value,weight,knap);
    printf("Answer of knapsack is : ",ans);

}

double knapsack(int num,int val[],int wei[],int knap) {
    int W=knap,weight=0,i;
    double x[10],answer;

    for(i=0;i<num;i++) {
	x[i] = 0;
    }

    i=0;
    while(weight<W) {
	if(weight+wei[i] <= W) {
	    x[i] = 1.0;
	    weight = weight + wei[i];
	}
	else {
	    x[i] = (W-weight)/wei[i];
	    weight = W;
	}
	i++;
    }

    for(i=0;i<num;i++) {
	answer = x[i] * val[i];
    }

    return answer;
}
