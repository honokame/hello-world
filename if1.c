// if1.c

#include<stdio.h>

int main(int argc,char**argv)
{
        int x,y,z;


         scanf("%d",&x);
         scanf("%d",&y);
         scanf("%d",&z);

        if(x==10 && (y==10 || z==10))
                printf("True \n");

        else
                printf("False \n");

        return 0;


}

