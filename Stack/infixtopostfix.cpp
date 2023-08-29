// infix to postfix conversion
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct
{
    char items[MAX_SIZE];
    int top;
} Stack;

void initializeStack(Stack *s)
{
    s->top = -1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char c)
{
    if (isFull(s))
    {
        printf("Stack overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = c;
}

char pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

int isOperand(char c)
{
    return isalpha(c) || isdigit(c);
}

int precedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

void infixToPostfix(char *expression)
{
    Stack stack;
    initializeStack(&stack);

    char postfix[MAX_SIZE];
    int postfixIndex = 0;

    int i = 0;
    while (expression[i] != '\0')
    {
        char currentChar = expression[i];

        if (isOperand(currentChar))
        {
            postfix[postfixIndex++] = currentChar;
        }
        else if (currentChar == '(')
        {
            push(&stack, currentChar);
        }
        else if (currentChar == ')')
        {
            while (!isEmpty(&stack) && stack.items[stack.top] != '(')
            {
                postfix[postfixIndex++] = pop(&stack);
            }
            if (!isEmpty(&stack) && stack.items[stack.top] != '(')
            {
                printf("Invalid expression: Mismatched parentheses\n");
                exit(1);
            }
            else
            {
                pop(&stack); // Pop '('
            }
        }
        else
        {
            while (!isEmpty(&stack) && precedence(currentChar) <= precedence(stack.items[stack.top]))
            {
                postfix[postfixIndex++] = pop(&stack);
            }
            push(&stack, currentChar);
        }

        i++;
    }

    while (!isEmpty(&stack))
    {
        postfix[postfixIndex++] = pop(&stack);
    }

    postfix[postfixIndex] = '\0';

    printf("Postfix expression: %s\n", postfix);
}

int main()
{
    char infix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPostfix(infix);

    return 0;
}
