// hairetu2.c

#include<stdio.h>

int main(int argc,char**argv)
{
	int a[10];
	printf("a[-1] = %d\n",a[-1]);
	a[10] = 100;
	printf("a[10] = %d\n",a[10]);
	printf("a[-1]のアドレスは%p\n",a[-1]);
	printf("a[10]の先頭アドレスは%p\n",a[10]);

	return 0;
}
