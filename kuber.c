#include <stdio.h>

int main()
{

    int c1=0, c2=0, c3=0, i;

    char string[15];

    printf("Enter your String : ");

    gets(string);

    for (i = 0; string[i] == 'a'; i++)

    {

        c1++;
    }

    for (; string[i] == 'b'; i++)

    {

        c2++;
    }

    for (; string[i] == 'c'; i++)

    {

        c3++;
    }

    if (c1 == c2 + c3)

    {

        printf("It is a valid String");
    }

    else

    {

        printf("It is not a valid String");
    }

    return 0;
}