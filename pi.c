#include<stdio.h>

int main(int argc,char**argv)
{
	double hankei,pi,nagasa,menseki;

	pi = 3.1415;
	printf("円の半径：");
	
	scanf("%lf",&hankei);
	nagasa = 2 * hankei * pi;
	menseki = hankei * hankei * pi; 
	
	printf("円周の長さ：%lf\n",nagasa);
	printf("面積：%lf\n",menseki);
	printf("円周の長さ：%0.2lf\n",nagasa);
        printf("面積：%0.2lf\n",menseki);
	printf("円周の長さ：%0.4lf\n",nagasa);
        printf("面積：%0.4lf\n",menseki);
	printf("円周の長さ：%0.5lf\n",nagasa);
        printf("面積：%0.5lf\n",menseki);

	return 0;
}
