#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>


int numberToComp(int[],int[],int,int);
int temp1[101];
int temp2[101];
int subtract_arr[101];
int a[101];
int b[101];
int t[101];
int ai = 0, bi = 0, ti = 0;
int i, k;


//Entry of two Number
void Entry()
{
    printf("Enter first number:\n");

    char ch='\0';

    while(1)
    {
    ai = 0;
    for(;;)
       {
       ch = getchar();
       if (ch=='\n')
           break;
       a[ai]=ch-48;
       ai++;
       }
    if (ai<101)
        break;
    else
      {
      getch();
      printf("\nEnter first number with 1-50 digits: ");
      }
    }

    for(int i=ai-1; i>=0; i--)
    temp1[ai-i-1]=a[i];

    printf("\nEnter second number:\n");
    ch='\0';
    while(1)
    {
    bi=0;
    for(;;)
       {
       ch = getchar();
       if (ch =='\n') break;
       b[bi]=ch-48;
       bi++;
       }
    if(bi<101) break;
    else
      {
      getch();
      printf("\nEnter second number with 1-50 digits: ");
      }
    }
    for(i=bi-1; i>=0; i--)
    temp2[bi-i-1]=b[i];

}

//Clear array
void clear()
{
    int i;
    for(i=0; i<101; i++)
    {
    temp1[i]='\0';
    temp2[i]='\0';
    subtract_arr[i]='\0';
    a[i]='\0';
    b[i]='\0';

    }
}

//Compare
int numberToComp(int arr1[], int arr2[], int x, int y)
{
    int i, m;
    if (x > y)
        return(1);
    else
        if (x < y)
            return(2);
        else
            if(x==y)
            {
            m=1;
            while((x-m)>=0)
            {
            if (arr1[x-m] > arr2[x-m])
                return(1);
            else
                if (arr1[x-m] < arr2[x-m])
                    return(2);
                m++;
    }
}
 return(1);
}


//subtraction of two numbers
void subtract(int arr1[], int arr2[], int x, int y)
{
    int subtract_i=0;
    char sign='\0';
    for(int k=0; k<101; k++)
        subtract_arr[k]='\0';
        int k;
        if(numberToComp(arr1, arr2, x, y)==1)
        {
        for(k=0; k<x; k++)
            {
            if (temp1[k]>= temp2[k])
            {
            subtract_arr[k] = temp1[k]-temp2[k];
            if (subtract_arr[k]>0)
                subtract_i = k;
            }
            else
            {
            temp1[k+1] = temp1[k+1]-1;
            temp1[k] = temp1[k]+10;
            subtract_arr[k] = temp1[k]-temp2[k];
            if (subtract_arr[k]>0)
                subtract_i=k;
            }
      }
     sign='+';
    }
    else if (numberToComp(arr1, arr2, x, y)==2)
    {
      for(int k=0; k<y; k++)
         {
        if (temp2[k]>=temp1[k])
         {
          subtract_arr[k]=temp2[k]-temp1[k];
          if (subtract_arr[k]>0) subtract_i=k;
         }
      else
         {
         temp2[k+1]=temp2[k+1]-1;
         temp2[k]=temp2[k]+10;
         subtract_arr[k]=temp2[k]-temp1[k];
          if (subtract_arr[k]>0) subtract_i=k;
         }
    }
    sign='-';
    }
    printf("The subtraction of two numbers is : ");

    printf("%c", sign);
    for(int i=0; i<=subtract_i; i++)
        printf("%d", subtract_arr[subtract_i-i]);
    printf("\n (a, m, s, d, e)? ");
}


