#include <stdio.h>

int main()
{
    char c = 10;
    short s = 20;
    int i = 30;
    long int l = 40;
    long long int ll = 50;
    float f = 1.5f;
    double d = 2.5;
    long double ld = 3.5L;

    char *pc = &c;
    short *ps = &s;
    int *pi = &i;
    long int *pl = &l;
    long long int *pll = &ll;
    float *pf = &f;
    double *pd = &d;
    long double *pld = &ld;

    printf("Avant :\n");
    printf("c  : %p -> %x\n", (void *)pc, (unsigned int)*pc);
    printf("s  : %p -> %x\n", (void *)ps, (unsigned int)*ps);
    printf("i  : %p -> %x\n", (void *)pi, (unsigned int)*pi);
    printf("l  : %p -> %lx\n", (void *)pl, (unsigned long)*pl);
    printf("ll : %p -> %llx\n", (void *)pll, (unsigned long long)*pll);
    printf("f  : %p -> %a\n", (void *)pf, (double)*pf);
    printf("d  : %p -> %a\n", (void *)pd, *pd);
    printf("ld : %p -> %La\n", (void *)pld, *pld);

    *pc = 11;
    *ps = 21;
    *pi = 31;
    *pl = 41;
    *pll = 51;
    *pf = 2.5f;
    *pd = 3.5;
    *pld = 4.5L;

    printf("\nApres :\n");
    printf("c  : %p -> %x\n", (void *)pc, (unsigned int)*pc);
    printf("s  : %p -> %x\n", (void *)ps, (unsigned int)*ps);
    printf("i  : %p -> %x\n", (void *)pi, (unsigned int)*pi);
    printf("l  : %p -> %lx\n", (void *)pl, (unsigned long)*pl);
    printf("ll : %p -> %llx\n", (void *)pll, (unsigned long long)*pll);
    printf("f  : %p -> %a\n", (void *)pf, (double)*pf);
    printf("d  : %p -> %a\n", (void *)pd, *pd);
    printf("ld : %p -> %La\n", (void *)pld, *pld);

    return 0;
}