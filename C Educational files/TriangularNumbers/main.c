#include <stdio.h>
#include <stdlib.h>

int main()
{
    puts("Enter the numbers :");
    int a; int b; int c;
    scanf("%d%d%d", &a, &b, &c);
    if(a < b + c && b < a + c && c < a + b)
        printf("Triangular");
    else
        printf("None");
    return 0;
}
