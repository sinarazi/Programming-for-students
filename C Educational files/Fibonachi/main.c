#include <stdio.h>
#include <stdlib.h>

void scan_function();
int fibonachi_functin();
int n;
int main()
{
    scan_function();
    printf("The output is: %d\n", fibonachi_functin(n));
    return 0;
}

void scan_function()
{
    puts("Enter your number :");
    scanf("%d", &n);
}

int fibonachi_functin(int n)
{
    if(n==0 || n==1){
        return 1;
    }
    else{
        return fibonachi_functin(n-2) + fibonachi_functin(n-1);
    }
}


