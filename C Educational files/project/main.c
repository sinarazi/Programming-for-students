#include <stdio.h>
#include <stdlib.h>
int Fib(int n)
{
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }
    else{
        return Fib(n-1) + Fib(n-2);
    }
}
int main()
{
    int n;
    printf("please enter number\n");
    scanf("%d", &n);
    int res = Fib(n);
    printf("%d", res);
    return 0;

}
