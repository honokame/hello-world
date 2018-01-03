#include<stdio.h>
#include<string.h>
#include<stdlib.h> //　書いていなかった

int main(int argc,char*argv)
{
  int i = 0,a = 0,b = 0;
  FILE *fp;
  char count[1000][1000];

  fp = fopen("a.txt","r");

  if(fp == NULL){
    printf("ファイルを開けませんでした");
    exit(-1);
  }
  while(!feof(fp) && i < 1000){
    fscanf(fp,"%s",(count[i]));
    a = strlen(count[i]); //　ファイル全体のサイズにしてた
    b = a + b;
    i++;
  }
  printf("行数 : %d\n",i);
  printf("サイズ ： %d\n",b);

  fclose(fp);
  printf("a.txtを読み込みました\n");

  return 0;
  }
