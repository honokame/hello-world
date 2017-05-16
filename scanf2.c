//scanf2.c

#include<stdio.h>

int main(int argc,char**argv)
{
        char s[50];

        printf("名前を入れてください：");
        scanf("%s",s); //&不要
        printf("入力された名前は %s です。\n",s);

        return 0;
}

// scanf("%[^\n]s") 改行するまで
