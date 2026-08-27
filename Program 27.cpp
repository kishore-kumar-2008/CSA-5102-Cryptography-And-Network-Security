#include <stdio.h>

long long power(long long a,long long e,long long n)
{
    long long r=1;
    while(e)
    {
        if(e%2) r=r*a%n;
        a=a*a%n;
        e/=2;
    }
    return r;
}

int main()
{
    long long n,e;

    printf("Enter n and e: ");
    scanf("%lld%lld",&n,&e);

    printf("\nCodebook:\n");

    for(int m=0;m<26;m++)
        printf("%d -> %lld\n",m,power(m,e,n));

    printf("\nAttack: Compare ciphertext with this table.");

    return 0;
}
