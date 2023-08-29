// Write a menu driven program to perform stack operation using array
#include <stdio.h>
#include <conio.h>
#define SIZE 10

int stack[SIZE], top, n, choice, x, i;

void push();
void pop();
void display();

int main()
{

	top = -1;
	printf("Enter the size of STACK : ");
	scanf("%d", &n);
	printf("STACK IMPLETATION USING ARRAY\n");
	do
	{
		printf("1. PUSH   2. POP  3. DISPLAY  4.EXIT\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		case 4:
			break;
		default:
			printf("\n Invalid choice");
		}
	} while (choice != 4);

	getch();

	return 0;
}

void push()
{
	if (top >= n - 1)
	{
		printf("\n STACK OVERFLOW");
	}
	else
	{
		printf("Enter a value to be pushed : ");
		scanf("%d", &x);
		top++;
		stack[top] = x;
	}
}

void pop()
{
	if (top <= -1)
	{
		printf("\n STACK UNDERFLOW");
	}
	else
	{
		printf("The popped element is %d \n", stack[top]);
		top--;
	}
}

void display()
{
	if (top >= 0)
	{
		printf("Elements in the stack: ");
		for (i = 0; i <= top; i++)
		{
			printf("%d\t", stack[i]);
		}
		printf("\n");
	}
	else
	{
		printf("\n Empty stack");
	}
}
