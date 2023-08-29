// Program to implement the linear queue
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define size 5

int front = -1;
int rear = -1;
int queue[size];
void insert();
void deletee();
void display();

int main()
{
	int choice;
	do
	{
		printf("Menu \n");
		printf("1. Insert  ");
		printf("2. Delete  ");
		printf("3. Display  ");
		printf("4. Exit ");
		printf("\n Enter Your Choice:  ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			insert();
			display();
			break;
		case 2:
			deletee();
			//				display();
			break;
		case 3:
			display();
			break;
		case 4:
			printf("End of Program");
			exit(0);
		}

	} while (choice != 4);
}

void insert()
{
	int n;
	printf("Enter no:");
	scanf("%d", &n);
	if (rear < size )
	{
		queue[++rear] = n;
		if (front == -1)
		{
			front = 0;
		}
	}
	else
		{
			printf("\nQueue is full");
		}
}
void deletee()
{
	if (front == -1)
	{
		printf("/nQueue is empty");
		return;
	}
	else
	{
		printf("Delete item = %d \n", queue[front]);
	}
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		front = front + 1;
	}
}

void display()
{
	int i;
	if (front == -1)
	{
		printf("\n Queue is empty\n");
		return;
	}
	for (i = front; i <= rear; i++)
	{
		printf("%d\t", queue[i]);
	}
	printf("\n");
}
