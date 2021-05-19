#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
 struct node *prev;
 int info;
 struct node *link;
};
struct node *head;
void createlist(int n);
void displaylist();
struct node* insert_cdll_front(struct node* first,int x);
struct node* insert_cdll_last(struct node* first,int x);
struct node* delet_first(struct node* first);
struct node* delet_last(struct node* first);
void main()
{
 int n,p,q,a,z;
 char ans;
 clrscr();
 printf("enter number of node:");
 scanf("%d",&n);
 createlist(n);
do
{
 printf("\n1.insertion \n 2.deletion \nenter your choice:");
 scanf("\n%d",&a);
 switch(a)
 {
 case 1:
 printf("1.insert at front \n2.insert at last");
 printf("\nenter choice:");
 scanf("%d",&z);
 switch(z)
 {
  case 1:printf("enter p(new info):");
	 scanf("%d",&p);
	 head=insert_cdll_front(head,p);
	 break;
  case 2:printf("enter p(new info):");
	 scanf("%d",&p);
	 head=insert_cdll_last(head,p);
	 break;
  default:
	 displaylist();
       break;
 }
 break;
 case 2:
 printf(" 1.delete first \n2.delete last");
 printf("\nenter choice:");
 scanf("%d",&z);
 switch(z)
 {
  case 1: head=delet_first(head);
	break;
  case 2: head=delet_last(head);
	break;
  default:
	  displaylist();
       break;
 }
 break;
}
 printf("\ndo you want to continue? ");
 ans=getche();
}while(ans=='y'||ans=='Y');
 printf("\n Circular Doubly List:");
 displaylist();
 getch();
}
void createlist(int n)
{
 struct node *temp,*newnode;
 int data,i;
 if(n==0)
     return NULL;
 else
 {
  head=(struct node*)malloc(sizeof(struct node));
  printf("enter value of node1:");
  scanf("%d",&data);
  head->prev=NULL;
  head->info=data;
  head->link=NULL;
  temp=head;
  for(i=2;i<=n;i++)
  {
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("enter data of new node:");
   scanf("%d",&data);
   newnode->info=data;
   newnode->link=head;
   temp->link=newnode;
   newnode->prev=temp;
   temp=temp->link;
  }
 }
}
void displaylist()
{
 struct node *temp;
 if(head==NULL)
 {
   printf("list is empty.");
 }
 else
 {
  temp=head;
  while(temp->link!=head)
  {
   printf(" %d ",temp->info);
   temp=temp->link;
  }
}
}
struct node* insert_cdll_front(struct node *first,int x)
{
 struct node *new1,*temp;
 new1=(struct node*)malloc(sizeof(struct node));
 new1->prev=NULL;
 new1->info=x;
 new1->link=NULL;
 temp=first;
 new1->link=temp;
 temp->prev=new1;
 temp=new1;
 return temp;

}
struct node* insert_cdll_last(struct node *first,int x)
{
 struct node *new1,*temp;
 new1=(struct node*)malloc(sizeof(struct node));
 new1->prev=NULL;
 new1->info=x;
 new1->link=NULL;
 temp=first;
 while(temp->link!=NULL)
 {
  temp=temp->link;
 }
 if(first==NULL)
 {
   first=new1;
 }
 else
 {
  temp->link=new1;
  new1->prev=temp;
 }
  return first;
}
struct node* delet_first(struct node* first)
{
 struct node *temp;
 temp=first;
 if(temp==NULL)
  printf("link list is not available.");
 else
 {
  first=temp->link;
  first->prev=NULL;
  return first;
 }
}
struct node *delet_last(struct node* first)
{
 struct node *temp;
 temp=first;
 if(temp==NULL)
    printf("list is empty.");
 else
 {
  while(temp->link!=NULL)
  {
   temp=temp->link;
  }
  if(temp==first)
      first=NULL;
  else
      temp->prev->link=NULL;
 }
 return first;
}