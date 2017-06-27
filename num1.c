// num1.c

#include<stdio.h>
int main(void)
{
	int i,num;
	for(i = 1;i<10001;i++){
		num = 3+(i-1)*4;
		printf("%d\n",num);
	}
	return 0;
}
