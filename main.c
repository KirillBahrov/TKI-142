#include <stdio.h>
#include <math.h>

int main(void) {
    float x=1.825,y=18.225,z=-3.298,a,b;
    a = (pow(x,(y/x))-pow((y/x),(1/3)));
    b = ((y-x)+(((y-z)/y-x)/(3+((pow(z,2))/5))));
    
    printf("%f\n",x);
    printf("%f\n",y);
    printf("%f\n",z);
    printf("%f\n",a);
    printf("%f",b);

}