//ransu

#include<stdio.h>
#include<stdlib.h>

int main (int argc, char **argv)
{
	int N,i = 0, s = 0,tane;
	double x, y, max = RAND_MAX;

	printf("発生させる乱数の数：");  
	scanf("%d",&N);	
	printf("発生させる乱数の種:");
	scanf("%d",&tane);
  	srand(tane);
  
  	while (i <= N){
    	x = random() / max;
    	y = random() / max;
    
    	if (x*x + y*y <= 1){
      	  s ++;
    	 }

    	 i ++;
  	}

  	printf(" π　の近似値は　%lf　です\n", (double)s * 4.0 / N);

  	return 0;

}
