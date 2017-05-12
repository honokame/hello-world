// atoi.c

#include<stdio.h>
#include<string.h> 
#include<stdlib.h>

int main(int argc,char**argv)
{
	char a[30], b[30],c[30],d[30],e[30],f[30],g[30],h[30],i[30];
	int total1;
	double total2;
	
	strcpy(a,"12345");
	strcpy(b,"23456");
	strcpy(c,"34567");
	strcpy(d,"45678");
	strcpy(e,"56789");
	strcpy(f,"67890");
	strcpy(g,"78901");
	strcpy(h,"89012");
	strcpy(i,"90123");
		
	total1 = atoi(a) + atoi(b) + atoi(c) + atoi(d) + atoi(e) + atoi(f) + atoi(g) + atoi(h) + atoi(i);
	total2 = atof(a) + atof(b) + atof(c) + atof(d) + atof(e) + atof(f) + atof(g) + atof(h) + atof(i);
	
	printf("atoi関数 = %d\n",total1);
	printf("atof関数 = %f\n",total2);

	return 0;
}
