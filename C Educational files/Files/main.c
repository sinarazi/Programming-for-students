#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*FILE *file_pointer;
    file_pointer = fopen("data.txt", "w");
    fprintf(file_pointer, "HelloWorld\n");
    fclose(file_pointer);*/
    FILE *file1;
    file1 = fopen("Data1.txt", "w");
    if(file1==NULL){
        printf("file can't be open\n");
    }
    else{
        char usename[50];
        printf("Please enter your username :\n");
        scanf("%s", usename);
        printf("Your user name written on file\n");

        fprintf(file1, "user %s was created", usename);
        fclose(file1);
    }


    return 0;
}
