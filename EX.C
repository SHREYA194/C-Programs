#include<stdio.h>
#include<conio.h>
typedef struct node
{
 int info;
 struct node *link;
}head;
struct node* createlist(int);
struct node* displaylist();
void main()
{
 int n;
 printf("enter n:");
 scanf("%d",&n);
 head=createlist(n);
 displaylist();
 getch();
}
struct node* createlist(int n)
{
 int val,i;
 struct node *temp,*newnode;
 head=(struct node*)malloc(sizeof(struct node));
 printf("enter value of node1:");
 scanf("%d",&val);
 head->info=val;
 head->link=NULL;
 temp=head;
 for(i=2;i<=n;i++)
 {
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("enter val of node:");
  scanf("%d",&val);
  newnode->info=val;
  newnode->link=NULL;
  temp->link=newnode;
  temp=temp->link;
 }
 return head;
}
struct node *displaylist()
{
 struct node *temp;
 temp=head;
 while(temp->link!=head)
 {
  printf(" %d",temp->info);
  temp=temp->link;
 }
 printf(" %d",temp->info);
 return head;
}
