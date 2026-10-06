#include <stdio.h>

int main()
{
    char a = 'A';
    signed char b = -10;
    unsigned char c = 10;
    signed short d = -20;
    unsigned short e = 20;
    signed int f = -30;
    unsigned int g = 30;
    signed long int h = -40;
    unsigned long int i = 40;
    signed long long int j = -50;
    unsigned long long int k = 50;
    float l = 1.5;
    double m = 2.5;
    long double n = 3.5;

    printf("%c\n", a);
    printf("%hhd\n", b);
    printf("%hhu\n", c);
    printf("%hd\n", d);
    printf("%hu\n", e);
    printf("%d\n", f);
    printf("%u\n", g);
    printf("%ld\n", h);
    printf("%lu\n", i);
    printf("%lld\n", j);
    printf("%llu\n", k);
    printf("%f\n", l);
    printf("%f\n", m);
    printf("%Lf\n", n);

    return 0;
}
