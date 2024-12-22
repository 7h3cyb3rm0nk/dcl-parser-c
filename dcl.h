#include <stdio.h>
#include <string.h>
#include <ctype.h>
#ifndef DCL
#define DCL

#define MAXTOKEN 100
enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);

int gettoken(void);
extern int tokentype;
extern char token[MAXTOKEN];
extern char name[MAXTOKEN];
extern char datatype[MAXTOKEN];
extern char out[1000];


#endif
