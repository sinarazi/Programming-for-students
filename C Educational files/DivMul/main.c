#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *Node;
struct node
{
    int info;
    Node next;
};


list_print(Node s)
    {
    if(s->next!= NULL) //Peymayesh linked list
    {
    list_print(s->next);
    printf("%d",s->info);
    }
    else
    {
        printf("%d",s->info);
    }
}


int num_list_add_leng(Node s, char str[])
{
    int len = strlen(str);
    int x=0;
    while(x < len)
    {
        int d=(int)str[x]-(int)'0';
        Node temp = NULL;
        temp = malloc(sizeof(Node));
        temp->next = s->next;
        s->next = temp;
        temp->info = d;
        x++;
     }
    return (len);
}

Initialize(Node one, Node two, Node ans)
{
    one->next = NULL;
    two->next = NULL;
    ans->next = NULL;
    one->info = 0;
    two->info = 0;
}

int bfr=0;


list_add_front(Node s, int x)
{
    Node temp = NULL;
    temp = malloc(sizeof(Node));
    temp->info = x;

    while(s->next!= NULL)
    {
       s = s->next;
    }
    s->next = temp;
    temp->next = NULL;
}



int ret=3;


int Greater(Node one, Node two)
{
    if((one->next!=NULL)&&(two->next!=NULL))
    {
        Greater(one->next,two->next);
    }
    if(((one->info)>(two->info))&&(ret==3)||((one->next!=NULL)&&(two->next==NULL)))
     {
        ret= 1;
     }
    if(((one->info)<(two->info))&&(ret==3)||((one->next==NULL)&&(two->next!=NULL)))
     {
        ret= 2;
     }
    return(ret);
}


int on = 1, flag = 0;
ZeroHandle(Node s)
{
    if(s!=NULL)
    {
    ZeroHandle(s->next);
    }
    if((s!=NULL)&&s->info==0&&on){
    flag = 1;
    }

    if((s!=NULL)&&(s->info!=0)&&flag){
    on = 0, flag = 0, s->next=NULL;
    }

    if(flag){
    s->next=NULL;
    }
}

SubE(Node s)
{
    if(s->next->info==0)
    {
    SubE(s->next);
    s->info=9;
    }
    else
    {
    s->next->info--;
    }
}

Free_M(Node s)
{
    if(s->next!=NULL)
    {
        Free_M(s->next);
    }
    free(s);
}


Subtract(Node one, Node two, Node ans)
{
    Node temp;
    int i=1;

    if(Greater(one,two)==2)
    {
        temp = two; //Swap
        two = one;
        one = temp;
    }
    if(Greater(one,two)==3)
    {
        temp = NULL;
        temp = malloc(sizeof(Node));
        temp->next = NULL;
        temp->info = 0;
        ans->next = temp;
        i=0;
    }
    int flag = 1;
    one = one->next;
    two = two->next;
    while(i)
    {
        if((one->info)<(two->info))
        {
            SubE(one);
            one->info = one->info+10;
            Node temp;
            temp = malloc(sizeof(Node));
            temp->next=NULL;
            temp->info = (one->info)-(two->info);
            ans->next = temp;
            ans = ans->next;
        }
        else
        {
            Node temp;
            temp = malloc(sizeof(Node));
            temp->next = NULL;
            temp->info = (one->info)-(two->info);
            ans->next = temp;
            ans = ans->next;
        }

        if((one->next!=NULL)&&(two->next!=NULL))
        {
            one=one->next;
            two=two->next;
        }
        else
        {
            while(one->next!=NULL){
            Node temp;
            temp = malloc(sizeof(Node));
            temp->next = NULL;
            temp->info = one->next->info;
            ans->next = temp;
            ans = ans->next;
            one = one->next;
        }
            break;
        }
    }
}


