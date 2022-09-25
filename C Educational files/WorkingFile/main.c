#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


struct StudentsInformation
{
    int code;
    char firstName[80];
    char lastName[80];
    char fatherName[80];
    int studentNumber[11];
    float score1, score2, score3, score4, avg;
};


void ItemChoose(void);
void AddNew(void);
void ShowList(void);
int ExistRecord(int);
void FindRecord(void);
void DeleteRecord(void);
void EditRecord(void);

int switchMenu;

int main(int argc, char *argv[])
{
     do
        {
        ItemChoose();
        if(switchMenu == 1)
            AddNew();
        else if(switchMenu == 2)
            EditRecord();
        else if(switchMenu == 3)
            ShowList();
        else if(switchMenu == 4)
            FindRecord();
        else if(switchMenu == 5)
            DeleteRecord();
        else if(switchMenu == 6)
            exit(1);
        }
        while (1);
return 0;
}


void ItemChoose(void)
{
     printf("1. Add New Record.\n");
     printf("2. Edit Record.\n");
     printf("3. Show List Record.\n");
     printf("4. Find Record.\n");
     printf("5. Delete Record.\n");
     printf("6. Exit Program.\n");
     printf("\nChoice Number: ");
     scanf("%d", &switchMenu);
}


void AddNew(void)
{
     struct StudentsInformation recordStudent;
     FILE *fileStudentsInformation;
     printf("\n");
     printf("--------------------- Enter Info Student ----------------------\n");
     printf("Enter Code: ");
     scanf("%d",&recordStudent.code);
     printf("Enter firstName: ");
     scanf("%s",recordStudent.firstName);
     printf("Enter lastName: ");
     scanf("%s",recordStudent.lastName);
     printf("Enter fatherName: ");
     scanf("%s",recordStudent.fatherName);
     printf("Enter Score1: ");
     scanf("%f",&recordStudent.score1);
     printf("Enter Score2: ");
     scanf("%f",&recordStudent.score2);
     printf("Enter Score3: ");
     scanf("%f",&recordStudent.score3);
     printf("Enter Score4: ");
     scanf("%f",&recordStudent.score4);

     recordStudent.avg =  (recordStudent.score1 + recordStudent.score2 + recordStudent.score3 + recordStudent.score4)/4;

    if ( ExistRecord(recordStudent.code) == 1 )
        {
        printf("\n");
        printf("Record Before Saving In DataBase[Please Return]...");
        getch();
        }
    else
        {
        fileStudentsInformation=fopen("student.txt","ab");
        if (!fileStudentsInformation)
        {
        printf("\n");
        printf("Can not Open OutPut File.\n");
        getch();
        exit(1);
        }
    fwrite(&recordStudent,sizeof(struct StudentsInformation),1,fileStudentsInformation);
    fclose(fileStudentsInformation);
    printf("------------------ Saving Record ------------------------------\n");
    printf("Press Enter...");
    getch();
    }
}


int ExistRecord(int code)
{
     struct StudentsInformation recordStudent,recordStudenttemp;
     FILE *fileStudentsInformation;
     fileStudentsInformation=fopen("student.txt", "rb");
     fread(&recordStudenttemp,sizeof(struct StudentsInformation), 1, fileStudentsInformation);

     while (!feof(fileStudentsInformation))
        {
        if (code == recordStudenttemp.code )
            return 1;
        fread(&recordStudenttemp,sizeof(struct StudentsInformation),1,fileStudentsInformation);
     }
     fclose(fileStudentsInformation);
     return 0;
}


