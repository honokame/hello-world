// fiehead.c

#include<stdio.h>
#include<stdlib.h>

int main(int argc,char**argv)
{
  FILE *file;
  int i;

  if((file = fopen(argv[1],"r")) == NULL){
    printf("ファイルが開けません\n");
    exit(-1);
  }

  while(1){
    i = fgetc(file);
    printf("%d\n",i);
    if(i == EOF){
      break;
    }
  }
  
  fclose(file);
  return 0;
}

