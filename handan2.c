#include<stdio.h>

int main(int argc,char**argv)
{
double a,w;
int x;
long y;
short z;
printf("風船の値段は何円がいいですか：");
scanf("%lf",&a);

w = a / 65;
x = (int)a / 65;
y = (long)a / 65;
z = (short)a / 65;

printf("風船を部員６５人でわけると一人あたりの値段は\n");
printf("%lf(double)\n%d(double..int)\n%ld(double..long)\n%d(double..short)\n",w,x,y,z);
return 0;
}
