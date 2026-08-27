#include <stdio.h>
#include <openssl/des.h>

int main()
{
    DES_cblock key={
        0x13,0x34,0x57,0x79,
        0x9B,0xBC,0xDF,0xF1
    };

    DES_key_schedule ks;

    DES_cblock p={
        0x01,0x23,0x45,0x67,
        0x89,0xAB,0xCD,0xEF
    };

    DES_cblock c,d;

    DES_set_key_unchecked(&key,&ks);

    DES_ecb_encrypt(&p,&c,&ks,DES_ENCRYPT);
    DES_ecb_encrypt(&c,&d,&ks,DES_DECRYPT);

    printf("Plaintext : ");

    for(int i=0;i<8;i++)
        printf("%02X",p[i]);

    printf("\nCiphertext: ");

    for(int i=0;i<8;i++)
        printf("%02X",c[i]);

    printf("\nDecrypted : ");

    for(int i=0;i<8;i++)
        printf("%02X",d[i]);

    return 0;
}
