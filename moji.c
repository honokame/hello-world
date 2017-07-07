#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char**argv)
{
//	int i;
	char s[] = "りんご";
	mbstowcs(s[]);
	printf("%s\n",s);
	
/*	for(i = 5;i > -1;)
		printf("%c",s[i]);
	printf("\n");
*/
	return 0;
}
