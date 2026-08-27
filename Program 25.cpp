#include <stdio.h>

int gcd(int a,int b)
{
    while(b)
    {
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int main()
{
    int n,m,g;

    printf("Enter n: ");
    scanf("%d",&n);

    printf("Enter plaintext block: ");
    scanf("%d",&m);

    g=gcd(n,m);

    printf("GCD = %d\n",g);

    if(g>1 && g<n)
        printf("Factor of n found!\n");
    else
        printf("No useful factor found.\n");

    return 0;
}
