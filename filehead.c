// filehead.c

#include<stdio.h>
int main(int argc,char**argv){
  int moji[11];
  int i;
  FILE *fp;

  if((fp = fopen(argv[1],"r")) == NULL){
    return -1;
  }
  
  for(i = 0;i < 10;i++){
    if((moji[i] = fgetc(fp)) == EOF){
      printf("ERROR!\n");
      return -1;
    }
  }

 for(i = 0;i < 10;i++){
   printf("%c",(char)moji[i]);
 }
 printf("\n");
 
 return 0;
}
