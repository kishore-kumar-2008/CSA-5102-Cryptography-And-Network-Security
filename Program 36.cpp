#include <stdio.h>
#include <string.h>

int gcd(int a,int b)
{
    while(b)
    {
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int main()
{
    char p[100];
    int a,b;

    printf("Enter plaintext: ");
    scanf("%s",p);

    printf("Enter a and b: ");
    scanf("%d%d",&a,&b);

    if(gcd(a,26)!=1)
    {
        printf("Invalid a. Not one-to-one.");
        return 0;
    }

    printf("Ciphertext: ");

    for(int i=0;p[i];i++)
    {
        int x=p[i]-'A';
        printf("%c",(a*x+b)%26+'A');
    }

    return 0;
}
