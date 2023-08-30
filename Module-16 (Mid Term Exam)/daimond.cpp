#include <stdio.h>
void pattren6(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * n - (2 * i + 1); j++)
        {
            printf("*");
        }
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}
void pattren7(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++)
        {
            printf("*");
        }
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        printf("\n");
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    pattren7(n);
    pattren6(n);
}