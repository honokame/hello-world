#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>
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
int i,j,a,b,c,d,e,f,n,x,y;

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
	  if(i == x && j == y){
	      map[x][y] = PLAYER;
	      printf("\x1b[47m");
	      printf("\x1b[35m");
	      printf("%c",map[x][y]);
	      printf("\x1b[49m");
	      printf("\x1b[39m");
	    }      
	 else if(i == 1 && j == 0){
	      map[i][j] = START;
	      printf("\x1b[30m");
	      printf("\x1b[34m");
	      printf("%c",map[i][j]);
	      printf("\x1b[49m");
	      printf("\x1b[39m");
	      }

	  else if(i == 18 && j ==19){
		map[i][j] = GOAL; // ゴール
	      	printf("\x1b[30m");
		printf("\x1b[34m");
		printf("%c",map[i][j]);
		printf("\x1b[49m");
		printf("\x1b[39m");
		}

	  else if((i == 0 || i == 19) || (j == 0 || j == 19)){
	      map[i][j] = KABE; // 壁
	      printf("\x1b[30m");
	      printf("\x1b[32m");
	      printf("%c",map[i][j]);
	      printf("\x1b[49m");
	      printf("\x1b[39m");
	  }
	  else if((i == 5 && j == 12) || (i == 10 && j == 6) || (i == 18 && j == 3)){
	      map[i][j] = BOMB; // 爆弾
	      printf("\x1b[30m");
	      printf("\x1b[31m");
	      printf("%c",map[i][j]);
	      printf("\x1b[49m");
	      printf("\x1b[39m");
	  }
	  else if((i == a && j == b) || (i == c && j == d) || (i == e && j == f)){  
	      map[a][b] = TREASURE;
	      map[c][d] = TREASURE;
	      map[e][f] = TREASURE;
	      printf("\x1b[30m");
	      printf("\x1b[37m");
	      printf("%c",map[i][j]);
	      printf("\x1b[49m");
	      printf("\x1b[39m");
	  }
	  else{
	      map[i][j] = '.'; // 特になし
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
  int o_muki,n_muki;
  char player[50];
  printf("プレイヤーを動かす\n");
  scanf("%s",player);
  for(n = 0;n < 50;n++){
      if(player[n]=='F'){
	map[x][y] = ' ';
	         
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
	for(i = 0;i < 20;i++){ 
      for(j = 0;j < 20;j++){
	  if(i == x && j == y){
	    printf("\x1b[47m");
	    printf("\x1b[35m");
	    printf("%c",map[x][y]);
	    printf("\x1b[49m");
	    printf("\x1b[39m");
	    }
          else if(i == 1 && j == 0){  
	      map[i][j] = START;
	      printf("\x1b[30m");
	      printf("\x1b[34m");
	      printf("%c",map[i][j]);
	      printf("\x1b[49m");
	      printf("\x1b[39m");
	      }
	  else if(i == 18 && j == 19){
	      map[i][j] = GOAL;
	      printf("\x1b[30m");
	      printf("\x1b[34m");
	      printf("%c",map[i][j]);
	      printf("\x1b[49m");
	      printf("\x1b[39m");
	      }
	    else if((i == 0 || i == 19) || (j == 0 || j == 19)){
	      map[i][j] = KABE; // 壁
	      printf("\x1b[30m");
	      printf("\x1b[32m");
	      printf("%c",map[i][j]);
	      printf("\x1b[49m");
	      printf("\x1b[39m");
	  }
	  else if((i == 5 && j == 12) || (i == 10 && j == 6) || (i == 18 && j == 3)){
	      map[i][j] = BOMB; // 爆弾
	      printf("\x1b[30m");
	      printf("\x1b[31m");
	      printf("%c",map[i][j]);
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
	sleep(1);
	if( x < 19){    
        if((map[x+1][y] == KABE)|| (map[x+1][y] == BOMB)){
	  printf(" GAMEOVER \n");
	  break;
	}}

	 else if(x>0){	
	 if((map[x-1][y] == KABE) || (map[x-1][y] == BOMB)){
	        printf("GAMEOVER\n");
		break;}}
	else if(y < 19){
	 if((map[x][y+1] == KABE) || (map[x][y+1] == BOMB)){
		printf("GAMEOVER\n");
		break;}}
	else if(y > 0){
	if((map[x][y-1] == KABE) || (map[x][y-1] == BOMB)){
		 printf(" GAMEOVER \n");
		 break;
	}
	}
	else if(map[x+1][y] == GOAL){
	  printf("GOAL");
	  break;
      }}
	  
	else if(player[n]=='R'){
	      n_muki = (o_muki + 1) % 4;
	      o_muki = n_muki;
	      }
 	else
	     break;
    }}


int main(int argc,char**argv)
{
  make_map(); //マップの設定
  play_game();
  return 0;
}
