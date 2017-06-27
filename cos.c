// cos.c

#include<stdio.h>
#include<math.h>

int main(int argc,char**argv)
{
        double d;
        for(d = 0.0;d<360;d+=1.0)
                printf("%0.1f\t%lf\n",d,cos(d*M_PI/180.0));
        return 0;
}

