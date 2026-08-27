#include <stdio.h>
#include <string.h>

#define BLOCK 8

int main()
{
    char text[100];
    int len;

    printf("Enter plaintext: ");
    fgets(text,100,stdin);

    text[strcspn(text,"\n")]=0;

    len=strlen(text);

    printf("Original length = %d\n",len);

    printf("Padding method: 1 followed by zeros.\n");

    if(len%BLOCK==0)
        printf("Add one complete padding block.\n");
    else
        printf("Pad remaining block with 1 and zeros.\n");

    printf("\nMotivation: padding makes the message\n");
    printf("length and end of data unambiguous.\n");

    return 0;
}