Divide(Node one, Node two, Node ans)
{
    int i=0;
    while(1)
    {
    if(Greater(one,two)==3)
    {
        i=i+1;
        break;
    }
    else
    {
        if(Greater(one,two)==2)
        {
            break;
        }
        else
        {
            i++;
            Subtract(one,two,ans);
            ZeroHandle(ans->next);
            one=ans;
        }
    }
}
    Node tmp = NULL;
    tmp = malloc(sizeof(Node));
    tmp->next = NULL;
    tmp->info = i;
    ans->next = tmp;
}


Add(Node one, Node two, Node ans)
    {
    bfr=0;
    Node op = NULL;
    int ad1,ad2;
    while(1)
    {
    if((one->next!= NULL)&&(two->next!= NULL))
    {
        one=one->next;
        ad1=one->info;
        two=two->next;
        ad2=two->info;
        }
    else
    {
        if((one->next==NULL)&&(two->next!=NULL))
        {
            ad1=0;
            two=two->next;
            ad2=two->info;
        }
        else
        {
            ad2=0;
            one=one->next;
            ad1=one->info;
        }
    }
    Node temp = NULL;
    temp = malloc(sizeof(Node));
    temp->next = NULL;
    temp->info = (ad1+ad2+bfr)%10;
    ans->next = temp;
    ans = ans->next;
    bfr = (ad1+ad2+bfr)>9?1:0;

    if((one->next==NULL)&&(two->next==NULL))
    {
    break;
    }

    if(bfr)
    {
        Node temp=NULL;
        temp=malloc(sizeof(Node));
        ans->next=temp;
        temp->info=1;
        temp->next=NULL;
    }
}

int i = 0, j = 0, buffer=0;
//Node add[l2];


int main()
{
    Node one = NULL;
    Node two = NULL;
    Node ans = NULL;
    one = malloc(sizeof(Node));
    two = malloc(sizeof(Node));
    ans = malloc(sizeof(Node));
    Initialize(one,two,ans);
    char a[10000];
    printf("First number :");
    scanf("%s",a);
    int l1 = num_list_add_leng(one,a);
    fflush(stdin);
    printf("\nSecond number :");
    scanf("%s",a);
    int l2 = num_list_add_leng(two,a);
    list_print(one->next);
    printf("\n");
    list_print(two->next);
    printf("\n  */+/-  ? = ");
    char pr;
    scanf(" %c",&pr);
    printf("The answer is: \n");
    int i=0, j=0, buffer=0;
    Node add[l2];
    int flow = 1;

    if((pr=='+')&&flow)
    {
         Add(one, two, ans);
         list_print(ans->next);
         flow = 0;
     }
     if((pr=='-')&&flow)
     {
         subtract(one, two, ans);
         ZeroHandle(ans->next);
         list_print(ans->next);
         flow = 0;
     }
     if((pr=='/')&&flow)
     {
         Divide(one, two, ans);
         list_print(ans->next);
         flow = 0;
     }
    if((pr=='*')&&flow)
     {
    for(j=0; j<l2; j++)
        {
        add[j] = malloc(sizeof(Node));
        add[j]->next = NULL;
        int ts=j;
        while(ts!=0)
        {
           list_add_front(add[j],0);
           ts--;
        }
        ans=one;
        int tmp1=two->next->info;
        for(i=0; i<l1; i++)
        {
            int tmp=one->next->info;
            int tmp3=(tmp1*tmp)+buffer;
            list_add_front(add[j],(tmp3)%10);
            buffer=(tmp3)>9?(tmp3/10):0;
            one=one->next;
        }

        one=ans;
        if(buffer>=1)
        {
            list_add_front(add[j],buffer);
        }
        two=two->next;
        buffer=0;
    }
    i=0;
    Free_M(ans);
    Node ans1;
    ans1 = malloc(sizeof(Node));
    ans1->next = NULL;
    j=l2;
    while(j>=2)
    {
      Add(add[i],add[i+1],ans1);
      add[i+1]=ans1;
      i++;
      j--;
    }
     }
    printf("\n");
    list_print(add[l2-1]->next);
    }
    printf("\n written by Sina Razi");
    getch();

    return 0;
}
