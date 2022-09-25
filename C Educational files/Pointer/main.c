#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    //char my_char = '=';
    char my_char;
    char *pointer_to_my_char = NULL; // the 0 index of memory

    pointer_to_my_char  = &my_char;
    (*pointer_to_my_char) = 'e';
    printf("%p %c",pointer_to_my_char, *pointer_to_my_char);
    */
    int a = -13;
    int *ptr_a = &a;
    int **ptr_a2 = &ptr_a;
    *(*(ptr_a2))= 12;
    printf("a = %d", a);

    return 0;
}
