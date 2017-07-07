// moji3.c

#include<stdio.h>
#include<string.h>

int main(int argc,char**argv)
{
	int i,j;
	char name[9][9],change[9];

	printf("名前を入力してください\n");
	for(i = 0;i < 10;i++){
		printf("%d人目:",i+1);
		scanf("%s",name[i]);
		}

	for(i = 1;i < 10;i++){
		for(j = 1;j < 10;j++){
		if(strcmp(name[j-1],name[j]) == 0)
			continue;	
		else if(strcmp(name[j-1],name[j]) > 0){
				strcpy(change,name[j-1]);
				strcpy(name[j-1],name[j]);
				strcpy(name[j],change);
				}
			}
	}
	printf("\n名前を並び替えます\n");
	for(i = 0;i < 10;i++)
		printf("%s\n",name[i]);

return 0;
}
