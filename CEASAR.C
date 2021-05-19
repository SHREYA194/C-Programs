#include<stdio.h>
#include<conio.h>

void main() {
 int key, i;
 char pl[20], cp[20];
 clrscr();

 printf(" Enter key : ");
 scanf("%d", &key);
 printf("\n Enter Plain Text : ");
 scanf("%s", pl);
 for(i=0; i<strlen(pl); i++) {
  strncat(cp[i], pl[i], 1);
 }
 printf("\n Cipher Text : %s ", cp);
}