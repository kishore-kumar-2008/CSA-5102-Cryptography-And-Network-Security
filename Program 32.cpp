#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int k1,k2;

    srand(time(NULL));

    k1=rand()%100+1;
    k2=rand()%100+1;

    printf("Message = HELLO\n");

    printf("First signature  uses k = %d\n",k1);
    printf("Second signature uses k = %d\n",k2);

    printf("\nTherefore signatures are different.\n");

    printf("\nDSA uses a new random k for every signature.\n");

    printf("If k is reused, the private key may be recovered.\n");

    return 0;
}
