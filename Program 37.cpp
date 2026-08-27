#include <stdio.h>
#include <ctype.h>

int main()
{
    char c[1000];
    int f[26]={0};

    printf("Enter ciphertext:\n");
    fgets(c,1000,stdin);

    for(int i=0;c[i];i++)
        if(isalpha(c[i]))
            f[toupper(c[i])-'A']++;

    printf("\nLetter frequencies:\n");

    for(int i=0;i<26;i++)
        printf("%c = %d\n",'A'+i,f[i]);

    printf("\nEnglish frequency order:\n");
    printf("ETAOINSHRDLCUMWFGYPBVKJXQZ\n");

    printf("\nUse high-frequency letters as likely E,T,A,O.\n");

    return 0;
}
