#include <stdio.h>
#include <stdlib.h>

void scan_function();
void print_function();
int factoriel_functin();
int n;
int main()
{
    scan_function();
    factoriel_functin();
    print_function();
    return 0;
}

void scan_function()
{
    puts("Enter your number :");
    scanf("%d", &n);
}

int factoriel_functin(int n)
{
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        return n * factoriel_functin(n-1);
    }
}

void print_function()
{
    printf("The output is: %d\n", factoriel_functin(n));
}
