#include<stdio.h>

int main(int argc,char**argv)
{
	printf("int型:%zuバイト\n",sizeof(int));
	printf("char型:%zuバイト\n",sizeof(char));
	printf("long型:%zuバイト\n",sizeof(long));
	printf("short型:%zuバイト\n",sizeof(short));
	printf("_Bool型:%zuバイト\n",sizeof(_Bool));
	printf("float型:%zuバイト\n",sizeof(float));
	printf("long long型:%zuバイト\n",sizeof(long long));
	printf("long double型:%zuバイト\n",sizeof(long double));
	printf("unsigned char型:%zuバイト\n",sizeof(unsigned char));
	
	return 0;
}

