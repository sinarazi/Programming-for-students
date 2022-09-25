#include <stdio.h>
#include <stdlib.h>

void reverse_function();
int main()
{
    puts("enter the number");
    reverse_function();
    return 0;
}

void reverse_function()
{
    int i;
    int number, n;
    scanf("%d", n);

    for(i=n; i>0 && number!=-1; i--){
            scanf("%d", number);
        if(number == -1){
            printf("the output is: %d\n", number);
        }
    }
}