void DeleteRecord(void)
{
     struct StudentsInformation recordStudent,recordStudenttemp;
     FILE *fileStudentsInformation,*fileStudentsInformationtemp;

     int code;
     int find=0;
     printf("\n");
     printf("------------------------------- Delete Record-------------------------------\n");
     printf("Enter Code Student For Delete :");
     scanf("%d",&code);
     fileStudentsInformation=fopen("student.txt","rb");
     fileStudentsInformationtemp=fopen("TempStudent.txt","wb");
     if (!fileStudentsInformation || !fileStudentsInformationtemp)
          {
           printf("\n");
           printf("Can't Open OutPut File.\n");
           getch();
           exit(1);
          }
     fread(&recordStudent,sizeof(struct StudentsInformation), 1, fileStudentsInformation);
     while (!feof(fileStudentsInformation))
        {
        if ( code != recordStudent.code )
            fwrite(&recordStudent,sizeof(struct StudentsInformation),1,fileStudentsInformationtemp);
        else
            find=1;
        fread(&recordStudent,sizeof(struct StudentsInformation),1,fileStudentsInformation);
     }
     fclose(fileStudentsInformation);
     fclose(fileStudentsInformationtemp);

     if (find == 1)
        {
        fileStudentsInformation=fopen("student.txt","wb");
        fileStudentsInformationtemp=fopen("TempStudent.txt","rb");
        fread(&recordStudent,sizeof(struct StudentsInformation), 1, fileStudentsInformationtemp);

        while (!feof(fileStudentsInformationtemp))
            {
            fwrite(&recordStudent,sizeof(struct StudentsInformation),1,fileStudentsInformation);
            fread(&recordStudent,sizeof(struct StudentsInformation),1,fileStudentsInformationtemp);
            }
       printf("\n");
       printf("Deleting Record ----------->  Press Enter...");
       getch();
       fclose(fileStudentsInformation);
       fclose(fileStudentsInformationtemp);
        }
    else
        {
        printf("\nRecord Not Find...\n");
        getch();
    }
}


void EditRecord(void)
{
     struct StudentsInformation recordStudent,recordStudenttemp,recordStudentnew;
     FILE *fileStudentsInformation,*fileStudentsInformationtemp;

     int code;
     int find=0;
     printf("\n");
     printf("------------------------------- Edit Record-------------------------------\n");
     printf("Enter Code Student For Edit :");
     scanf("%d",&code);
     printf("---------------------------------------------------------------------------\n");
     printf("--------------------------- Enter Info Student ----------------------------\n");

     recordStudentnew.code = code;
     if(ExistRecord(code)== 1)
        {
        printf("Enter firstName :");
        scanf("%s", recordStudentnew.firstName);
        printf("Enter lastName :");
        scanf("%s", recordStudentnew.lastName);
        printf("Enter fatherName :");
        scanf("%s", recordStudentnew.fatherName);
        printf("Enter Score :");
        scanf("%f", &recordStudentnew.score1);
        printf("Enter Score2 :");
        scanf("%f", &recordStudentnew.score2);
        printf("Enter Score3 :");
        scanf("%f", &recordStudentnew.score3);
        printf("Enter Score4 :");
        scanf("%f", &recordStudentnew.score4);
        recordStudentnew.avg =  (recordStudentnew.score1 + recordStudentnew.score2 + recordStudentnew.score3 + recordStudentnew.score4)/4;

        fileStudentsInformation=fopen("student.txt","rb");
        fileStudentsInformationtemp=fopen("TempStudent.txt","wb");
        if (!fileStudentsInformation || !fileStudentsInformationtemp)
            {
            printf("\n");
            printf("Can't Open OutPut File.\n");
            getch();
            exit(1);
            }
       fread(&recordStudenttemp,sizeof(struct StudentsInformation),1,fileStudentsInformation);

       while (!feof(fileStudentsInformation))
          {
          if ( code == recordStudenttemp.code )
             {
             recordStudenttemp.code = recordStudentnew.code;
             strncpy(recordStudenttemp.firstName,recordStudentnew.firstName, 80);
             strncpy(recordStudenttemp.lastName , recordStudentnew.lastName, 80);
             strncpy(recordStudenttemp.fatherName , recordStudentnew.fatherName, 80);
             recordStudenttemp.score1 = recordStudentnew.score1;
             recordStudenttemp.score2 = recordStudentnew.score2;
             recordStudenttemp.score3 = recordStudentnew.score3;
             recordStudenttemp.score4= recordStudentnew.score4;
             recordStudenttemp.avg =  recordStudentnew.avg;
            }
        fwrite(&recordStudenttemp,sizeof(struct StudentsInformation),1,fileStudentsInformationtemp);
        fread(&recordStudenttemp,sizeof(struct StudentsInformation),1,fileStudentsInformation);
        }
        fclose(fileStudentsInformation);
        fclose(fileStudentsInformationtemp);
        fileStudentsInformation=fopen("student.txt","wb");
        fileStudentsInformationtemp=fopen("TempStudent.txt","rb");
        fread(&recordStudent,sizeof(struct StudentsInformation),1,fileStudentsInformationtemp);

        while (!feof(fileStudentsInformationtemp))
        {
            fwrite(&recordStudent,sizeof(struct StudentsInformation),1,fileStudentsInformation);
            fread(&recordStudent,sizeof(struct StudentsInformation),1,fileStudentsInformationtemp);
        }
        printf("\n");
        printf("Edit Record ----------->  Press Enter...");
        getch();
        fclose(fileStudentsInformation);
        fclose(fileStudentsInformationtemp);
        }
     else
        {
         printf("\n Record Not Find...\n Press Any Key To Continue.\n");
         getch();
         exit(1);
        }
}


