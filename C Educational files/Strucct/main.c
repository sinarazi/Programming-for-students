#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 50
#define STUDENTS_COUNT 10

struct student
{
    char first_name[MAX_STR_LEN];
    char last_name[MAX_STR_LEN];
    int entrance_year;
    float average;
};
int main()
{
    struct student s1[STUDENTS_COUNT];
    for(int i=0; i<STUDENTS_COUNT; i++){
    printf("please enter %d first name: ",i+1 );
    scanf("%s", s1[i].first_name);
    printf("please enter %d last name: ", i+1);
    scanf("%s", s1[i].last_name);
    printf("please enter %d entrance year: ", i+1);
    scanf("%d", &s1[i].entrance_year);
    printf("please enter %d average: ", i+1);
    scanf("%sf", &s1[i].average);
    }
    printf("ID\tFirstName\tLastName\tEntranceYear\tAverage\n");
    for(int i=0; i<STUDENTS_COUNT; i++){
         printf("%d\t%s\t%s\t%d\t%f\n",i+1,
                s1[i].first_name, s1[i].last_name, s1[i].entrance_year, s1[i].average);
    }

    return 0;
}
