#include <stdio.h>
#include "intarith.h"

int main()
{
    char c1 = 'a';
    char c2 = 17;
    char c3 = 0xfe;

    printf("character c1\n  dec=%d\n  hex=%x\n  chr=%c\n", c1, c1, c1);
    printf("character c2\n  dec=%d\n  hex=%x\n  chr=%c\n", c2, c2, c2);
    printf("character c3\n  dec=%d\n  hex=%x\n  chr=%c\n", c3, 0xff&c3, c3);

    return 0;
}