//rpg.c

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>



int main(int argc,char**argv){
  int playerhp;
  int playerkougeki;
  int playerbougyo;
  int tekihp;
  int tekikougeki;
  int tekibougyo;
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
  int cmd=0,player_plus=0,teki_plus=0;
  int random=0;

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
  printf("%d\n",base);
  
  srand((unsigned)time(NULL));
  player_hp_random = 0.8 + (rand() * ( 2.0 - 0.8 + 1.0)/(1.0 + RAND_MAX)); //0.8-2.0
  player_kougeki_random = 0.6 + (rand() * ( 1.5 - 0.6 + 1.0)/(1.0 + RAND_MAX)); //0.6-1.5
  player_bougyo_random = 0.1 + (rand() * ( 0.5 - 0.1 + 1.0)/(1.0 + RAND_MAX)); //0.1-0.5
  playerhp = base * player_hp_random; //340-902
  playerkougeki = base * player_kougeki_random;// 270-676
  playerbougyo = base * player_bougyo_random; //45-225
  teki_hp_random = 0.8 + (rand() * ( 2.0 - 0.8 + 1.0)/(1.0 + RAND_MAX)); //0.8-2.0
  teki_kougeki_random = 0.6 + (rand() * ( 1.3 - 0.6 + 1.0)/(1.0 + RAND_MAX)); //0.6-1.3
  teki_bougyo_random = 0.1 + (rand() * ( 0.7 - 0.1 + 1.0)/(1.0 + RAND_MAX)); //0.1-0.7
  tekihp = base * teki_hp_random; //340-902
  tekikougeki = base * teki_kougeki_random; // 270-586
  tekibougyo = base * teki_bougyo_random; //45-315

  printf("player name:");
  scanf("%s",name);
  printf("\n****************************doragon***************************************\n");

  printf("[name]:%s\n",name);
  printf("[HP]:%d\n",playerhp);
  printf("[kougeki]:%d\n",playerkougeki);
  printf("[bougyo]:%d\n",playerbougyo);
  printf("\n");
  printf("[HP]:%d\n",tekihp);
  printf("[kougeki]:%d\n",tekikougeki);
  printf("[bougyo]:%d\n",tekibougyo);

    while((playerhp >= 0)&&(tekihp >= 0)){
    printf("\n%s [HP]:%d\n",name,playerhp);
    printf("1 >> kougeki\n2 >> kakureru\n");
    scanf("%d",&cmd);

    player_plus = (int)rand() % 100;
    teki_plus = (int)rand() % 100;
    random = (int)rand() % 6 + 1;
    if(cmd == 1){
      if(tekibougyo < playerkougeki + player_plus){
        tekihp = tekihp - ((playerkougeki + player_plus) - tekibougyo);
        printf("\n%s >>>> doragon\n",name);
        printf("%d damage\n",(playerkougeki + player_plus) - tekibougyo);
      }
      printf("\ndragon >>>> %s\n",name);
      if(playerbougyo < tekikougeki + teki_plus){
        playerhp = playerhp - ((tekikougeki + teki_plus) -playerbougyo);
        printf("%d damage\n",(tekikougeki + teki_plus) -playerbougyo);
      }
    }

    else if(cmd == 2){
      if(random < 5){
        printf("kakureru ... NO!\n"); 
        printf("\ndragon >>>> %s\n",name);
        playerhp = playerhp - (tekikougeki + teki_plus);
        printf("%d damage\n",(tekikougeki + teki_plus));
        }
      if(random > 4){
        printf("kakureru ... OK!\n");
        printf("damage 0\n");
      }
    }
    if(playerhp < 0){
      playerhp = 0;
      printf("%s[HP]:%d\ndragon[HP]:%d",name,playerhp,tekihp);
      printf("\n****************  GAME OVER  ***********************\n");
      break;
    }

    else if(tekihp < 0){
      tekihp = 0;
      printf("%s[HP]:%d\n[HP]:%d",name,playerhp,tekihp);
      printf("\n****************  %s WIN  *********************\n",name);
      break;
    }

    printf("%s[HP]:%d\n[HP]:%d",name,playerhp,tekihp);
    printf("\n************************************\n");
  }
  fclose(fp);
  return 0;
}




