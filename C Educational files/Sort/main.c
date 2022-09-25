#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void print_array(int num_array[], int size);
void bubble_sort(int num_array[], int size);

int main()
{
    int num_size;
    puts("Select the size:");

    scanf("%d", &num_size);
    int nums[num_size];
    printf("Enter the numbers:\n");
    for(int i =0; i<num_size; i++){
        scanf("%d", &nums[i]);
    }
    print_array(nums, num_size);
    bubble_sort(nums, num_size);
    print_array(nums, num_size);
    return 0;
}


void print_array(int num_array[], int size)
{
    for(int i=0; i<size; ++i){
        printf("%d ", num_array[i]);
    }
    puts(" ");
}

void bubble_sort(int num_array[], int size)
{
    int i,j;
    for(i=0; i<size-1; i++){
        for(j = 0; i<size-i-1; j++){
            if(num_array[j+1] < num_array[j])
                swap(&num_array[j], &num_array[j+1]);

        }
    }
}
