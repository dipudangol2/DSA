#include <stdio.h>
int fact(int);
int main()
{
    int num;
    printf("Enter a number to find the factorial of: ");
    scanf("%d", &num);
    int factorial = fact(num);
    printf("%d! = %d\n", num, factorial);
    return 0;
}
int fact(int f)
{
    if (f == 0 || f == 1)
        return 1;
    else
        return (f * fact(f - 1));
}
