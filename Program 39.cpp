#include <stdio.h>
#include <ctype.h>

int main()
{
    char c[500];

    printf("Enter ciphertext: ");
    fgets(c,500,stdin);

    for(int k=0;k<26;k++)
    {
        printf("\nKey %d: ",k);

        for(int i=0;c[i];i++)
        {
            if(isalpha(c[i]))
            {
                char b=isupper(c[i])?'A':'a';

                putchar((c[i]-b-k+26)%26+b);
            }
            else
                putchar(c[i]);
        }
    }

    return 0;
}
