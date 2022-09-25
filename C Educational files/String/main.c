#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    puts("Enter your name");
    /*ar username[10];
    scanf("%s", username);
    for(int i =0; i<10; i++){
        printf("%c -- %d\n", username[i], username[i]);
    }*/
  //char username[10] = {'s', 'i', 'n', 'a', '\0'};
   char username[20];
   char string2[50] = "hello, world";
   string2[4]=0;
   strcpy(username, string2);
   int len = strlen(string2);
   printf("len of string2 is %d\n", len);
    printf("%s\n", username);
    return 0;
}
