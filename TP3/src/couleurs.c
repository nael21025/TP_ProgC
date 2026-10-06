#include <stdio.h>

struct Couleur
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};

int main()
{
    struct Couleur couleurs[5] = {
        {0xff, 0x00, 0x00, 0xff},
        {0x00, 0xff, 0x00, 0xff},
        {0x00, 0x00, 0xff, 0xff},
        {0xff, 0xff, 0x00, 0xff},
        {0xff, 0xff, 0xff, 0xff}
    };
    int i;

    for (i = 0; i < 5; i++)
        printf("%02x %02x %02x %02x\n",
               couleurs[i].r, couleurs[i].g,
               couleurs[i].b, couleurs[i].a);

    return 0;
}