void FindRecord(void)
{
     struct StudentsInformation recordStudent;
     FILE *fileStudentsInformation,*filestudent;

     int code;
     int find=0;
     printf("\n");
     printf("---------------------- Show Info Student ----------------------------\n");
     printf("Enter Code Student :");
     scanf("%d",&code);
     fileStudentsInformation=fopen("student.txt","rb");
     filestudent=fopen("st_kar.txt","wb");
     if (!fileStudentsInformation)
          {
           printf("\n");
           printf("Can't Open OutPut File.\n");
           getch();
           exit(1);
          }
     printf("\n");
     fread(&recordStudent,sizeof(struct StudentsInformation), 1, fileStudentsInformation);
     while (!feof(fileStudentsInformation))
     {
        if (code ==recordStudent.code )
        {
            printf("---------------------------------------------------------------------\n");
            printf(" Code:%d \nfirstName:%s \n lastName:%s \n fatherName:%s \n Score1:%f \n Score2:%f \n Score3:%f \n Score4:%f \n",recordStudent.code,recordStudent.firstName,recordStudent.lastName,recordStudent.fatherName,recordStudent.score1,recordStudent.score2,recordStudent.score3,recordStudent.score4);
            printf("\n Average:%2.2f \n",recordStudent.avg);
            printf("---------------------------------------------------------------------\n");
            fwrite(&recordStudent,sizeof(struct StudentsInformation),1,filestudent);
            printf("File (st_kar.txt) Created.\n Press Key Resume...\n");
            getch();
            find=1;
            break;
        }
        fread(&recordStudent,sizeof(struct StudentsInformation), 1, fileStudentsInformation);
     }
     if (find==0)
        {
        printf("\nRecord NotFind..\n");
        getch();
        }
     fclose(fileStudentsInformation);
     fclose(filestudent);
}


