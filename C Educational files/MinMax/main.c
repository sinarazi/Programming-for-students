#include <stdio.h>
#include <stdlib.h>

int main()
{
int n, s1, s2, z;
    printf(" How many Integer numbers : ");
    scanf("%d", &n);
    z=n;
    if(n>0){
        printf("\n Enter the First number : ");
        scanf("%d", &s1);
        n--;
        if(n>0){
        for(;n>=1; n--){
            printf("\n Enter the next number : ");
            scanf("%d", &s2);
            if(s1<s2)
                s1=s2;
                }
            }
        }
        printf("\n The Max of %d numbers is %d\n", z, s1);


    printf(" : \n");
    printf(" How many Integer numbers : \n");
    scanf("%d", &n);
    z=n;
        if(n>0){
        printf("\n Enter the First number : ");
        scanf("%d", &s1);
        n--;
        if(n>0){
        for(;n>=1; n--){
            printf("\n Enter the next number : ");
            scanf("%d", &s2);
            if(s2<s1)
                s1=s2;
                }
            }
        }
        printf("\n The Min of %d numbers is %d\n", z, s1);
    return(0);
}