//divide
void divide(void)
{
    int n = 0, m, temp1_i = 0, temp2_i = 0;
    int tn[101];
    int tm[101];
    int t_0[101];
    int subtract_t[101];
    int subtract_ti=0;
    ti = ai;

    for(int i = 0; i< 101; i++)
    {
        t[i]='\0';
        tn[i]='\0';
        tm[i]='\0';
        t_0[i]=0;
        subtract_arr[i]='\0';
        subtract_t[i]='\0';
    }
    for(i=0; i<ai; i++)
        t[i] = temp1[i];
        while((numberToComp(t,temp2,ti,bi))==1)
        {
        //subtraction(t,temp2)
        subtract_ti=0;
        for(int k=0; k<ti; k++)
          {
         if (t[k]>=temp2[k])
             {
             subtract_t[k]=t[k]-temp2[k];
             if(subtract_t[k]>0) subtract_ti=k;
             }
         else
          {
          t[k+1] = t[k+1]-1;
          t[k] = t[k]+10;
          subtract_t[k] = t[k]-temp2[k];
          if (subtract_t[k]>0) subtract_ti=k;
          }
     }
     ti = subtract_ti+1;
     for(i=0; i<=ti; i++)
     t[i] = subtract_t[i];
     tn[0]++;
     for(i=0; i<100; i++)
          if (tn[i]>9)
          {
           tn[i]=0;
           tn[i+1]++;
          }
     }

    for(int s=0; s<10; s++)
    {
      if ((numberToComp(t_0,t,ti,ti))==1)break;
      for(int j=100; j>0; j--)
      t[j] = t[j-1];
      t[0]=0;
      m = 0;
      ti++;
    while((numberToComp(t,temp2,ti,bi))==1)
    {
    //subtraction(t,temp2)
    subtract_ti=0;
    for(int k=0; k<ti; k++)
      {
         if (t[k]>=temp2[k])
         {
         subtract_t[k] = t[k]-temp2[k];
            if (subtract_t[k]>0) subtract_ti=k;
         }
        else
            {
            t[k+1] = t[k+1]-1;
            t[k] = t[k]+10;
            subtract_t[k] = t[k]-temp2[k];
            if (subtract_t[k]>0) subtract_ti=k;
            }
        }
        ti=subtract_ti+1;
        for(i=0; i<=ti; i++)
            t[i]=subtract_t[i];
            m++;
            }
        tm[s]=m;
        if(m>0)
            temp2_i=s;
        }
    for(i=0; i<100; i++)
        if (tn[i]>0)
        temp1_i=i;

    printf("The division of two numbers is : ");
    for(i=temp1_i; i>=0; i--)
    printf("%d", tn[i]);
    printf(".");
    for(i=0; i<=temp2_i; i++)
    printf("%d", tm[i]);
    printf("\n (a, m, s, d, e)? ");
}


//Multiply two numbers
void multiply(void)
{
    int multiply_arr[201];
    for (int k=0;k<201;k++)
    multiply_arr[k]=0;

    int zi=0;
    for(int j=0;j<bi;j++)
    for(int i=0;i<ai;i++)
    {
    int x = temp1[i]*temp2[j]+multiply_arr[i+j];
    if (x<10)
    {
    multiply_arr[i+j]=x;
    zi=i+j;
    }
    else
    {
    multiply_arr[i+j+1]+=x / 10;
    multiply_arr[i+j]=x % 10;
    zi=i+j+1;
    }
    }
    printf("The multiply of two numbers is :");
    for(int n=0;n<=zi;n++)
    printf("%d", multiply_arr[zi-n]);
    printf("\n (a, m, s, d, e)? ");
}


// Add two numbers
void add()
{
    int pi=0;
    int add_arr[201];
    for (int k=0;k<201;k++)
    add_arr[k]=0;
    int max=ai;

    if (bi>max)
        max=bi;
    for(k=0;k<max;k++)
        {
        add_arr[k]=temp1[k]+temp2[k]+add_arr[k];
        pi=k;
        if (add_arr[k]>9)
        {
        add_arr[k+1]=add_arr[k]/10;
        add_arr[k]=add_arr[k]%10;
        pi=k+1;
        }
    }
    printf("The sum of two numbers is : ");
    for(int i=0; i<=pi; i++)
    printf("%d", add_arr[pi-i]);
    printf("\n (a, m, s, d, e)? ");
}


int main()
{

    puts("Add, Subtract, Multiply, Divide of two numbers with 50 digits.\n");
    Entry();
    printf("\nEnter your Choice :\n");
    printf("\n -----------------------");
    printf("\n a) add");
    printf("\n m) multiply");
    printf("\n s) subtract");
    printf("\n d) divide");
    printf("\n e) Exit");
    printf("\n -----------------------");
    printf("\n (a, m, s, d, e)? ");

    char select;
    while(1)
    {
    scanf("%c", &select);
    if (select=='a')
        add();
    else
    if (select=='m')
    multiply();
    else
    if (select=='s')
    subtract(temp1,temp2,ai,bi);
    else
    if (select=='d')
    divide();
    if (select=='e')
    break;
    }
}//End main


