#include <stdio.h>

int main()
{
    int num1 = 16;
    int num2 = 3;
    char op = '+';

    switch (op)
    {
        case '+':
            printf("%d\n", num1 + num2);
            break;
        case '-':
            printf("%d\n", num1 - num2);
            break;
        case '*':
            printf("%d\n", num1 * num2);
            break;
        case '/':
            printf("%d\n", num1 / num2);
            break;
        case '%':
            printf("%d\n", num1 % num2);
            break;
        case '&':
            printf("%d\n", num1 & num2);
            break;
        case '|':
            printf("%d\n", num1 | num2);
            break;
        case '~':
            printf("%d\n", ~num1);
            break;
    }

    return 0;
}
