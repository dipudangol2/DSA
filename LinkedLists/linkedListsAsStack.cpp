#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *tos;
void push()
{
    int x;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d", &x);
    temp->data = x;
    if (tos == NULL)
    {
        temp->next = NULL;
        tos = temp;
    }
    else
    {
        temp->next = tos;
        tos = temp;
    }
}
int pop()
{
    struct node *temp;
    int data;
    if (tos == NULL)
    {
        printf("Stack Empty!");
        return;
    }
    else
    {
        temp = tos;
        data = temp->data;
        tos = tos->next;
        free(temp);
        return data;
    }
}
void display()
{
    struct node *temp;
    temp = tos;
    if (tos == NULL)
    {
        printf("Stack empty!");
        return;
    }
    else
    {
        while (temp->next != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}
int main()
{
    int ch;
    while (1)
    {

        printf("\n1.Push \n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter the choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            printf("The popped element is:%d", pop());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice!");
        }
    }
    getch();
}
