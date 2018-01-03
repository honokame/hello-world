// map1.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define KABE '+'
#define START 'S'
#define GOAL 'G'
#define PRAYER '@'
#define TREASURE '*'
#define BOMB '!'
#define GRASS '.'

char map[20][20];

void make_map(void)
{
  int i,j,a,b,c,d,e,f;

srand((unsigned int)time(NULL));
a = 1 + (int)(rand()*(18-1+1.0)/(1.0+RAND_MAX));
b = 1 + (int)(rand()*(18-1+1.0)/(1.0+RAND_MAX));
c = 1 + (int)(rand()*(18-1+1.0)/(1.0+RAND_MAX));
d = 1 + (int)(rand()*(18-1+1.0)/(1.0+RAND_MAX));
e = 1 + (int)(rand()*(18-1+1.0)/(1.0+RAND_MAX));
f = 1 + (int)(rand()*(18-11.0)/(1.0+RAND_MAX));

  for(i = 0; i < 20; i++)
  {
      for(j = 0; j < 20; j++)
      {	  
	  if(i == 1 && j == 0)
	      map[i][j] = START; // スタート
	  //printf("\x1b[31m");
	  else if(i == 18 && j ==19)
	      map[i][j] = GOAL; // ゴール
	  else if(i == 0 || i == 19)
	      map[i][j] = KABE; // 壁
	  else if(j == 0 || j ==19)
	      map[i][j] = KABE; // 壁
	  else if(i == 5 && j == 12)
	      map[i][j] = BOMB; // 爆弾
	  else if(i == 10 && j == 6)
	      map[i][j] = BOMB; // 爆弾
	  else if(i == 18 && j == 3)
	      map[i][j] = BOMB; // 爆弾
	  else
	      map[i][j] = '.'; // 特になし
	      map[a][b] = TREASURE;
	      map[c][d] = TREASURE;
	      map[e][f] = TREASURE;
	  printf("\x1b[30m"); // 背景色：黒
	  printf("\x1b[32m"); // 文字色：水色
	  printf("%c",map[i][j]);
	  printf("\x1b[31m");
	  printf("\x1b[49m"); // 背景色をデフォルトに戻す
	  printf("\x1b[39m"); // 文字色をデフォルトに戻す
      }
      printf("\n"); // 空白
  }
  printf("\n"); // 空白
   
}
int main(int argc,char**argv)
{
  make_map(); //マップの設定

  return 0;
}
