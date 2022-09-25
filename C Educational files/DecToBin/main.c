#include <stdio.h>
#include <stdlib.h>

void decToBinary(int n)
{
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)

        printf("%d",binaryNum[j]);
}
int main()
{
    puts("Enter the decimal number:");
    int n;
    scanf("%d", &n);
    decToBinary(n);
    return 0;
}
