#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8

void xorBlock(char *a, char *b, char *result) {
    for (int i = 0; i < BLOCK_SIZE; i++)
        result[i] = a[i] ^ b[i];
}

void simpleEncrypt(char *plain, char *key, char *cipher) {
    xorBlock(plain, key, cipher);
}

void simpleDecrypt(char *cipher, char *key, char *plain) {
    xorBlock(cipher, key, plain);
}

int main() {
    char P1[BLOCK_SIZE] = "ABCDEFGH";
    char P2[BLOCK_SIZE] = "IJKLMNOP";
    char key[BLOCK_SIZE] = "12345678";

    char C1[BLOCK_SIZE], C2[BLOCK_SIZE];
    char D1[BLOCK_SIZE], D2[BLOCK_SIZE];

    /* ECB */
    simpleEncrypt(P1, key, C1);
    simpleEncrypt(P2, key, C2);

    /* Introduce error in C1 */
    C1[0] ^= 1;

    simpleDecrypt(C1, key, D1);
    simpleDecrypt(C2, key, D2);

    printf("ECB after error:\n");
    printf("P1 = %s\n", D1);
    printf("P2 = %s\n", D2);

    /* CBC */
    char IV[BLOCK_SIZE] = "ABCDEFGH";
    char temp[BLOCK_SIZE];

    xorBlock(P1, IV, temp);
    simpleEncrypt(temp, key, C1);

    xorBlock(P2, C1, temp);
    simpleEncrypt(temp, key, C2);

    /* Error in C1 */
    C1[0] ^= 1;

    simpleDecrypt(C1, key, temp);
    xorBlock(temp, IV, D1);

    simpleDecrypt(C2, key, temp);
    xorBlock(temp, C1, D2);

    printf("\nCBC after error:\n");
    printf("P1 is corrupted\n");
    printf("P2 has a corresponding bit error\n");

    printf("\nAnswers:\n");
    printf("a) No blocks beyond P2 are affected.\n");
    printf("b) A bit error in P1 propagates through C1 and affects C1 and subsequent CBC processing.\n");

    return 0;
}
