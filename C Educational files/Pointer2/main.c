#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*int a[5] = {1, 2, 3, 4, 5};
   /* printf("%p\n", a);
    printf("%p\n", &a[0]); /

    int *p =a;
    for(int i =0; i<5; i++){
        printf("%d\n", (*p));
        p++;
    }*/

    int *a = malloc(4 * sizeof(int)); // heap memory
    a[0]=1;
    a[1]= 2;
    printf("%d %d\n", a[0], a[1] );

    return 0;
}
