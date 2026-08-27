#include <stdio.h>
#include <string.h>

int main()
{
    char p[100];
    int key[100],c[100],n;

    printf("Enter plaintext: ");
    scanf("%s",p);

    n=strlen(p);

    printf("Enter key values 0-25:\n");

    for(int i=0;i<n;i++)
        scanf("%d",&key[i]);

    printf("Ciphertext: ");

    for(int i=0;i<n;i++)
    {
        c[i]=(p[i]-'A'+key[i])%26;
        printf("%c",c[i]+'A');
    }

    printf("\nDecrypted: ");

    for(int i=0;i<n;i++)
        printf("%c",(c[i]-key[i]+26)%26+'A');

    return 0;
}
