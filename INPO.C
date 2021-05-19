#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 50
char st[max];
int top=-1;
void push(char st[],char);
char pop(char st[]);
int getpriority(char);
void infixtopostfix(char source[],char target[]);
void   main()
{
 char infix[50],postfix[50];
 clrscr();
 printf("enter infix expression:");
 gets(infix);
 strcpy(postfix," ");
 infixtopostfix(infix,postfix);
 printf("\ncorresponding postfix expression:");
 puts(postfix);
 getch();
}
void infixtopostfix(char source[],char target[])
{
 int i=0,j=0;
 char temp;
 strcpy(target,"");
 while(source[i]!='\0')
 {
  if(source[i]=='(')
  {
   push(st,source[i]);
   i++;
  }
  else if(source[i]==')')
  {
   while((top!=1)&&(st[top]!='('))
   {
    target[j]=pop(st);
    j++;
   }
   if(top==-1)
   {
    printf("\nIncorrect expression");
    exit(1);
   }
   temp=pop(st);
   i++;
  }
  else if(isdigit(source[i])||isalpha(source[i]))
  {
   target[j]=source[i];
   j++;
   i++;
  }
  else if(source[i]=='+'||source[i]=='-'||source[i]=='*'||source[i]=='/'||source[i]=='%')
  {
   while((top!=-1)&&(st[top]!='(')&&(getpriority(st[top])>getpriority(source[i])))
   {
     target[j]=pop(st);
    j++;
   }
   push(st,source[i]);
   i++;
  }
  else
   {
    printf("\nIncorrect element in expression.");
    exit(1);
   }
  }
   while((top!=-1)&&(st[top]!='('))
   {
    target[j]=pop(st);
    j++;
   }
   target[j]='\0';
 }
  int getpriority(char op)
  {
   if(op=='/'||op=='*'||op=='%')
	return 1;
   else if(op=='+'||op=='-')
	return 0;
  }
  void push(char st[],char val)
  {
   if(top==max-1)
	printf("\nstack overflow");
   else
   {
    top++;
    st[top]=val;
   }
  }
  char pop(char st[])
  {
   char val=' ';
   if(top==-1)
	printf("\nstack underflow");
   else
   {
    val=st[top];
    top--;
   }
   return val;
  }
