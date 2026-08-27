#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 8

void pad(char *input, char *output) {
    int len = strlen(input);
    int newLen = ((len / BLOCK_SIZE) + 1) * BLOCK_SIZE;

    for (int i = 0; i < newLen; i++)
        output[i] = 0;

    for (int i = 0; i < len; i++)
        output[i] = input[i];

    output[len] = 0x80;   // 10000000
}

int main() {
    char plaintext[100];
    char padded[120];

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    plaintext[strcspn(plaintext, "\n")] = '\0';

    pad(plaintext, padded);

    printf("\nOriginal length = %lu bytes\n", strlen(plaintext));
    printf("Padding applied using 1 followed by 0s.\n");

    printf("\nMotivation for padding an already complete block:\n");
    printf("It makes padding unambiguous during decryption.\n");
    printf("The receiver can always remove the final padding block correctly.\n");

    return 0;
}
