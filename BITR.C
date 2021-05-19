#include<stdio.h>
#include<conio.h>
typedef struct node
{
 int data;
 struct node *left,*right;
}*node;
struct node *insert(struct node*,int);
void inorder(struct node*);
void main()
{
 struct node *root;
 int n,x,y,i;
 clrscr();
 printf("enter number of nodes:");
 scanf("%d",&n);
 printf("\nenter data:");
 for(i=0;i<n;i++)
 {
  scanf("%d",&x);
  root=insert(root,x);
 }
 getch();
}
struct node *insert(struct node *r,int info)
{
 if(r==NULL)
 {
  r=(struct node*)malloc(sizeof(struct node));
  r->data=info;
  r->left=r->right=NULL;
 }
 else if(info<r->data)
	r->left=insert(r->left,info);
 else if(info>r->data)
	r->right=insert(r->right,info);
 else if(info==r->data)
 {
  printf("error!");
  exit(0);
 }
 return r;
}
