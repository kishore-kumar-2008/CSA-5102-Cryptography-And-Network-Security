#include <stdio.h>

int main()
{
    int n=3599,e=31,p,q,phi,d;

    for(p=2;p<n;p++)
        if(n%p==0)
        {
            q=n/p;
            break;
        }

    phi=(p-1)*(q-1);

    for(d=1;d<phi;d++)
        if((e*d)%phi==1)
            break;

    printf("p = %d\n",p);
    printf("q = %d\n",q);
    printf("Phi = %d\n",phi);
    printf("Private key d = %d\n",d);

    return 0;
}