void ShowList(void)
{
     struct StudentsInformation recordStudent,temp,listsort[100];
     FILE *fileStudentsInformation;

     int count=0,p,i,selitem;
     printf("\n");
     printf("---------------------- Show Info Student ----------------------------\n");
     do
     {
      printf("\n1-Sort Asc.\n");
      printf("2-Sort Desc.\n");
      printf("Select Item[1,2]:");
      scanf("%d",&selitem);
     }
     while(!(selitem>=1 && selitem<=2));

     fileStudentsInformation=fopen("student.txt","rb");
     if (!fileStudentsInformation)
          {
           printf("\n");
           printf("Can't Open OutPut File.\n");
           getch();
           exit(1);
          }

     fread(&recordStudent,sizeof(struct StudentsInformation),1,fileStudentsInformation);
     while (!feof(fileStudentsInformation))
        {
        listsort[count].code =recordStudent.code;
        strncpy(listsort[count].firstName ,recordStudent.firstName, 80);
        strncpy(listsort[count].lastName ,recordStudent.lastName, 80);
        strncpy(listsort[count].fatherName ,recordStudent.fatherName, 80);
        listsort[count].score1 =recordStudent.score1;
        listsort[count].score2 =recordStudent.score2;
        listsort[count].score3 =recordStudent.score3;
        listsort[count].score4 =recordStudent.score4;
        listsort[count].avg =recordStudent.avg;
        count++;
        fread(&recordStudent,sizeof(struct StudentsInformation),1,fileStudentsInformation);
        }
     count--;
     fclose(fileStudentsInformation);

     for ( p = 0; p <= count ; p++)
         {
         for ( i = 0; i <= count - 1; i++)
             {
             if(selitem==1)
                {
                 if (listsort[i].avg > listsort[i + 1].avg)
                     {
                     temp.code = listsort[i + 1].code;
                     strncpy(temp.firstName , listsort[i + 1].firstName, 80);
                     strncpy(temp.lastName , listsort[i + 1].lastName, 80);
                     strncpy(temp.fatherName , listsort[i + 1].fatherName, 80);
                     temp.score1 = listsort[i + 1].score1;
                     temp.score2 = listsort[i + 1].score2;
                     temp.score3 = listsort[i + 1].score3;
                     temp.score4 = listsort[i + 1].score4;
                     temp.avg = listsort[i + 1].avg;

                     listsort[i + 1].code = listsort[i].code;
                     strncpy(listsort[i + 1].firstName , listsort[i].firstName, 80);
                     strncpy(listsort[i + 1].lastName , listsort[i].lastName, 80);
                     strncpy(listsort[i + 1].fatherName , listsort[i].fatherName, 80);
                     listsort[i + 1].score1 = listsort[i].score1;
                     listsort[i + 1].score2 = listsort[i].score2;
                     listsort[i + 1].score3 = listsort[i].score3;
                     listsort[i + 1].score4 = listsort[i].score4;
                     listsort[i + 1].avg = listsort[i].avg;

                     listsort[i].code = temp.code;
                     strncpy(listsort[i].firstName , temp.firstName,20);
                     strncpy(listsort[i].lastName , temp.lastName,20);
                     strncpy(listsort[i].fatherName , temp.fatherName,20);
                     listsort[i].score1 = temp.score1;
                     listsort[i].score2 = temp.score2;
                     listsort[i].score3 = temp.score3;
                     listsort[i].score4 = temp.score4;
                     listsort[i].avg = temp.avg;
                    }
                }
                else if(selitem==2)
                     if (listsort[i].avg < listsort[i + 1].avg)
                         {
                         temp.code = listsort[i + 1].code;
                         strncpy(temp.firstName , listsort[i + 1].firstName,20);
                         strncpy(temp.lastName , listsort[i + 1].lastName,20);
                         strncpy(temp.fatherName , listsort[i + 1].fatherName,20);
                         temp.score1 = listsort[i + 1].score1;
                         temp.score2 = listsort[i + 1].score2;
                         temp.score3 = listsort[i + 1].score3;
                         temp.score4 = listsort[i + 1].score4;
                         temp.avg = listsort[i + 1].avg;

                         listsort[i + 1].code = listsort[i].code;
                         strncpy(listsort[i + 1].firstName , listsort[i].firstName,20);
                         strncpy(listsort[i + 1].lastName , listsort[i].lastName,20);
                         strncpy(listsort[i + 1].fatherName , listsort[i].fatherName,20);
                         listsort[i + 1].score1 = listsort[i].score1;
                         listsort[i + 1].score2 = listsort[i].score2;
                         listsort[i + 1].score3 = listsort[i].score3;
                         listsort[i + 1].score4 = listsort[i].score4;
                         listsort[i + 1].avg = listsort[i].avg;

                         listsort[i].code = temp.code;
                         strncpy(listsort[i].firstName , temp.firstName,20);
                         strncpy(listsort[i].lastName , temp.lastName,20);
                         strncpy(listsort[i].fatherName , temp.fatherName,20);
                         listsort[i].score1 = temp.score1;
                         listsort[i].score2 = temp.score2;
                         listsort[i].score3 = temp.score3;
                         listsort[i].score4 = temp.score4;
                         listsort[i].avg = temp.avg;
                         }
                    }
                }
     printf("\n");

     printf(" Code \tfirstName \tlastName \tfatherName \tScore1 \tScore2 \tScore3 \tScore4 \tAverage\n");
     printf("-----------------------------------------------------------------------\n");

     for(i=0; i<=count; i++)
        {
         printf(" %d \t%s \t%s \t%s \t%2.2f \t%2.2f \t%2.2f \t%2.2f \t%2.2f\n",listsort[i].code,listsort[i].firstName,listsort[i].lastName,listsort[i].fatherName,listsort[i].score1,listsort[i].score2,listsort[i].score3,listsort[i].score4,listsort[i].avg);
        }
     printf("-----------------------------------------------------------------------\n");
     getch();
}
