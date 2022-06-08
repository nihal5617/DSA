#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define STACKSIZE 100

struct stack
{
    int top;
    char items[STACKSIZE];
};

void push(struct stack *ps, char x)
{
    if (ps->top == STACKSIZE - 1)
    {
        printf("Stack Overflow. Cannot push\n");
        getch();
        exit(1);
    }
    ps->items[++(ps->top)] = x;
}

int empty(struct stack *ps)
{
    if (ps->top == -1)
        return 1;
    else
        return 0;
}

char pop(struct stack *ps)
{
    if (empty(ps))
    {
        printf("Stack Underflow. Cannot pop\n");
        getch();
        exit(1);
    }
    return ps->items[(ps->top)--];
}

void show(struct stack *ps)
{
    int i;
    printf("Stack from topmost element is as shown:\n");
    for (i = ps->top; i >= 0; i--)
        printf("%d ", ps->items[i]);
}

void main()
{
    int x, ch;
    struct stack operand, operator;
    char[10] string;
    system("cls");
    operand.top = -1;
    operator.top = - 1;
    gets(string);
    for (int i = 0; string[i] != '\0'; i++)
    {
        switch (string[i])
        {
        case '+':
        case '-':
        case '*':
        case '/':
            push(operator, string[i]); break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            push(operand,string[i]);
            break;
        case ')':
            char a = pop(operand);
            char b = pop(operand);
            char c = pop(operator);
            char[10] buf;
            buf += '(';
            buf += a;
            buf += b;
            buf += c;
            buf += ')';
        }
    }
}