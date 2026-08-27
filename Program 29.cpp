#include <stdio.h>

int main()
{
    int capacity[25]={0};

    printf("SHA-3 Capacity Lane Analysis\n\n");

    printf("Initial capacity lanes:\n");

    for(int i=0;i<25;i++)
        printf("%d ",capacity[i]);

    printf("\n\nPermutation is ignored.\n");

    printf("Therefore non-zero bits from the rate\n");
    printf("portion never enter capacity lanes.\n");

    printf("\nAll capacity lanes remain zero.\n");

    printf("\nTime required = NEVER\n");

    return 0;
}
