// scanf4.c

#include<stdio.h>

int main(int argc,char**argv)
{
        //int a;
	char s[15];
        printf("数を入れてください:\n");
        fgets(s,sizeof(s),stdin);
        printf("入力された数は %d です。\n",atoi(s));

        return 0;
}

