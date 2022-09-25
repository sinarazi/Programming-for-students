#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *nums = malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d", &nums[i]);
    }
    for(int i =0; i<n; i++){
        printf("d\n", nums[i]);
    }
    free(nums);
    return 0;
}
