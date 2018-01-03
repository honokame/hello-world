// pointa5.c

#include<stdio.h>

int main(int argc,char**argv){

  int a = 5;
  int *p = &a;
    
  printf("*p = %d\t\t%p\n*(p+1) = %d\t%p\n*(p+2) = %d\t%p\n",*p,p,*p+1,p+1,*p+2,p+2);

  return 0;
}
  
