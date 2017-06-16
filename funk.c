#include<stdio.h>

int main(void)
{
	int i;

	printf("ともやんの強さ\n");
	printf("攻撃力：");
	for(i = 0; i<15; i++)
	{
		printf("#");
	}
	printf("\n");
	
	printf("防御力：");
        for(i = 0; i<12; i++)
        {
                printf("#");
        }
        printf("\n");

	printf("素早さ：");
        for(i = 0; i<19; i++)
        {
                printf("#");
        }
        printf("\n");

	return 0;
}
