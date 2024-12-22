#include "getch.h"


char buf[100];

int bufp;

int getch(void){
  return bufp > 0?buf[--bufp]:getchar();
}

void ungetch(int c){
  if(bufp >= 100)
    printf("error: too many characters in buffer");
  else
    buf[bufp++] = c;
}
