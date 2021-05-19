#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void detect_tokens(FILE *fp);

void main() {
 FILE *fp;
 clrscr();
 fp = fopen("C:\\TURBOC3\\BIN\\shreya\\INPUT.c","r");
 detect_tokens(fp);
 fclose(fp);
 getch();
}

void detect_tokens(FILE *fp) {
 int i=0, j=0;
 char ch, p, str1[20];
 char keywords[32][10] = {"auto", "break", "case", "char", "continue", "do",
		      "default", "const", "double", "else", "enum", "extern",
		      "for", "if", "goto", "float", "int","long", "register",
		      "return", "signed", "static", "sizeof", "short",
		      "struct", "switch", "typedef", "union", "void", "while",
		      "volatile", "unsigned"};

 char operators[34][10] = {"+", "-", "*", "/", "%", "++", "--", "==", "!=",
			">", "<", ">=", "<=", "&&", "||", "!", "&", "|", "^", "~",
			"<<", ">>", "=", "+=", "-=", "*=", "/=", "%=", "<<="
			">>=", "&=", "^=", "|=", "sizeof()", "?:"};

 //char special_characters[20][3] = {",", };

 for(j=0; j<strlen(str1); j++) {
  str1[i] = '\0';
 }

 if(fp == NULL) {
  printf("File failed to open.");
 }
 else {
  while(1) {
   ch = fgetc(fp);

   //if(ch>=32 && ch<=47 || ch>=58 && ch<=64 || ch>=91 && ch<=96 ||
   //    ch>=123 && ch<=126) {
   // printf("%c - Special character\n", ch);
   // ch = ' ';
  // }

   if(ch == ')') {
    ch = ' ';
   }

   else if(ch == '{') {
    printf("{ - Function Begins\n");
    ch = ' ';
   }

   else if(ch == '}') {
    printf("} - Function Ends\n");
    ch = ' ';
   }

   else if(ch == ';') {
    printf("; - Statement End\n");
    ch = ' ';
   }
   else if(ch == ',' || ch == ':') {
    printf("%c - Special Character\n", ch);
    ch = ' ';
   }

   else if(isspace(ch) == 0 && ch != EOF && p != ' ') {
    strncat(str1, &ch, 1);
   }

   else {
    int size = strlen(str1);
    //int x = atoi(str1);
    //printf("%d - Number\n", x);
    if(size == 0)
	continue;

    if(str1[size-1] == ')') {
     printf("%s) - Function\n", str1);
     goto break1;
    }

    else {
     for(j=0; j<32; j++) {
      if(strcmp(keywords[j], str1) == 0) {
       printf("%s - Keyword\n", str1);
       goto break1;
      }
     }

     for(j=0; j<34; j++) {
      if(strcmp(operators[j], str1) == 0) {
       printf("%s - Operator\n", str1);
       goto break1;
      }
     }

     if(str1[size-1] == '"')
      printf("%s - String\n", str1);

     //if(isdigit(str1) == 1)
      //printf("%s - Number\n", str1);

      printf("%s - Identifier\n", str1);

    }

    break1 :
    for(j=0; j<size; j++) {
     str1[j] = '\0';
    }
    i=0;
   }
   if(ch == EOF)
	break;
  }
 }
}