// num2.c

#include<stdio.h>

int func(int);
int a ;

int main(void)
{
	int i,num;

	for(i=0;i<10000;i++){
		if(i==0){
			a = 3;
		}else{
			a++;
		}
		num = func(a);
		printf("%d\n",num);

	}
	return 0;
}

int func(int a)
{
	if(a==3)
		return 3;
	else
		return func(a-1)+4;
}
