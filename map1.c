// map1.c
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
#define KABE '+'
#define START 'S'
#define GOAL 'G'
#define PLAYER '@'
#define TREASURE '*'
#define BOMB '!'
#define GRASS '.'
#define KITA 0
#define HIGASHI 1
#define MINAMI 2
#define NISHI 3

char map[20][20];
char player[50];
int i,j,a,b,c,d,e,f,n,x,y,o_muki,n_muki;

void make_map(void)
{
  map[x][y] = PLAYER;
  x = 1;
  y = 0;

  srand((unsigned int)time(NULL));
  a = 1 + (int)(rand() * (18 - 1 + 1.0) / (1.0 + RAND_MAX));
  b = 1 + (int)(rand() * (18 - 1 + 1.0) / (1.0 + RAND_MAX));
  c = 1 + (int)(rand() * (18 - 1 + 1.0) / (1.0 + RAND_MAX));
  d = 1 + (int)(rand() * (18 - 1 + 1.0) / (1.0 + RAND_MAX));
  e = 1 + (int)(rand() * (18 - 1 + 1.0) / (1.0 + RAND_MAX));
  f = 1 + (int)(rand() * (18 - 1 + 1.0) / (1.0 + RAND_MAX));  
  
  for(i = 0; i < 20; i++){
      for(j = 0; j < 20; j++){	  
	  if(i == 1 && j == 0)
	      map[i][j] = START; // スタート
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
	  else{
	      map[i][j] = '.'; // 特になし
	      map[a][b] = TREASURE;
	      map[c][d] = TREASURE;
	      map[e][f] = TREASURE;
	  }
    if(i == 1 && j == 0){  
        printf("\x1b[30m");
	printf("\x1b[31m");
	printf("%c",map[1][0]);
	printf("\x1b[49m");
	printf("\x1b[39m");
    }
    else if(i == 18 && j == 19){
	printf("\x1b[30m");
	printf("\x1b[31m");
	printf("%c",map[18][19]);
	printf("\x1b[49m");
	printf("\x1b[39m");
    }
    else{
	printf("\x1b[30m");
	printf("\x1b[32m");
	printf("%c",map[i][j]);
	printf("\x1b[49m");
	printf("\x1b[39m");
    }
   }
   printf("\n"); // 空白
  }
  printf("\n"); // 空白 
}

void play_game(void)
{
  for(i = 0;i < 20;i++){ 
      for(j = 0;j < 20;j++){
	  if(i == 1 && j == 0)
	      map[i][j] = PLAYER;
	  else if(i == 18 && j == 19)
	       map [i][j] = GOAL;
	  else if(i == 0 || i == 19)
	       map[i][j] = KABE;
	  else if(i == 5 && j== 8)
	        map[i][j] = BOMB;
	  else if(i == 11 && j== 3)
	        map[i][j] = BOMB;
	  else if(i == 17 && j== 10)
	        map[i][j] = BOMB;
	  else{
	       map[i][j] = '.';
	       map[a][b] = TREASURE; 
	       map[c][d] = TREASURE;
	       map[e][f] = TREASURE;
	       }
	  if(i == 1 && j == 0){  
	      printf("\x1b[47m");
	      printf("\x1b[35m");
	      printf("%c",map[1][0]);
	      printf("\x1b[49m");
	      printf("\x1b[39m");
	      }
	  else if(i == 18 && j == 19){
	      printf("\x1b[30m");
	      printf("\x1b[31m");
	      printf("%c",map[18][19]);
	      printf("\x1b[49m");
	      printf("\x1b[39m");
	      }
	  else{
	      printf("\x1b[30m");
	      printf("\x1b[32m");
	      printf("%c",map[i][j]);
	      printf("\x1b[49m");
	      printf("\x1b[39m");
	      }
	  }
	  printf ("\n");
	}
	printf ("\n");

	printf("プレイヤーを動かす\n");
	for(n = 0;n < 50;n++){
	    scanf("%s",player);
	    if(player[n]=='F'){
	      if(o_muki == KITA){
		x--;
		map[x][y] = PLAYER; 
	      }
	      else if(o_muki == HIGASHI){
		y++;
		map[x][y] = PLAYER;
	      }

	      else if(o_muki == MINAMI){
		x++;
		map[x][y] = PLAYER;
	      }

	      else if(o_muki == NISHI){
		y--;
		map[x][y] = PLAYER;
	      }

}
	    if(player[n]=='R'){
	      n_muki = (o_muki + 1) % 4;
	      o_muki = n_muki;
	      } 
	      
	}
	
}

int main(int argc,char**argv)
{
  make_map(); //マップの設定
  play_game();
  return 0;
}
