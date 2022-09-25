#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x;
    scanf("%d",&x);
    float fx = pow(sin(x), 2) + pow(cos(x), 2);

    printf("the result is %f", fx);
    return 0;
}
