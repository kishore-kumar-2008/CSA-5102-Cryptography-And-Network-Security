#include <stdio.h>

unsigned long long shift(unsigned long long x)
{
    return x<<1;
}

int main()
{
    unsigned long long L,K1,K2;

    printf("Enter L in hexadecimal: ");
    scanf("%llx",&L);

    K1=shift(L);

    if(L&0x8000000000000000ULL)
        K1^=0x1B;

    K2=shift(K1);

    if(K1&0x8000000000000000ULL)
        K2^=0x1B;

    printf("K1 = %llX\n",K1);
    printf("K2 = %llX\n",K2);

    printf("\n64-bit Rb  = 1B");
    printf("\n128-bit Rb = 87");

    return 0;
}
