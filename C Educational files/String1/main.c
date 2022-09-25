#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 50

int main()
{
    char string1[MAX_STR_LEN];
    char string2[MAX_STR_LEN];
     strcpy(string1, "Hello ");
     strcpy(string2, "World ");

     printf("String1 =%s\tstring2 = %s\n", string1, string2);
     strcat(string1, string2);
     printf("String1 =%s\tstring2 = %s\n", string1, string2);

    if(strcmp(string1, string2) == 0){
        printf("two string are the same\n");
    }else{
        printf("not matched\n");
    }
    return 0;
}
