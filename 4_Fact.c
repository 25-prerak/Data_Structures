#include <stdio.h>
#include <stdlib.h>
float fact(int x)
{
    float f;
    if(x==1)
        f=1;
    else
        f=x*fact(x-1);
    return f;
}
int main()
{
    float fac;
    int x;
    printf("Enter number whose factorial is to be calculated\n");
    scanf("%d",&x);
    fac=fact(x);
    printf("Factorial of %d is %f\n",x,fac);
    return 0;
}
/*Output
Enter number whose factorial is to be calculated
8
Factorial of 8 is 40320.000000
*/

