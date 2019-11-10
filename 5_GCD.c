#include <stdio.h>
int gcd(int x,int y)
{
    int g;
    if(x>y)
        gcd(y,x);
    else
    {
        if(x==0)
            g=y;
        else
            g=gcd(x,y%x);
        return g;
    }

}
int main()
{
    int n,m,g;
    printf("Enter number 1:");
    scanf("%d",&m);
    printf("Enter number 2:");
    scanf("%d",&n);
    g=gcd(m,n);
    printf("GCD of %d and %d is %d",m,n,g);
    return 0;
}
/* output
Enter number 1:12
Enter number 2:16
GCD of 12 and 16 is 4
*/
