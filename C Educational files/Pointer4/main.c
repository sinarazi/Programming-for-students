#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a = malloc(20 * sizeof(int));
    printf("%d\n", sizeof(a)); // only size of pointer
    int b[10];
    printf("%d\n", sizeof(b));
    return 0;
}
