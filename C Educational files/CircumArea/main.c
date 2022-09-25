#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int pi = 3;
    int r;
    scanf("%d", &r);
    int p;
    int a;
    p = 2 * r * pi;
    a = r * r * pi;
    printf("Perimeter = %d, Area = %d", p, a);
    return 0;
}
