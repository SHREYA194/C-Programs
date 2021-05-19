#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
char str1[30];
void detect_tokens(FILE *fp);
void check(char str1[]);
void null(char str1[]);

void main() {
 FILE *fp;
 clrscr();
 fp = fopen("C:\\TURBOC3\\BIN\\shreya\\INPUT.c","r");
 detect_tokens(fp);
 fclose(fp);
 getch();
}

void detect_tokens(FILE *fp) {
 int n=0;
 char ch, str1[30];
 null(str1);
 /*for(j=0; j<strlen(str1); j++) {
  str1[j] = '\0';
 } */

 if(fp == NULL) {
  printf("File failed to open.");
 }

 else {
  while(1) {
   ch = fgetc(fp);

   if(ch == '"' || str1[0] == '"') {
    if(ch == '"')
	n++;
    strncat(str1, &ch, 1);
    if(n == 2) {
     printf("%s - String\n", str1);
     null(str1);
     /*for(j=0; j<strlen(str1); j++) {
      str1[j] = '\0';
     } */
     n=0;
    }
   }

   else {
   switch(ch) {
    case '(' :
	printf("%s() - Function\n", str1);
	null(str1);
	/*for(j=0; j<strlen(str1); j++) {
		str1[j] = '\0';
	} */
	break;

    case ')' :
	check(str1);
	null(str1);
	/*for(j=0; j<strlen(str1); j++) {
		str1[j] = '\0';
	} */
	break;

    case '=' :
	check(str1);
	printf("= - Assignment Operator\n");
	null(str1);
	break;

    case '{' :
	printf("{ - Function Begins\n");
	break;

    case '}' :
	printf("} - Function Ends\n");
	break;

    case ';' :
	check(str1);
	null(str1);
	/*for(j=0; j<strlen(str1); j++) {
		str1[j] = '\0';
	} */
	printf("; - Statement End\n");
	break;

    case ',' :
	check(str1);
	null(str1);
	/*for(j=0; j<strlen(str1); j++) {
		str1[j] = '\0';
	} */
	printf(", - Special Character\n");
	break;

    case ' ' :
	check(str1);
	null(str1);
	/*for(j=0; j<strlen(str1); j++) {
		str1[j] = '\0';
	} */
	break;

    case '\n' :
	break;

    default :
	strncat(str1, &ch, 1);
	break;
   }
   }
   if(ch == EOF)
	break;
  }
 }
}

void check(char str1[]) {
 int i=0, n=0;
 char ans[12];
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

 if(strlen(str1) > 0) {

 for(i=0; i<strlen(str1); i++) {
  if(str1[i] >= '0' && str1[i] <= '9') {
   n++;
  }
 }
 if(n == strlen(str1)) {
  printf("%s - Number\n", str1);
  goto break1;
 }


 for(i=0; i<34; i++) {
  if(strcmp(str1,operators[i]) == 0) {
   //strncat(ans, "Operator", 8);
   //strcpy(ans, "Operator");
   printf("%s - Operator\n", str1);
   goto break1;
  }
 }

 for(i=0; i<32; i++) {
  if(strcmp(str1, keywords[i]) == 0) {
   //strncat(ans, "Keyword", 7);
   //strcpy(ans, "Keyword");
   printf("%s - Keyword\n", str1);
   goto break1;
  }
 }

 if(str1[strlen(str1)-1] == '"') {
  //strncat(ans, "String", 6);
  //strcpy(ans, "String");
  printf("%s - String\n", str1);
 }
 else {
  printf("%s - Identifier\n", str1);
 }
 }
 break1:
}

void null(char str1[]) {
 int j=0;
 for(j=0; j<strlen(str1); j++) {
  str1[j] = '\0';
 }
}
