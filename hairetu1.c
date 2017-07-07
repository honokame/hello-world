// hairetu1.c

#include<stdio.h>

int main(int argc,char**argv)
{
        int a[100],i,j,k;
	double b[100];
	char c[100];

	for(i=0;i<10;i++){
                printf("a[%d]のアドレスは%p\n",i,&a[i]);
	}
	for(j=0;j<10;j++){
	printf("b[%d]のアドレスは%p\n",j,&b[j]);

	}
	for(k=0;k<10;k++){
	printf("c[%d]のアドレスは%p\n",k,&c[k]);
      	}
        return 0;

}

