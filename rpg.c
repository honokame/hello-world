

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct status{
  char name[20];
  int hp;
  int kougeki;
  int bougyo;
};

typedef struct status tsuyosa;
void first_status(tsuyosa player,tsuyosa teki);
void play_game(tsuyosa player,tsuyosa teki);
int main(int argc,char**argv){
  tsuyosa player;
  tsuyosa teki;
  
  int i,base=0;
  int moji[11] = {};
  FILE *fp;
  char filename[20] = {};
  double player_hp_random =0;
  double player_kougeki_random=0;
  double player_bougyo_random=0;
  double teki_hp_random=0; 
  double teki_kougeki_random=0;
  double teki_bougyo_random=0;
  char name[20] = {};
  printf("input filename(20)\n");
  scanf("%s",filename);
  
  fp = fopen(filename,"r");
  if(fp == NULL){
    printf("not open file\n");
    return -1;
  }

  for(i = 0;i < 10;i++){
    if((moji[i] = fgetc(fp)) == EOF){
      printf("ERROR!\n");
      return -1;
    }
  }
  for(i = 0;i < 10;i++){ 
    base += moji[i]; //451
  }
  
  srand((unsigned)time(NULL));
  player_hp_random = 0.8 + (rand() * ( 2.0 - 0.8 + 1.0)/(1.0 + RAND_MAX)); //0.8-2.0
  player_kougeki_random = 0.6 + (rand() * ( 1.5 - 0.6 + 1.0)/(1.0 + RAND_MAX)); //0.6-1.5
  player_bougyo_random = 0.1 + (rand() * ( 0.5 - 0.1 + 1.0)/(1.0 + RAND_MAX)); //0.1-0.5
  player.hp = base * player_hp_random; //340-902
  player.kougeki = base * player_kougeki_random;// 270-676
  player.bougyo = base * player_bougyo_random; //45-225
  teki_hp_random = 0.8 + (rand() * ( 2.0 - 0.8 + 1.0)/(1.0 + RAND_MAX)); //0.8-2.0
  teki_kougeki_random = 0.6 + (rand() * ( 1.3 - 0.6 + 1.0)/(1.0 + RAND_MAX)); //0.6-1.3
  teki_bougyo_random = 0.1 + (rand() * ( 0.7 - 0.1 + 1.0)/(1.0 + RAND_MAX)); //0.1-0.7
  teki.hp = base * teki_hp_random; //340-902
  teki.kougeki = base * teki_kougeki_random; // 270-586
  teki.bougyo = base * teki_bougyo_random; //45-315

  printf("player name:");
  scanf("%s",name);
  strcpy(player.name,name);
  printf("\n****************************doragon***************************************\n");
  first_status(player,teki);
  play_game(player,teki);
  fclose(fp);
  return 0;
}

void first_status(tsuyosa player,tsuyosa teki){
  printf("[name]:%s\n",player.name);
  printf("[HP]:%d\n",player.hp);
  printf("[kougeki]:%d\n",player.kougeki);
  printf("[bougyo]:%d\n",player.bougyo);
  printf("\n");
  printf("[HP]:%d\n",teki.hp);
  printf("[kougeki]:%d\n",teki.kougeki);
  printf("[bougyo]:%d\n",teki.bougyo);
  printf("*******************************************");
  return;
}

void play_game(tsuyosa player,tsuyosa teki){
  
  int cmd=0;
  int player_plus=0,teki_plus=0;
  int random=0;

  while((player.hp >= 0) && (teki.hp >= 0)){ 
    printf("%s [HP]:%d\n\n",player.name,player.hp);
    printf("1 >> kougeki\n2 >> kakureru\n");
    scanf("%d",&cmd);

    player_plus = (int)rand() % 100;
    teki_plus = (int)rand() % 100;
    random = (int)rand() % 6 + 1;
    if(cmd == 1){
      if(teki.bougyo < player.kougeki + player_plus){
        teki.hp = teki.hp - ((player.kougeki + player_plus) - teki.bougyo);
        printf("\n%s >>>> doragon\n",player.name);
        printf("%d damage\n",(player.kougeki + player_plus) - teki.bougyo);
      }
      printf("\ndragon >>>> %s\n",player.name);
      if(player.bougyo < teki.kougeki + teki_plus){
        player.hp = player.hp - ((teki.kougeki + teki_plus) -player.bougyo);
        printf("%d damage\n",(teki.kougeki + teki_plus) -player.bougyo);
      }
    }

    else if(cmd == 2){
      if(random < 5){
        printf("kakureru ... NO!\n"); 
        printf("\ndragon >>>> %s\n",player.name);
        player.hp = player.hp - (teki.kougeki + teki_plus);
        printf("%d damage\n",(teki.kougeki + teki_plus));
        }
      if(random > 4){
        printf("kakureru ... OK!\n");
        printf("damage 0\n");
      }
    }
    if(player.hp < 0){
      player.hp = 0;
      printf("%s[HP]:%d\ndragon[HP]:%d",player.name,player.hp,teki.hp);
      printf("\n****************  GAME OVER  ***********************\n");
      break;
    }

    else if(teki.hp < 0){
      teki.hp = 0;
      printf("%s[HP]:%d\n[HP]:%d",player.name,player.hp,teki.hp);
      printf("\n****************  %s WIN  *********************\n",player.name);
      break;
    }

    printf("%s[HP]:%d\n[HP]:%d",player.name,player.hp,teki.hp);
    printf("\n*************************************\n");
  }
  return;
}




