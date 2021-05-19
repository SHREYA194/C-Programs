#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
 int info;
 struct node *link;
};
struct node *head;
struct node* createlist(int n);
struct node* displaylist();
struct node* insert_csll_front(struct node* first,int x);
struct node* insert_csll_last(struct node* first,int x);
struct node* insert_csll_befsp(struct node* first,int x,int y);
struct node* insert_csll_aftsp(struct node* first,int x,int y);
struct node* delet_csll_first(struct node* first);
struct node* delet_csll_last(struct node* first);
struct node* delet_csll_spe(struct node* first,int x);
struct node* delet_csll_bef(struct node* first,int x);
struct node* delet_csll_aft(struct node* first,int x);
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
 printf("1.insert at front \n2.insert at last \n3.insert before specific node \n4.insert after specific node.");
 printf("\nenter choice:");
 scanf("%d",&z);
 switch(z)
 {
  case 1:printf("enter p(new info):");
	 scanf("%d",&p);
	 head=insert_csll_front(head,p);
	 break;
  case 2:printf("enter p(new info):");
	 scanf("%d",&p);
	 head=insert_csll_last(head,p);
	 break;
  case 3:
	 printf("enter p(new info) and q(specific node):");
	 scanf("%d %d",&p,&q);
	 head=insert_csll_befsp(head,p,q);
       break;
  case 4:
	 printf("enter p(new info) and q(specific node):");
	 scanf("%d %d",&p,&q);
	 head=insert_csll_aftsp(head,p,q);
       break;
  default:
	 displaylist();
       break;
 }
 break;
 case 2:
 printf(" 1.delete first \n2.delete last \n3.delete specific \n4.delete before specific node \n5.delete after specific node.");
 printf("\nenter choice:");
 scanf("%d",&z);
 switch(z)
 {
  case 1: head=delet_csll_first(head);
	break;
  case 2: head=delet_csll_last(head);
	break;
  case 3:printf("enter value of specific node:");
	 scanf("%d",&p);
	 head=delet_csll_spe(head,p);
       break;
  case 4: printf("enter specific node value:");
	  scanf("%d",&p);
	  head=delet_csll_bef(head,p);
       break;
  case 5: printf("enter specific node value:");
	  scanf("%d",&p);
	  head=delet_csll_aft(head,p);
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
 printf("\n Circular List:");
 displaylist();
 getch();
}
struct node* createlist(int n)
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
  head->info=data;
  head->link=head;
  temp=head;
  for(i=2;i<=n;i++)
  {
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("enter data of new node:");
   scanf("%d",&data);
   newnode->info=data;
   newnode->link=head;
   temp->link=newnode;
   temp=temp->link;
  }
 }
 return head;
}
struct node* displaylist()
{
 struct node *temp;
 if(head==NULL)
 {
  printf("circular list is empty.");
 }
 else
 {
  temp=head;
  while(temp->link!=head)
  {
   printf(" %d ",temp->info);
   temp=temp->link;
  }
  printf(" %d",temp->info);
}
 return head;
}
struct node* insert_csll_front(struct node *first,int x)
{
 struct node *new1,*temp;
 new1=(struct node*)malloc(sizeof(struct node));
 new1->info=x;
 new1->link=NULL;
 temp=first;
 while(temp->link!=first)
 {
  temp=temp->link;
 }
 new1->link=first;
 temp->link=new1;
 first=new1;
   return first;
}
struct node* insert_csll_last(struct node *first,int x)
{
 struct node *new1,*temp;
 new1=(struct node*)malloc(sizeof(struct node));
 new1->info=x;
 new1->link=NULL;
 temp=first;
 while(temp->link!=head)
 {
  temp=temp->link;
 }
  temp->link=new1;
  new1->link=first;
  return first;
}
struct node* insert_csll_befsp(struct node *first,int x,int y)
{
 struct node *new1,*temp,*temp1;
 new1=(struct node*)malloc(sizeof(struct node));
 new1->info=x;
 new1->link=NULL;
 temp=first;
 temp1=first;
 while(temp->info!=y)
 {
  temp1=temp;
  temp=temp->link;
 }
 if(temp==NULL)
 {
  printf("node is not available.");
 }
 else if(temp==first)
 {
  insert_csll_front(head,x);
 }
 else
 {
  temp1->link=new1;
  new1->link=temp;
 }
return first;
}
struct node* insert_csll_aftsp(struct node *first,int x,int y)
{
 struct node *temp,*new1;
 new1=(struct node*)malloc(sizeof(struct node));
 new1->info=x;
 new1->link=NULL;
 temp=first;
 while(temp->info!=y)
 {
  temp=temp->link;
 }
 if(temp==NULL)
 {
  printf("node is not available.");
 }
 else
 {
   new1->link=temp->link;
   temp->link=new1;
 }
 return first;
}
struct node* delet_csll_first(struct node* first)
{
 struct node *temp;
 temp=first;
 if(temp==NULL)
  printf("link list is not available.");
 else
 {
  while(temp->link!=first)
  {
   temp=temp->link;
  }
  temp->link=first->link;
  first=first->link;
  return first;
 }
}
struct node *delet_csll_last(struct node* first)
{
 struct node *temp,*temp1;
 temp=first;
 if(temp==NULL)
 {
   printf("list is empty.");
 }
 else
 {
  while(temp->link!=first)
  {
   temp1=temp;
   temp=temp->link;
  }
  temp1->link=first;
 }
 return first;
}
struct node* delet_csll_spe(struct node* first,int x)
{
 struct node *temp,*temp1;
 temp=first;
 if(temp==NULL)
  printf("list is empty.");
 else
 {
  while(temp->info!=x)
  {
   temp1=temp;
   temp=temp->link;
  }
  if(temp==first)
  {
   temp1->link=first->link;
   first=first->link;
  }
   temp1->link=temp->link;
 }
 return first;
}
struct node* delet_csll_bef(struct node* first,int x)
{
 struct node *temp,*temp1,*temp2;
 temp=first;
 if(temp==NULL)
  printf("list is mpty.");
 else
 {
  while(temp->info!=x&&temp!=NULL)
  {
   temp2=temp1;
   temp1=temp;
   temp=temp->link;
  }
  if(temp1==first)
	first=temp;
  else
       temp2->link=temp;
 }
return first;
}

struct node* delet_csll_aft(struct node *first,int x)
{
 struct node *temp;
 temp=first;
 if(temp==NULL)
  printf("list is empty.");
 else
 {
  while(temp->info!=x&&temp!=NULL)
  {
   temp=temp->link;
  }
  temp->link=temp->link->link;
 }
 return first;
}










