#include<stdio.h>
#include<conio.h>
#define max 3
int insert(int);
int delet(int);
int display(int);
int cique_arr[max];
int front=-1;
int rear=-1;
void main()
{
 int n,a;
 clrscr();
 do
 {
  printf("\n1.insert	2.delete	3.display	4.exit");
  printf("\nenter choice:");
  scanf("%d",&n);
  switch(n)
  {
   case 1:printf("\nenter element to be insert:");
	  scanf("%d",&a);
	  rear=insert(a);
	   break;
   case 2:front=delet(front);
	  break;
   case 3:front=display(front);
	  break;
  }
 }while(n!=4);
getch();
}
int insert(int x)
{
 if((front==0)&&(rear==max-1))
	printf("circular queue overflow.");
 else if(rear==-1&&front==-1)
 {
  rear=front=0;
  cique_arr[rear]=x;
 }
 else if(rear==max-1&&front!=0)
 {
  rear=0;
  cique_arr[rear]=x;
 }
 else
 {
  rear++;
  cique_arr[rear]=x;
 }
 return rear;
}
int delet(int front)
{
 int val;
 if(front==-1&&rear==-1)
 {
   printf("\nqueue underflow.");
 }
  val=cique_arr[front];
  printf("\ndeleted element=%d",val);
  if(front==rear)
  {
     front=rear=-1;
  }
  else
  {
   if(front==max-1)
       front=0;
   else
       front++;
  }
 return front;
}
int display(int front)
{
 int i;
 if(front==-1&&rear==-1)
	printf("circular queue is underflow.");
 else
 {
  printf("Circular queue:");
  if(front<rear)
  {
   for(i=front;i<=rear;i++)
	printf(" %d",cique_arr[i]);
  }
  else
  {
   for(i=front;i<=max-1;i++)
	printf(" %d",cique_arr[i]);
   for(i=rear;i<front;i++)
	printf(" %d",cique_arr[i]);
  }
}
return front;
}






