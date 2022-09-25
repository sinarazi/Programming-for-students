#include <stdio.h>
#include <stdlib.h>

int main()
{
    char my_char = getchar();
    int my_value = my_char;
    int new_value = my_value + 32;
    char new_char = new_value;
    printf("%c\n", new_char);
    return 0;
}
