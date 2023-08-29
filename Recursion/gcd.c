#include <stdio.h>

int GCD(int a, int b)
{
    int result = ((a < b) ? a : b);
    while (result > 0)
    {
        if (a % result == 0 && b % result == 0)
        {
            break;
        }
        result--;
    }
    return result;
}

int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);
    int gcd = GCD(a, b);
    printf("GCD(%d,%d)=%d\n", a, b, gcd);
    return 0;
}