#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void isPalindrome(char str[])
{
    int l = 0;
    int h = strlen(str) - 1;

    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            printf("%s is Not Palindrome", str);
            return;
        }
    }
    printf("%s is palindrome", str);
}

int main()
{
    puts("Enter your favorite string");
    char stringValue[20];
    scanf("%s", stringValue);
    isPalindrome(stringValue);
    return 0;
}
