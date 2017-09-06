// test4.c

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char*argv)
{
  char a[101],b[101]; //　なぜか１００１にしてた
  int newa[100],newb[100],total[100]; //　答えをint型にしてなかった
  int i,c,d;

  for(i = 0;i < 101;i++){
    a[i] = '0'; //　配列の初期化をしてなかった
    b[i] = '0';
  }

  printf("100桁までの整数を2つ入力して下さい\n");
  scanf("%s",a);
  scanf("%s",b);
  c = strlen(a) - 1; //　構文をｓｔｒｃｍｐとまざった
  d = strlen(b) - 1;
  printf("\n%s + %s =",a,b);

  for(i = 0;i < 100;i++){ //　後ろの桁から計算していた
    if(i <= c){
      newa[i] = a[c-i] -'0'; //　atoiで変換してた
    }
    if(i <= d){
      newb[i] = b[d-i] -'0';
    }
    if(i > c){
      newa[i] = 0; //　int型に変換していなかった
    }
    if(i > d){
      newb[i] = 0;
    }
  }
  for(i = 0;i < 100;i++){
    total[i] = newa[i] + newb[i];
  }
  for(i = 0;i < 100;i++){
    if(total[i] >= 10){
      total[i] = total[i] - 10;
      total[i+1] = total[i+1] + 1;
    }
  }
  i = 99;
  while(total[i] == 0){ //　答えに表示しなくていい部分も表示するようにしてた
    i--;
  }
  for(;i >= 0;i--){
    printf("%d",total[i]);
  }
  printf("\n");

  return 0;
}
