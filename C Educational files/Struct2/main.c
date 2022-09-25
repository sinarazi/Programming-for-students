#include <stdio.h>
#include <stdlib.h>

#define MAX_STR_LEN 50
/*struct student
{
    char first_name[MAX_STR_LEN];
    char last_name[MAX_STR_LEN];
    int entrance_year;
    float average;
};

void reduce_entrance_year(struct student *s)
{
    s->entrance_year --;
}

int main()
{
    struct student s2= {"Alex", "Jordan", 2001, 15.3};
    struct student *pointer_to_student = &s2;
    printf("%s\n", (*pointer_to_student).first_name);
    printf("%s\n", pointer_to_student->last_name);
    printf("%d\n", s2.entrance_year);
    reduce_entrance_year(&s2);
    printf("%d\n", s2.entrance_year);

    return 0;
}*/

/*union number
{
    int int_value;
    float floating_value;
};

int main()
{
    union number n1;
    n1.int_value=2;
    printf("%d %d\n", n1.int_value, n1.floating_value);
    n1.floating_value=4.7;
    printf("%d %d\n", n1.int_value, n1.floating_value);
    return 0;
}*/

enum mounths
{
    Jan =1,
    Feb,
};

int main()
{
 enum mounths m;
 m = Feb;
 printf("%d",m);
 //you can use switch case
    return 0;
}
