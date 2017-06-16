#include<stdio.h>

//void graph(int);
void graph(int x)
{
        int i;

        for(i = 0; i<x; i++)
        {
                printf("#");
        }
        printf("\n");
}


int main(int argc,char**argv)
{
	printf("ともやんの強さ\n");

	printf("攻撃力：");	
	graph(15);

	printf("防御力：");
        graph(12);

	printf("素早さ：");
        graph(19);

	return 0;
}


