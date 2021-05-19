#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
 int info;
 struct node *link;
};
struct node *head;
void createlist(int n);
void displaylist();
struct node* insert_sll_fron(struct node* first,int x);
struct node* insert_sll_last(struct node* first,int x);
struct node* insert_ase(struct node* first,int x);
struct node* delet_first(struct node* first);
struct node* delet_bef(struct node* first,int x);
struct node* delet_aft(struct node* first,int x);
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
 printf("1.1 insert front \n1.2 insert last \n1.3 insert in asending list \n2.1 delete first \n2.2 delete before specific \n2.3 delete after specific");
 printf("1.insertion \n 2.deletion \nenter your choice:");
 scanf("\n%d",&a);
 switch(a)
 {
 case 1: printf("enter choice:");
	 scanf("%d",&z);
 switch(z)
 {
  case 1:printf("enter p(new info):");
	 scanf("%d",&p);
	 head=insert_sll_fron(head,p);
	 break;
  case 2:printf("enter p(new info):");
	 scanf("%d",&p);
	 head=insert_sll_last(head,p);
	 break;
  case 3:printf("enter p(new info):");
	 scanf("%d",&p);
	 head=insert_ase(head,p);
	 break;
  default:
	printf("enter valid choice.");
	break;
 }
 break;
 case 2: printf("enter choice:");
	 scanf("%d",&z);
 switch(z)
 {
  case 1: head=delet_first(head);
	break;
  case 2: printf("enter specific node value:");
	  scanf("%d",&p);
	  head=delet_bef(head,p);
       break;
  case 3: printf("enter specific node value:");
	  scanf("%d",&p);
	  head=delet_aft(head,p);
       break;
 }
 break;
}
 printf("do you want to continue.");
 ans=getche();
}while(ans=='y'||ans=='Y');
 displaylist();
 getch();
}
void createlist(int n)
{
 struct node *temp,*newnode;
 int data,i;
 head=(struct node*)malloc(sizeof(struct node));
 printf("enter value of node1:");
 scanf("%d",&data);
 head->info=data;
 head->link=NULL;
 temp=head;
 for(i=2;i<=n;i++)
 {
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("enter data of new node:");
  scanf("%d",&data);
  newnode->info=data;
  newnode->link=NULL;
  temp->link=newnode;
  temp=temp->link;
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
  while(temp!=NULL)
  {
   printf(" list=%d ",temp->info);
   temp=temp->link;
  }
}
}
struct node* insert_sll_fron(struct node *first,int x)
{
 struct node *new1,*temp;
 new1=(struct node*)malloc(sizeof(struct node));
 new1->info=x;
 new1->link=NULL;
 temp=first;
 new1->link=temp;
 temp=new1;
 return temp;

}
struct node* insert_sll_last(struct node *first,int x)
{
 struct node *new1,*temp;
 new1=(struct node*)malloc(sizeof(struct node));
 new1->info=x;
 new1->link=NULL;
 temp=first;
 while(temp->link!=NULL)
 {
  temp=temp->link;
 }
 if(temp==NULL)
  printf("list is not available.");
 else
 {
  temp->link=new1;
  new1->link=NULL;
 }
 return first;
}
struct node* insert_ase(struct node* first,int x)
{
 struct node *temp,*new1,*temp1;
 new1=(struct node*)malloc(sizeof(struct node));
 new1->info=x;
 new1->link=NULL;
 temp=first;
 temp1=first;
 if(temp==NULL)
     first=new1;
 else
 {
  while(temp->info<x)
  {
   temp1=temp;
   temp=temp->link;
  }
  temp1->link=new1;
  new1->link=temp;
  return first;
 }
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
  return first;
 }
}
struct node* delet_bef(struct node* first,int x)
{
 struct node *temp,*temp1,*temp2;
 temp=first;
 if(temp==NULL)
  printf("list is mpty.");
 else
 {
  while(temp->info!=x)
  {
   temp2=temp1;
   temp1=temp;
   temp=temp->link;
  }
  temp2->link=temp;
 }
return first;
}

struct node* delet_aft(struct node *first,int x)
{
 struct node *temp;
 temp=first;
 if(temp==NULL)
  printf("list is empty.");
 else
 {
  while(temp->info!=x)
  {
   temp=temp->link;
  }
  temp->link=temp->link->link;
 }
 return first;
}







