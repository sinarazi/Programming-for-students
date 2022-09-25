#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter number of array elements: ");

       int j;
       scanf("%d", &j);
       int num[30];
       printf("Enter array elements:\n");

       for (int i = 0; i < j; i++) //sabt be sorate araye

             scanf("%d", &num[i]);


            printf("Array elements in reverse order:\n");

       for (int i = j - 1; i >= 0; i--)   //barax kardan

            printf("%d ", num[i]);

            printf("\n");

    return 0;
}
