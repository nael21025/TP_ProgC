#include <stdio.h>

int main()
{
    unsigned int d = (1u << 28) | (1u << 12);

    if ((d & (1u << 28)) && (d & (1u << 12)))
        printf("1\n");
    else
        printf("0\n");

    return 0;
}
