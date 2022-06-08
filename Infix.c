#include <stdio.h>
#include <math.h>
#define STACKSIZE 50

struct stack
{
    int top;
    char items[STACKSIZE];
};

int isEmpty(struct stack *stack)
{
    if (stack->top == -1)
        return 1;
    else
        return 0;
}

char pop(struct stack *stack)
{
    return (stack->items[(stack->top)--]);
}

char peek(struct stack *stack)
{
    return (stack->items[stack->top]);
}

void push(struct stack *stack, char x)
{
    if (stack->top == STACKSIZE - 1)
    {
        printf("Stack Overflow. Cannot push \n");
    }
    else
        stack->items[++(stack->top)] = x;
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9');
}

int Prec(char ch)
{
    switch (ch)
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

float Operation(char operator, float opnd1, float opnd2)
{
    switch (operator)
    {
    case '+':
        return (opnd1 + opnd2);
    case '-':
        return (opnd1 - opnd2);
    case '*':
        return (opnd1 * opnd2);
    case '/':
        return (opnd1 / opnd2);
    case '^':
        return pow(opnd1, opnd2);
    }
}

void PostfixEval(char exp[50])
{
    float opnd1, opnd2, result;
    struct stack stack;
    printf("Enter the values of follwing variables:\n");
    for (int i = 0; exp[i]; i++)
    {
        if (isOperand(exp[i]))
        {
            printf("%c= ", exp[i]);
            exp[i] = getchar();
            getchar();
        }
    }
    printf("%s\n", exp);
    for (int i = 0; exp[i]; i++)
    {
        if (isOperand(exp[i]))
        {
            push(&stack, exp[i]);
        }
        else
        {
            opnd2 = pop(&stack) - '0';
            opnd1 = pop(&stack) - '0';
            result = Operation(exp[i], opnd1, opnd2);
            push(&stack, result + '0');
        }
    }
    printf("The answer of the following expression is %f", result);
}

int InfixToPostfix(char exp[50])
{
    char temp;
    int i, k;
    struct stack stack;
    stack.top = -1;
    for (i = 0, k = -1; exp[i]; ++i)
    {
        if (isOperand(exp[i]))
            exp[++k] = exp[i];

        else if (exp[i] == '(')
            push(&stack, exp[i]);

        else if (exp[i] == ')')
        {
            while (!isEmpty(&stack) && peek(&stack) != '(')
                exp[++k] = pop(&stack);
            if (!isEmpty(&stack) && peek(&stack) != '(')
                return -1;
            else
                pop(&stack);
        }
        else
        {
            while (!isEmpty(&stack) && Prec(exp[i]) <= Prec(peek(&stack)))
            {
                if (Prec(exp[i]) == 3 && Prec(peek(&stack)) == 3)
                    break;
                exp[++k] = pop(&stack);
            }
            push(&stack, exp[i]);
        }
    }

    while (!isEmpty(&stack))
        exp[++k] = pop(&stack);

    exp[++k] = '\0';
    printf("%s\n", exp);
    PostfixEval(exp);
}

int main()
{
    char ie[50];
    printf("Enter the expression in infix form:\n");
    gets(ie);
    InfixToPostfix(ie);
}
