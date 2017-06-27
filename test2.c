#include<stdio.h>
#include<stdlib.h>

int main(int argc,char**argv)
{
        int a,sixcount = 0,allcount = 0; //サイコロを３つ使ってた。sixcount、allcountについてはサイコロを３回振るだけだと思っていたので必要性に気づけなかった
  	
	srand(23478924); //乱数の種の意味がわかってなかった（忘れてた）ので書けなかった

        while (sixcount < 4 ){ //サイコロを３回振って終わってた
                a = rand()*(double)6/(1.0+RAND_MAX)+1; //RAND_MAXの使い方がわからなくて適当に書いたのでよくわからない乱数を作るようになった
        	if(a != 6){ //サイコロが６以外出た時のことを考えてなかった。
			sixcount = 0; //３回連続で考えてなかった。サイコロを３つ振って全部６が出たらいいと思ってた
		}else{ 
			sixcount ++; 
			}
			allcount ++; //そもそも問題の意味がわかっていなかった。サイコロを３回振るだけと思ってた
			}
        printf("%d回目で３回連続６が出た\n",allcount); //何回目出ると書いてなかった（３回しかふらないと思ってた）

        return 0;
}

