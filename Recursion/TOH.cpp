#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void hanoi(int n, char nd1, char nd2, char nd3)
{
    if (n == 1)
    {
        printf("Move top disk from %c to %c\n", nd1, nd2);
        return;
    }
    hanoi(n - 1, nd1, nd3, nd2);
    printf("Move top disk from %c to %c\n", nd1, nd2);
    hanoi(n - 1, nd3, nd2, nd1);
}

int main()
{
    int no;
    printf("Enter the number of disks to be transferred.\t");
    scanf("%d", &no);
    if (no < 1)
    {
        printf("\nThere is nothing to move");
    }
    else
    {
        printf("\nRecursive\n");
        hanoi(no, 'A', 'B', 'C');
    }
    getch();
    return 0;
}