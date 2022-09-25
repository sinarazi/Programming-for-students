#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    const float G=9.8;
    unsigned int t;
    float v0;
    float x0;
    float x;
    x = G * t * t / 2 + v0 * t + x0;
    printf(" x = 1/2 * %f * %d * %d + %f * %d + %f = %f\n", G, t, t, v0, t, x0, x);
    return 0;
}
