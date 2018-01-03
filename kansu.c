// kansu.c

#include<stdio.h>
int ringo(void);

int main(void)
{
  ringo();
  return 0;
}

int ringo(void)
{
  long  price,money;
   
  printf("りんごは何円ですか：");
  scanf("%ld",&price);
  printf("何円ほしいですか：");
  scanf("%ld",&money);

  printf("りんご %ld 個 GET !!!!\n",(money/price));

  return 0;
}

