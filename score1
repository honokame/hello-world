#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,char**argv)
{
  FILE *fp;
  int i,math,English;

  srand((unsigned int)time(NULL));
  fp = fopen("score.txt","w+");

  if(fp == NULL)
  {
    printf("ファイルを開けませんでした\n");
    exit(-1);
  }
  fprintf(fp,"\t英語\t数学\n\n");
  for(i = 1; i < 41; i++){
  math = 1 + (int)(rand() * (100 - 1 + 1.0) / (1.0 + RAND_MAX));
  English = 1 + (int)(rand() * (100 - 1 + 1.0) / (1.0 + RAND_MAX));
  fprintf(fp,"\t%d\t%d\n",English,math);
  }
  fclose(fp);

  printf("score.txtに書き込みました\n");
