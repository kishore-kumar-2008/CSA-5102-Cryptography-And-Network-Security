#include <stdio.h>

int main()
{
    int X,T,second;

    printf("Enter X: ");
    scanf("%X",&X);

    printf("Enter MAC T: ");
    scanf("%X",&T);

    second=X^T;

    printf("\nOriginal message = %02X\n",X);
    printf("MAC = %02X\n",T);

    printf("\nForged message:\n");
    printf("%02X || %02X\n",X,second);

    printf("\nCBC-MAC of forged message = %02X\n",T);

    printf("\nThis demonstrates CBC-MAC forgery.");

    return 0;
}
