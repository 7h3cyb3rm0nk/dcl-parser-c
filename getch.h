#include <stdio.h>
#include <string.h>
#include <ctype.h>

#ifndef GETCH
#define GETCH
extern char buf[100];
extern int bufp;

int getch(void);
void ungetch(int);


#endif

