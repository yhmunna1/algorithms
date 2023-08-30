#include <stdio.h>

void patternHeart(int n)
{
    for (int i = n / 2; i <= n; i += 2)
    {
        for (int j = 1; j < n - i; j += 2)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        for (int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j < n; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= (i * 2) - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    patternHeart(n);
    return 0;
}
