#include <stdio.h>

long long power(long long a,long long x,long long q)
{
    long long r=1;
    while(x)
    {
        if(x%2) r=r*a%q;
        a=a*a%q;
        x/=2;
    }
    return r;
}

int main()
{
    long long a,q,xA,xB,A,B;

    printf("Enter a,q: ");
    scanf("%lld%lld",&a,&q);

    printf("Enter Alice secret: ");
    scanf("%lld",&xA);

    printf("Enter Bob secret: ");
    scanf("%lld",&xB);

    A=power(a,xA,q);
    B=power(a,xB,q);

    printf("Alice sends %lld\n",A);
    printf("Bob sends %lld\n",B);

    printf("Shared key = %lld\n",power(B,xA,q));

    return 0;
}
