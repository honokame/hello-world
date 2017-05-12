// error2.c 文字列 

#include<stdio.h>
#include<string.h>

int main(int argc,char**argv)
{
	char s[100];
	strcpy(s,"今日は雨が降ります");
	printf("%s\n",s);
	printf("%c\n",s[4]);
	return 0;
}
