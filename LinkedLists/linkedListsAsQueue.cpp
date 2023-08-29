#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *front, *rear;
void insrtlast()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data:");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (front == NULL)
    {
        front = rear = temp;
        return;
    }
    else
    {
        rear->next = temp;
        rear = temp;
        return;
    }
}
void del()
{
    struct node *temp;
    if (front == NULL)
    {
        printf("Queue Empty.");
        return;
    }
    temp = front;
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    temp = front;
    if (rear == NULL)
    {
        printf("List empty :(");
        return;
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
    int ch;

    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter the choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insrtlast();
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("invalid choice..");
        }
    }
    getch();
}
