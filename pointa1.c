//pointa.c

#include<stdio.h>

int main(int argc,char**argv){
  char x = 'a';
  char *y = &x;

  printf("x; %c,&x: %p\n",x,&x);
  printf("*y: %c,y: %p\n",*y,y);

  return 0;
}
