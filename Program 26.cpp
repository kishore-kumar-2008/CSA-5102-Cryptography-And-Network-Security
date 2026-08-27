#include <stdio.h>

int main()
{
    printf("Bob's private key is leaked.\n");

    printf("\nBob generates a new e and d.\n");

    printf("If the same modulus n is used,\n");
    printf("the system is NOT secure.\n");

    printf("\nReason:\n");
    printf("The leaked key can help recover the factors\n");
    printf("p and q of n.\n");

    printf("\nTherefore Bob must generate a new n,\n");
    printf("as well as new e and d.\n");

    return 0;
}
