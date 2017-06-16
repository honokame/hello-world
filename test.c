#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char**argv)
{
        double e;
        int c,d;
	char a[100],b[100]; //要素数を指定してなかった

	while(1){ //ただaとbの入力をくりかえすループになってた
        printf("５桁までの数字を２つ入力してください。１つ目がa,２つ目をbとする\n");
        printf("このプログラムは'quit'と入力されるまでくりかえします\n"); //quitをダブルクォーテーションで囲っていた
        scanf("%s",a);
        scanf("%s",b);

	if((strcmp(a,"quit") == 0)||(strcmp(b,"quit")==0)){
 		break;
	}
        else if((strlen(a) > 5)||(strlen(b) > 5)){
                printf("桁数が５桁より大きいのでもう一度入力してください\n");
                continue; //５桁より大きいときループしないようになってた
        }	

	else if(atoi(b) == 0){　//0の存在を忘れてたので追加
		printf("０では割れないのでもう一度入力してください\n");
		continue;
 	}	        
       	else if((strlen(a) <= 5)&&(strlen(b) <= 5)){ //計算するときの条件を書いてなかった
        	c = atoi(a) / atoi(b);
        	d = atoi(a) % atoi(b);
        	e = atof(a) / atof(b);
        	printf("aをbで割った商：%d あまり：%d\n",c,d);
		printf("aをbで割った商（少数第２位）：%0.2f\n",e); //あまりも書いてた
		continue; //ループしてなかった
        	}
	}
	return 0;
}

