#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, c, k, space = 1;

    printf("Enter number of rows\n");
    scanf("%d", &n);

    space = n - 1;

    for (k = 1; k <= n; k++)
    {

        for (c = 1; c <= space; c++)
        printf(" ");

        space--;

        for (c = 1; c <= k; c++)
        printf(" *");

        printf("\n");

    }
    space = 1;

    for (k = 1; k <= n - 1; k++)
    {

        for (c = 1; c <= space; c++)
        printf(" ");

        space++;

        for (c = 1 ; c <= (n-k); c++)
        printf(" *");

        printf("\n");

    }

    return 0;
}
