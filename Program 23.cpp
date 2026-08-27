#include <stdio.h>

int sdes(int x, int key)
{
    return (x ^ key) & 255;   // simplified S-DES operation
}

int main()
{
    int p[3] = {1, 2, 4};
    int c[3], d[3], key = 0xFD;
    int counter = 0;

    printf("Encryption:\n");
    for(int i=0;i<3;i++)
    {
        c[i] = p[i] ^ sdes(counter++,key);
        printf("%02X ",c[i]);
    }

    counter=0;
    printf("\nDecryption:\n");
    for(int i=0;i<3;i++)
    {
        d[i] = c[i] ^ sdes(counter++,key);
        printf("%02X ",d[i]);
    }

    return 0;
}
