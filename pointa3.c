// pointa3.c

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(int argc,char**argv){
  int i;
  int int_a[5] = {};
  int *a;
  double double_b[5] = {};
  double *b;
  char char_c[5] = {};
  char *c;
  short short_d[5] = {};
  short *d;
  float float_e[5] = {};
  float *e;
  long double long_double_f[5] = {};
  long double *f;

  srand((unsigned int)time(NULL));

  for(i = 0;i < 5;i++){
    int_a[i] = rand();
    double_b[i] = (rand() % 9999999) / 10000.0;
    char_c[i] = rand() % 127;                               
    short_d[i] = rand() % 32767;
    float_e[i] = (rand() % 99) / 1000.0;
    long_double_f[i] = (rand() % 9999999999) / 10000.0;
  }

  a = int_a;
  b = double_b;
  c = char_c;
  d = short_d;
  e = float_e;
  f = long_double_f;

  printf("int\n");

  for(i = 0;i < 5;i++){
    printf("a[%d] = %d\t%p\n",i,*a,a);
    a++;
  }

  printf("\ndouble\n");

  for(i = 0;i < 5;i++){
    printf("b[%d] = %f\t%p\n",i,*b,b);
    b++;
  }

  printf("\nchar\n");

  for(i = 0;i < 5;i++){
    printf("c[%d] = %c\t\t%p\n",i,*c,c);
    c++;
  } 
  
  printf("\nshort\n");

  for(i = 0;i < 5;i++){
    printf("d[%d] = %d\t\t%p\n",i,*d,d);
    d++;
  } 
  
  printf("\nfloat\n");

  for(i = 0;i < 5;i++){
    printf("e[%d] = %f\t\t%p\n",i,*e,e);
    e++;
  } 
  
  printf("\nlong double\n");

  for(i = 0;i < 5;i++){
    printf("f[%d] = %LF\t%p\n",i,*f,f); 
    f++;
  }

  printf("\n");

  return 0;
 
}
