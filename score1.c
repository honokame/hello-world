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

  if(sp == NULL)
  {
    printf("score.txtファイルを開けませんでした\n");
    exit(-1);
  }
  
  if(ep == NULL)
  {
    printf("English.txtファイルを開けませんでした\n");
    exit(-1);
  }
  
  if(mp == NULL)
  {
    printf("Mathematics.txtファイルを開けませんでした\n");
    exit(-1);
  }
  
  fprintf(sp,"\t英語\t数学\n\n");
  for(i = 0; i < 40; i++){
  English[i] = 1 + (int)(rand() * (100 - 1 + 1.0) / (1.0 + RAND_MAX));
  Math[i] = 1 + (int)(rand() * (100 - 1 + 1.0) / (1.0 + RAND_MAX));
  fprintf(sp,"\t%d\t%d\n",English[i],Math[i]);
  }

  fprintf(sp,"\t平均点\t平均点\n\n");
  for(i = 0; i < 40; i++){
    fscanf(sp,"\t%d\t%d\n",&English[i],&Math[i]);
    totale = totale + English[i];
    totalm = totalm + Math[i];
  }
  avge = (double)totale / 40;  
  avgm = (double)totalm / 40;
  fprintf(sp,"\t%0.2lf\t%0.2lf\n",avge,avgm);
  
  for(i = 0; i < 40; i++){
    fscanf(sp,"\t%d\t%d\n",&English[i],&Math[i]);
    fscanf(sp,"\t%0.2lf\t%0.2lf\n",&avge,&avgm);
    e = (double)English[i] - avge;
    m = (double)Math[i] - avgm;
    fprintf(ep,"\t%lf\t%lf\n",English[i],e);
    fprintf(mp,"\t%lf\t%lf\n",Math[i],m);
  }
    
  fclose(sp);
  fclose(ep);  
  fclose(mp);
  
  return 0;
}
 
 
    
  
  
  

 
  
  
