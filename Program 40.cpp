#include <stdio.h>
#include <ctype.h>

int main()
{
    char text[1000];
    int f[26]={0};

    printf("Enter ciphertext:\n");
    fgets(text,1000,stdin);

    for(int i=0;text[i];i++)
        if(isalpha(text[i]))
            f[toupper(text[i])-'A']++;

    printf("\nFrequency ranking:\n");

    for(int x=0;x<26;x++)
    {
        int max=-1,pos=-1;

        for(int i=0;i<26;i++)
            if(f[i]>max)
            {
                max=f[i];
                pos=i;
            }

        if(max==0) break;

        printf("%c : %d\n",'A'+pos,max);
        f[pos]=-1;
    }

    printf("\nLikely English order:\n");
    printf("E T A O I N S H R D L C U M W F G Y P B V K J X Q Z\n");

    return 0;
}
