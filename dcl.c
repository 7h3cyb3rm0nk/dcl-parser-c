#include "dcl.h"
#include "getch.h"


int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];


int gettoken(void){
  int c;
  char *p = token;

  while((c = getch()) == ' ' || c == '\t')
    ;
  if(c == '(') {
    if ((c = getch()) == ')'){
      strcpy(token, "()");
      return tokentype = PARENS;
    }else{
      ungetch(c);
      return tokentype = '(';
    }
  }
  else if(c == '[') {
   for(*p++ = c; (*p++ = getch()) != ']'; );
    *p = '\0';
    return tokentype = BRACKETS;
  }
  else if(isalpha(c)) {
    for(*p++ = c; isalnum(c = getch());)
      *p++ = c;
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;

  }
  else {
    return tokentype = c;
   }
}


void dcl(void) {
  int ns;
  for(ns=0; gettoken() == '*';)
    ns++;
  dirdcl();
  while(ns-- > 0)
    strcat(out, " pointer to");

}

void dirdcl(void) {
  int type;

  if(tokentype == '('){
    dcl();
    if(tokentype != ')')
      printf("error: missing )\n");
    
  }else if(tokentype == NAME)
    strcpy(name, token);
  else 
    printf("error: expected name or (dcl)\n");
  while((type=gettoken()) == PARENS || type == BRACKETS)
   if(type == PARENS)
    strcat(out, " function returning");
   else{
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
  
}
