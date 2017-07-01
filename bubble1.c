// bubble1.c

#include <stdio.h>
#include<stdlib.h>

int main(int argc,char** argv)
{
	int i,j,change,a[50];
	srand(1607);
	for(i = 0;i < 50;i++){
		a[i]=rand();
		}
		
	for(i = 0;i < 50-1;i++){
	  	for(j = 50-1;j > i;j--){
			if(a[j-1] > a[j]){
				change = a[j];
				a[j] = a[j-1];
				a[j-1] = change;
				}
			}
		printf("%d\n",a[j]);

	}
	return 0;
}
