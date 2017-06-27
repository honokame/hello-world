// tan.c

#include<stdio.h>
#include<math.h>

int main(int argc,char**argv)
{
        double  d;
        for(d = 0.0;d<360.0;d++){
 		if((d != 90.0) && (d !=270.0)){
			printf("%0.1lf\t%lf\n",d,tan(d*M_PI/180.0));
		}

}
	

        return 0;
}

