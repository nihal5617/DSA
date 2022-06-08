#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)
        malloc(sizeof(struct Stack));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;

    stack->array = (int *)malloc(stack->capacity * sizeof(int));

    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

char peek(struct Stack *stack)
{
    return stack->array[stack->top];
}

char pop(struct Stack *stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack *stack, char op)
{
    stack->array[++stack->top] = op;
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

int eval()
{
    char exp[100];
    float opnd1, opnd2;
    float result;
    printf("Enter the postfix expression to be evaluated: ");
    scanf("%s", exp);
    struct Stack *stack = createStack(strlen(exp));
    if (!stack)
        return -1;
    for (int i = 0; exp[i]; i++)
    {
        if (isOperand(exp[i]))
        {
            push(stack, exp[i]);
        }
        else
        {
            opnd2 = pop(stack) - '0';
            opnd1 = pop(stack) - '0';
            result = Operation(exp[i], opnd1, opnd2);
            push(stack, result + '0');
        }
    }
    printf("The answer of the following expression is %f", result);
}

int InfixToPostfix()
{
    char exp[100], temp;
    int i, k;
    printf("Enter Infix expression: ");
    scanf("%s", exp);
    struct Stack *stack = createStack(strlen(exp));
    if (!stack)
        return -1;

    for (i = 0, k = -1; exp[i]; ++i)
    {
        if (isOperand(exp[i]))
            exp[++k] = exp[i];

        else if (exp[i] == '(')
            push(stack, exp[i]);

        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1;
            else
                pop(stack);
        }
        else
        {
            while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
            {
                if (Prec(exp[i]) == 3 && Prec(peek(stack)) == 3)
                    break;
                exp[++k] = pop(stack);
            }
            push(stack, exp[i]);
        }
    }

    while (!isEmpty(stack))
        exp[++k] = pop(stack);

    exp[++k] = '\0';
    printf("%s\n", exp);
}

int main()
{
    InfixToPostfix();
    return 0;
}
