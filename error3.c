// error3.c

#include<stdio.h>
#include<string.h>
 
int main(int argc,char**argv)
{
	char a[10],b[10];
	
	strcpy(a,"wwwwwwwwwwwwwwwwwwwwww");
	printf("a = %s\n",a);
	strcpy(b,"aaaaaaaaaaaaaaaaaaaaa");
	strcat(a,b);
	printf("a = %s\n",a);	

	return 0;
}
