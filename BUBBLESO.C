#include<stdio.h>
#include<conio.h>
#include<time.h>

void main() {
 int i,j,n,arr[20] ,temp;
 time_t start,end;
 double tc;
 clrscr();

 printf(" Enter n:");
 scanf("%d",&n);
 printf(" Enter elements:");

 for(i=0;i<n;i++) {
  scanf("%d",&arr[i]);
 }

 start=clock();
 for(i=0;i<n-1;i++) {
  for(j=0;j<n-i-1;j++) {
   if(arr[j]>arr[j+1]) {
    temp=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=temp;
   }
  }
 }

 printf(" Sorted array : ");
 for(i=0;i<n;i++) {
  printf("%6d",arr[i]);
 }
 end=clock();

 tc=(difftime(end,start)/CLOCKS_PER_SEC);
 printf("\n Start time : %ld \n End time : %ld \n Clocks per second : %ld \n Time Complexity : %f",start,end,CLOCKS_PER_SEC,tc);
 getch();
}