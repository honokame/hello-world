// filewrite.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char**argv)
{
  FILE *fp;
  int a,b;
  
  a = 355;
  b = 113;

  fp = fopen("test.txt","w");

  if(fp == NULL)
  {
    printf("フアイルを開けませんでした\n");
    exit(-1);
  }

  fprintf(fp,"a = %d\n",a);
  fprintf(fp,"b = %d\n",b);

  fclose(fp);

  printf("test.txtに書き込みました\n");

  return 0;
}
