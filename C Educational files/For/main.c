#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*printf("enter the number\n");
    int n;
    scanf("%d", &n);
    for(int i=0; i< n;i++){
        for(int j = 0; j<i; j++ ){
            printf("* " );
        }
        printf("\n");
    }*/
    int i;
    for(i=0; i<10; i= i+2){
        if(i==5)
            continue;
        else
            printf("%d\n", i);
    }

    return 0;
}
