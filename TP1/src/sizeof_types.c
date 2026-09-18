#include <stdio.h>

int main()
{
    printf("char : %zu\n", sizeof(char));
    printf("signed char : %zu\n", sizeof(signed char));
    printf("unsigned char : %zu\n", sizeof(unsigned char));

    printf("signed short : %zu\n", sizeof(signed short));
    printf("unsigned short : %zu\n", sizeof(unsigned short));

    printf("signed int : %zu\n", sizeof(signed int));
    printf("unsigned int : %zu\n", sizeof(unsigned int));

    printf("signed long int : %zu\n", sizeof(signed long int));
    printf("unsigned long int : %zu\n", sizeof(unsigned long int));

    printf("signed long long int : %zu\n", sizeof(signed long long int));
    printf("unsigned long long int : %zu\n", sizeof(unsigned long long int));

    printf("float : %zu\n", sizeof(float));
    printf("double : %zu\n", sizeof(double));
    printf("long double : %zu\n", sizeof(long double));

    return 0;
}