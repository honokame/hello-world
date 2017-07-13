#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define KABE '+'
#define START 'S'
#define GOAL 'G'
#define PLAYER '@'
#define BONB '!' 
#define TREASURE '*'
#define GRASS '.'

char map[20][20];

void make_map(void)
{
	int a,b,c,d,e,f,i,j;
  
  srand((unsigned int)time(NULL));
  a = 1 + (int)(rand() * (18 - 1 + 1.0) / (1.0 + RAND_MAX));
  b = 1 + (int)(rand() * (18 - 1 + 1.0) / (1.0 + RAND_MAX));
  c = 1 + (int)(rand() * (18 - 1 + 1.0) / (1.0 + RAND_MAX));
  d = 1 + (int)(rand() * (18 - 1 + 1.0) / (1.0 + RAND_MAX));
  e = 1 + (int)(rand() * (18 - 1 + 1.0) / (1.0 + RAND_MAX));
  f = 1 + (int)(rand() * (18 - 1 + 1.0) / (1.0 + RAND_MAX));  
	
	for(i = 0;i < 20;i++)
	{ 
		for(j = 0;j < 20;j++)
		{
		if(i == 1 && j == 0)
		    map[i][j] = START;
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
		printf("\x1b[30m");
		printf("\x1b[31m");
		printf("%c,map[1][0]");
		printf("\x1b[49m");
		printf("\x1b[39m");
    }
    else if(i == 18 && j == 19){
    printf("\x1b[30m");
		printf("\x1b[31m");
		printf("%c,map[18][19]");
		printf("\x1b[49m");
		printf("\x1b[39m");
    }
    else{
    printf("\x1b[30m");
		printf("\x1b[32m");
		printf("%c,map[i][j]");
		printf("\x1b[49m");
		printf("\x1b[39m");
    }
    
	}
	printf ("\n");
  }
  printf ("\n");
}
int main (int argc,char**argv)
{
	make_map();
	
	return 0;
}
