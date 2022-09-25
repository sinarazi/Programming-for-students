#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*int i=0;
    puts("please enter n :");
    int n;
    scanf("%d", &n);
    while(i< n){
        printf("%d\n", i);
        i++;
    }
    printf("Hello world!\n");*/
    int i=0;
    puts("please enter n :");
    int n;
    int sum=0;

    do{
        scanf("%d", &n);
        sum = sum + n;
    }
    while(n !=0);
    printf("the sum is : %d", sum);
    return 0;
}
