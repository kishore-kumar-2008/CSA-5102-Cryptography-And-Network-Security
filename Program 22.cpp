#include <stdio.h>

int P10[] = {3,5,2,7,4,10,1,9,8,6};
int P8[]  = {6,3,7,4,8,5,10,9};
int IP[]  = {2,6,3,1,4,8,5,7};
int IP1[] = {4,1,3,5,7,2,8,6};
int EP[]  = {4,1,2,3,2,3,4,1};
int P4[]  = {2,4,3,1};

int S0[4][4] = {
    {1,0,3,2},
    {3,2,1,0},
    {0,2,1,3},
    {3,1,3,2}
};

int S1[4][4] = {
    {0,1,2,3},
    {2,0,1,3},
    {3,0,1,0},
    {2,1,0,3}
};

void permute(int *in, int *out, int *p, int n) {
    for(int i=0;i<n;i++)
        out[i] = in[p[i]-1];
}

void leftShift(int *a, int n) {
    int t = a[0];
    for(int i=0;i<n-1;i++)
        a[i] = a[i+1];
    a[n-1] = t;
}

void keyGeneration(int *key, int *K1, int *K2) {
    int p10[10], l[5], r[5], temp[10];

    permute(key,p10,P10,10);

    for(int i=0;i<5;i++) {
        l[i]=p10[i];
        r[i]=p10[i+5];
    }

    leftShift(l,5);
    leftShift(r,5);

    for(int i=0;i<5;i++) {
        temp[i]=l[i];
        temp[i+5]=r[i];
    }

    permute(temp,K1,P8,8);

    leftShift(l,5);
    leftShift(r,5);

    leftShift(l,5);
    leftShift(r,5);

    for(int i=0;i<5;i++) {
        temp[i]=l[i];
        temp[i+5]=r[i];
    }

    permute(temp,K2,P8,8);
}

int sbox(int *x, int s[4][4]) {
    int row = x[0]*2+x[3];
    int col = x[1]*2+x[2];
    return s[row][col];
}

void fk(int *bits, int *key) {
    int left[4], right[4], ep[8], temp[8], p4[4];
    int sleft[4], sright[4];

    for(int i=0;i<4;i++) {
        left[i]=bits[i];
        right[i]=bits[i+4];
    }

    permute(right,ep,EP,8);

    for(int i=0;i<8;i++)
        temp[i]=ep[i]^key[i];

    int val=sbox(temp,S0);
    sleft[0]=(val>>1)&1;
    sleft[1]=val&1;

    val=sbox(temp+4,S1);
    sright[0]=(val>>1)&1;
    sright[1]=val&1;

    int four[4]={sleft[0],sleft[1],sright[0],sright[1]};
    permute(four,p4,P4,4);

    for(int i=0;i<4;i++)
        left[i]^=p4[i];

    for(int i=0;i<4;i++)
        bits[i]=left[i];

    for(int i=0;i<4;i++)
        bits[i+4]=right[i];
}

void swapHalves(int *b) {
    for(int i=0;i<4;i++) {
        int t=b[i];
        b[i]=b[i+4];
        b[i+4]=t;
    }
}

void sdesEncrypt(int *plain,int *K1,int *K2,int *cipher) {
    int b[8],t[8];

    permute(plain,b,IP,8);

    fk(b,K1);
    swapHalves(b);
    fk(b,K2);

    permute(b,cipher,IP1,8);
}

void sdesDecrypt(int *cipher,int *K1,int *K2,int *plain) {
    int b[8];

    permute(cipher,b,IP,8);

    fk(b,K2);
    swapHalves(b);
    fk(b,K1);

    permute(b,plain,IP1,8);
}

void printBits(int *b,int n) {
    for(int i=0;i<n;i++)
        printf("%d",b[i]);
}

int main() {

    int key[10]={0,1,1,1,1,1,1,1,0,1};
    int IV[8]={1,0,1,0,1,0,1,0};

    int P1[8]={0,0,0,0,0,0,0,1};
    int P2[8]={0,0,1,0,0,0,1,1};

    int K1[8],K2[8];
    int C1[8],C2[8];
    int temp[8],D1[8],D2[8];

    keyGeneration(key,K1,K2);

    for(int i=0;i<8;i++)
        temp[i]=P1[i]^IV[i];

    sdesEncrypt(temp,K1,K2,C1);

    for(int i=0;i<8;i++)
        temp[i]=P2[i]^C1[i];

    sdesEncrypt(temp,K1,K2,C2);

    printf("CBC Ciphertext: ");
    printBits(C1,8);
    printf(" ");
    printBits(C2,8);

    sdesDecrypt(C1,K1,K2,temp);

    for(int i=0;i<8;i++)
        D1[i]=temp[i]^IV[i];

    sdesDecrypt(C2,K1,K2,temp);

    for(int i=0;i<8;i++)
        D2[i]=temp[i]^C1[i];

    printf("\nDecrypted: ");
    printBits(D1,8);
    printf(" ");
    printBits(D2,8);

    return 0;
}
