#include <stdio.h>

int inv(int x)
{
    for(int i=1;i<26;i++)
        if(x*i%26==1) return i;
    return -1;
}

int main()
{
    int P[2][2],C[2][2],K[2][2];
    int d,di;

    printf("Enter plaintext matrix:\n");

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            scanf("%d",&P[i][j]);

    printf("Enter ciphertext matrix:\n");

    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            scanf("%d",&C[i][j]);

    d=(P[0][0]*P[1][1]-P[0][1]*P[1][0]+26)%26;
    di=inv(d);

    if(di==-1)
    {
        printf("Matrix not invertible.");
        return 0;
    }

    K[0][0]=C[0][0]*P[1][1]-C[0][1]*P[1][0];
    K[0][1]=-C[0][0]*P[0][1]+C[0][1]*P[0][0];
    K[1][0]=C[1][0]*P[1][1]-C[1][1]*P[1][0];
    K[1][1]=-C[1][0]*P[0][1]+C[1][1]*P[0][0];

    printf("Recovered key:\n");

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            printf("%d ",(K[i][j]*di%26+26)%26);
        printf("\n");
    }

    return 0;
}
