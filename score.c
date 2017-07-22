#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc,char**argv)
{
  FILE *sp,*ep,*mp;
  int i,English[50],Math[50],totale= 0,totalm = 0;
  double avge,avgm,e,m;

  srand((unsigned int)time(NULL));
  sp = fopen("score.txt","w+");
  ep = fopen("English.txt","w");
  mp = fopen("Mathematics.txt","w");

  if(sp == NULL){
    printf("score.txtファイルを開けませんでした\n");
    exit(-1);
  }
  
  if(ep == NULL){
    printf("English.txtファイルを開けませんでした\n");
    exit(-1);
  }
  
  if(mp == NULL){
    printf("Mathematics.txtファイルを開けませんでした\n");
    exit(-1);
  }
  
  fprintf(sp,"\t英語\t\t数学\n\n");

  for(i = 0; i < 40; i++){
    English[i] = 1 + (int)(rand() * (100 - 1 + 1.0) / (1.0 + RAND_MAX));
    Math[i] = 1 + (int)(rand() * (100 - 1 + 1.0) / (1.0 + RAND_MAX));
    fprintf(sp,"\t%d\t\t%d\n",English[i],Math[i]);
    fscanf(sp,"%d%d",&English[i],&Math[i]);
    totale = totale + English[i];
    totalm = totalm + Math[i];
  }

  fprintf(sp,"\n");
  fprintf(sp,"\t平均点\t\t平均点\n");
  avge = (double)totale / 40;  
  avgm = (double)totalm / 40;
  fprintf(sp,"\t%0.2f\t\t%0.2f\n",avge,avgm);
  fprintf(ep,"\t点数\t\t差分\n\n");
  fprintf(mp,"\t点数\t\t差分\n\n");
  
  for(i = 0; i < 40; i++){
    fscanf(sp,"%d%d",&English[i],&Math[i]);
    fscanf(sp,"%0.2f%0.2f",&avge,&avgm);
    if(English[i] > avge){
      e = (double)English[i] - avge;
    }
    else if(English[i] < avge){
      e = avge - (double)English[i];
    }
    if(Math[i] > avgm){  
      m = (double)Math[i] - avgm;
    }
    else if(Math[i] < avgm){
      m = avgm - (double)Math[i];
    }

    fprintf(ep,"\t%d\t\t%0.2f\n",English[i],e);
    fprintf(mp,"\t%d\t\t%0.2f\n",Math[i],m);
  }
    
  fclose(sp);
  fclose(ep);  
  fclose(mp);
  printf("score.txtに書き込みました\n");
  printf("English.txtに書き込みました\n");
  printf("Mathematics.txtに書き込みました\n");

  return 0;
}
