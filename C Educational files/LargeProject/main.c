    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct node *nodeptr;
    struct node{
    int data;
    nodeptr next;
    };

    list_print(nodeptr s)
       {

       if(s->next!=NULL)
       {

       list_print(s->next);
       printf("%d",s->data);
       }
       else{printf("%d",s->data);}

       }
    int num_list_add_leng(nodeptr s ,char str[])
    {

     int len=strlen(str);

     int x=0;
     while(x<len)
     {
                    int d=(int)str[x]-(int)'0';
                    nodeptr temp=NULL;
                    temp=malloc(sizeof(nodeptr));
                    temp->next=s->next;
                    s->next=temp;
                    temp->data=d;
                    x++;
     }
     return (len);

    }
    initialize(nodeptr one,nodeptr two,nodeptr ans)
    {
        one->next=NULL;
        two->next=NULL;
        ans->next=NULL;
        one->data=0;
        two->data=0;
    }
    int bfr=0;


    list_add_front(nodeptr s,int x)
    {

       nodeptr temp=NULL;

       temp=malloc(sizeof(nodeptr));
       temp->data=x;
       while(s->next!=NULL){
       s=s->next;}
       s->next=temp;
       temp->next=NULL;
    }

     addit(nodeptr one,nodeptr two,nodeptr ans)
    {
        bfr=0;
        nodeptr op=NULL;
        int ad1,ad2;
     while(1){

        if((one->next!=NULL)&&(two->next!=NULL))
        {
            one=one->next;
            ad1=one->data;
            two=two->next;
            ad2=two->data;
        }
        else{
        if((one->next==NULL)&&(two->next!=NULL))
        {

                    ad1=0;
            two=two->next;
            ad2=two->data;

        }

        else{
        {
            ad2=0;
            one=one->next;
            ad1=one->data;

        }
        }
        }

            nodeptr temp=NULL;
        temp=malloc(sizeof(nodeptr));
        temp->next=NULL;
        temp->data=(ad1+ad2+bfr)%10;
        ans->next=temp;
        ans=ans->next;
        bfr=(ad1+ad2+bfr)>9?1:0;
        if((one->next==NULL)&&(two->next==NULL))
        break;
        }
        if(bfr)
        {
        nodeptr temp=NULL;
        temp=malloc(sizeof(nodeptr));
        ans->next=temp;
        temp->data=1;
        temp->next=NULL;

        }


    }

    freemem(nodeptr s)
    {
        if(s->next!=NULL)
        {
            freemem(s->next);
        }
        free(s);

    }
    int ret=3;

    int greater(nodeptr one,nodeptr two)
    {
        if((one->next!=NULL)&&(two->next!=NULL))
        {
            greater(one->next,two->next);

        }
        if(((one->data)>(two->data))&&(ret==3)||((one->next!=NULL)&&(two->next==NULL)))
        ret= 1;
        if(((one->data)<(two->data))&&(ret==3)||((one->next==NULL)&&(two->next!=NULL)))
        ret= 2;

        return(ret);

    }
    subthd(nodeptr s)
    {
        if(s->next->data==0)
        {
            subthd(s->next);
            s->data=9;
        }
        else{
        s->next->data--;
        }
    }
     int on=1,flg=0;
     int traverse(nodeptr s)
     {

         while(s!=NULL)
         {
             if(s->data!=0)
             {
                 return 0;
             }
             s=s->next;
         }
         return 1;
     }
     zero_trim(nodeptr s)
     {
       while(s->next!=NULL)
       {
           if(s->next->data==0)
           {
               if(traverse(s->next))
               s->next=NULL;
           }
           s=s->next;
       }

     }
    stripLeadingZeros( nodeptr s )
    {
      if(s!=NULL)
      stripLeadingZeros(s->next);
      if((s!=NULL)&&s->data==0&&on)
      flg=1;
      if((s!=NULL)&&(s->data!=0)&&flg)
      on=0,flg=0,s->next=NULL;
      if(flg)
      s->next=NULL;
    }



    subtract(nodeptr one,nodeptr two,nodeptr ans)
    {
        nodeptr tmp;
        int i=1;
        if(greater(one,two)==2)
        {
            tmp=two;
            two=one;
            one=tmp;
        }
        if(greater(one,two)==3)
        {
            tmp=NULL;
            tmp=malloc(sizeof(nodeptr));
            tmp->next=NULL;
            tmp->data=0;
            ans->next=tmp;
            i=0;
        }

        int flag =1;
        one=one->next;
        two=two->next;
        while(i){

                if((one->data)<(two->data))
                {

                    subthd(one);
                    one->data=one->data+10;
                    nodeptr tmp;
                    tmp=malloc(sizeof(nodeptr));
                    tmp->next=NULL;
                    tmp->data=(one->data)-(two->data);
                    ans->next=tmp;
                    ans=ans->next;

                }
                else
                {
                  nodeptr tmp;
                  tmp=malloc(sizeof(nodeptr));
                  tmp->next=NULL;
                  tmp->data=(one->data)-(two->data);
                  ans->next=tmp;
                  ans=ans->next;
                }

                if((one->next!=NULL)&&(two->next!=NULL))
                {
                    one=one->next;
                    two=two->next;
                }
                else{
                    while(one->next!=NULL){
                    nodeptr tmp;
                    tmp=malloc(sizeof(nodeptr));
                    tmp->next=NULL;
                    tmp->data=one->next->data;
                    ans->next=tmp;
                    ans=ans->next;
                    one=one->next;
                    }
                break;
                }


        }



    }


    divide(nodeptr one,nodeptr two,nodeptr ans){
    int i=0;
    while(1){

    if(greater(one,two)==3)
    {
        i=i+1;
        break;
    }
    else{
        if(greater(one,two)==2)
        {

            break;

        }
        else
        {
            i++;
            subtract(one,two,ans);
            stripLeadingZeros(ans->next);
            one=ans;
        }

    }
    }

    nodeptr tmp=NULL;
    tmp=malloc(sizeof(nodeptr));
    tmp->next=NULL;
    tmp->data=i;
    ans->next=tmp;


    }


    main()
    {
        nodeptr one=NULL;
        nodeptr two=NULL;
        nodeptr ans=NULL;
        one=malloc(sizeof(nodeptr));
        two=malloc(sizeof(nodeptr));
        ans=malloc(sizeof(nodeptr));
        initialize(one,two,ans);
        char a[10000];
        printf("first number =");
        scanf("%s",a);
        int l1=num_list_add_leng(one,a);

        fflush(stdin);
        printf("\n second number =");
        scanf("%s",a);
        int l2=num_list_add_leng(two,a);
        list_print(one->next);
        printf("\n");
        list_print(two->next);
        printf("\n  */+/-  ? = ");
        char pr;
        scanf(" %c",&pr);
        printf("\n");
        int i=0,j=0,buffer=0;
        nodeptr add[l2];
        int flow=1;
     if((pr=='+')&&flow){
         addit(one,two,ans);
         list_print(ans->next);
         flow=0;
     }
     if((pr=='-')&&flow)
     {

         subtract(one,two,ans);
         stripLeadingZeros(ans->next);
         list_print(ans->next);
         flow=0;
     }
     if((pr=='/')&&flow)
     {
         divide(one,two,ans);
         list_print(ans->next);
         flow=0;
     }
     if((pr=='*')&&flow){                                         //note: ans node is useless for addition from here used as temp mem frm here
    for(j=0;j<l2;j++)
    {
        add[j]=malloc(sizeof(nodeptr));
        add[j]->next=NULL;
        int ts=j;
        while(ts!=0)
        {
           list_add_front(add[j],0);
           ts--;
        }
         ans=one;
        int tmp1=two->next->data;
     for(i=0;i<l1;i++){
          int tmp=one->next->data;
          int tmp3=(tmp1*tmp)+buffer;
          list_add_front(add[j],(tmp3)%10);
          buffer=(tmp3)>9?(tmp3/10):0;
              one=one->next;
                      }
                      one=ans;
    if(buffer>=1){
    list_add_front(add[j],buffer);

    }
    two=two->next;
    buffer=0;
    }
    i=0;
    freemem(ans);
    nodeptr ans1;
    ans1=malloc(sizeof(nodeptr));
    ans1->next=NULL;
    j=l2;
    while(j>=2){
      addit(add[i],add[i+1],ans1);
      add[i+1]=ans1;
      i++;
      j--;
    }


    printf("\n");
    list_print(add[l2-1]->next);
    }
    printf("\n written by Namit Sinha");
    getch();
    }
