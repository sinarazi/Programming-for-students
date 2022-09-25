#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter number of array elements: ");

       float sum = 0;
       int j;
       scanf("%d", &j);
       int num[j];
       printf("Enter array elements:\n");

       for (int i = 0; i < j; i++)

             scanf("%d", &num[i]);


            printf("Array elements in reverse order:\n");

       for (int i = 0; i < j; i++)

            sum+= num[i];
            printf("%f ", sum/j);

            printf("\n");

    return 0;
}
