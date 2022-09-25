#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50
#define SIZE_USE (MAX_SIZE-1)

int div(int inum_first[], int inum_second[], int div_result[], int firstlen, int secondlen)
{
int i;
int check1 = 0, check2 = 0;

int zeroC = 0;

    int tmp[MAX_SIZE];

    for (i = 0; i <= SIZE_USE; i++)
    {
        tmp[i] = 0;
    }

    int inum_firstCP[MAX_SIZE] = { 0 };

    for (i = 0; i <= 1; i++)
    {
        inum_firstCP[i] = inum_first[i]; // create a copy of inum_first
    }

    for (i = 0; i <= SIZE_USE; i++)
    {
        if (inum_first[i] != 0)
            check1++;

        if (inum_second[i] != 0)
            check2++;
    }

    if (secondlen > firstlen)
    {
        zeroC++;
        goto EOI;
    }

    if (check2 == 0)
    {
        puts("\nExpected error\n");
        return -1;
    }

    int j = 0, p = 0;

    int s = 0;
    int o = 1; // o is Quotient!

    do
    {
        for (i = SIZE_USE; i >= 0; i--)
        {
            if (tmp[i] = inum_firstCP[i] - inum_second[i] >= 0)
            {
                tmp[i] = inum_firstCP[i] - inum_second[i];
            }
            else
            {
                inum_firstCP[i - 1] = inum_firstCP[i - 1] - 1;
                tmp[i] = (inum_firstCP[i] + 10) - inum_second[i];
            }

            inum_firstCP[i] = tmp[i];

        }
    if (compare(inum_firstCP, inum_second, firstlen, secondlen) < 0) break;
    j++;
    o++;
    } while (j<MAX_SIZE); // anything else will also work

EOI:

    return 0;
}
int compare( mynum &a, mynum &b){
  if (a.len() > b.len()){
     return 1;
  } else (if b.len() > a.len()){
   return -1;
  } else(){
    for(int i = b.len(); i > 0; i--){
      if (a[i] > b[i]){
        return 1;
      } else if(b[i] > a[i]){
        return -1;
      }
     }
   //if we get there the numbers are the same
   return 0;
  }
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
