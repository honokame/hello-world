#include<stdio.h>
#include<string.h>

char name[11];
char func();

int main(void)
{

printf("名前を入力してください：");
while(1){
func();
printf("%s\n",name);

if(strcmp(name,"quit")==0)
	break;
}
return 0;
}

char func(void)
{
scanf("%s",name);
return name;
}

