struct node* insert_sll_spec(struct node* first,int x,int y);
 case 3:printf("enter p(new info) and q(specific node):");
	 scanf("%d %d",&p,&q);
	 head=insert_sll_spec(head,p,q);
	 break;
struct node* insert_sll_spec(struct node *first,int x,int y)
{
 struct node *new1,*temp,*pred;
 new1=(struct node*)malloc(sizeof(struct node));
 new1->info=x;
 new1->link=NULL;
 temp=first;
 while(temp->info!=y)
 {
  pred=temp;
  temp=temp->link;
 }
  pred->link=new1;
  new1->link=temp;
 return first;
}