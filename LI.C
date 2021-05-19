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
struct node* insert_sll_front(struct node* first,int x);
struct node* insert_sll_last(struct node* first,int x);
struct node* insert_sll_befsp(struct node* first,int x,int y);
struct node* insert_sll_aftsp(struct node* first,int x,int y);
struct node* delet_first(struct node* first);
struct node* delet_last(struct node* first);
struct node* delet_spe(struct node* first,int x);
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
	 head=insert_sll_front(head,p);
	 break;
  case 2:printf("enter p(new info):");
	 scanf("%d",&p);
	 head=insert_sll_last(head,p);
	 break;
  case 3:
	 printf("enter p(new info) and q(specific node):");
	 scanf("%d %d",&p,&q);
	 head=insert_sll_befsp(head,p,q);
       break;
  case 4:
	 printf("enter p(new info) and q(specific node):");
	 scanf("%d %d",&p,&q);
	 head=insert_sll_aftsp(head,p,q);
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
  case 1: head=delet_first(head);
	break;
  case 2: head=delet_last(head);
	break;
  case 3:printf("enter value of specific node:");
	 scanf("%d",&p);
	 head=delet_spe(head,p);
       break;
  case 4: printf("enter specific node value:");
	  scanf("%d",&p);
	  head=delet_bef(head,p);
       break;
  case 5: printf("enter specific node value:");
	  scanf("%d",&p);
	  head=delet_aft(head,p);
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
 printf("\n List:");
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
   printf(" %d ",temp->info);
   temp=temp->link;
  }
}
}
struct node* insert_sll_front(struct node *first,int x)
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
struct node* insert_sll_befsp(struct node *first,int x,int y)
{
 struct node *new1,*pred,*temp;
 new1=(struct node*)malloc(sizeof(struct node));
 new1->info=x;
 new1->link=NULL;
 temp=first;
 while(temp->info!=y&&temp!=NULL)
 {
  pred=temp;
  temp=temp->link;
 }
 if(temp==NULL)
 {
  printf("node is not available.");
 }
 else if(temp==first)
 {
  new1->link=first;
  first=new1;
 }
 else
 {
  pred->link=new1;
  new1->link=temp;
 }
return first;
}
struct node* insert_sll_aftsp(struct node *first,int x,int y)
{
 struct node *temp,*new1;
 new1=(struct node*)malloc(sizeof(struct node));
 new1->info=x;
 temp=first;
 while(temp->info!=y&&temp!=NULL)
 {
  temp=temp->link;
 }
 if(temp==NULL)
 {
  return first;
 }
 else
 {
   new1->link=temp->link;
   temp->link=new1;
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
  while(temp->link->link!=NULL)
  {
   temp=temp->link;
  }
  if(temp==first)
      first=NULL;
  temp->link=NULL;
 }
 return first;
}
struct node* delet_spe(struct node* first,int x)
{
 struct node *temp,*temp1;
 temp=first;
 if(temp==NULL)
   printf("list is empty.");
 else
 {
  while(temp->info!=x&&temp!=NULL)
  {
   temp1=temp;
   temp=temp->link;
  }
  if(temp==first)
       first=NULL;
  temp1->link=temp->link;
 }
 return first;
}
struct node* delet_bef(struct node* first,int x)
{
 struct node *temp,*temp1,*temp2;
 temp=first;
 if(temp==NULL)
  printf("list is empty.");
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

struct node* delet_aft(struct node *first,int x)
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










