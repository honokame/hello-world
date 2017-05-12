//strcmp.c

#include<stdio.h>
#include<string.h>

int main(int argc,char**argv)
{
	char s[30],t[30],u[30],v[30],w[30];
	int a,b,c,d,e,f,g,h,i,j;
	 
	strcpy(s,"a");
	strcpy(t,"A");
	strcpy(u,"23");
	strcpy(v,"nya-");
	strcpy(w,"**");

	a = strcmp(s,t);
	b = strcmp(s,v);
	c = strcmp(s,w);
	d = strcmp(v,u);
	e = strcmp(w,t);
	f = strcmp(u,w);
	g = strcmp(u,t);
	h = strcmp(t,u);
	i = strcmp(v,w);
	j = strcmp(w,v);

	printf("strcmpの結果 = %d\n",a);
	printf("strcmpの結果 = %d\n",b);
	printf("strcmpの結果 = %d\n",c);
	printf("strcmpの結果 = %d\n",d);
	printf("strcmpの結果 = %d\n",e);
	printf("strcmpの結果 = %d\n",f);
	printf("strcmpの結果 = %d\n",g);
	printf("strcmpの結果 = %d\n",h);
	printf("strcmpの結果 = %d\n",i);
	printf("strcmpの結果 = %d\n",j);

	return 0;

}
