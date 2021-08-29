#include"findshow.h"
#include<stdio.h>
#include<stdlib.h>
#include"interface.h"
#include"show.h"
#include"otherfunc.h"
#include"findfunc.h"
#include"record.h"
#include"gobal.h"
#include<windows.h>
#include"date.h"

int find()
{
    int findinput;
    scanf("%d",&findinput);
    switch (findinput) {
    case 1:
        system("cls");
        finddepartment();
        break;
    case 2:
        system("cls");
        finddoctor();
        break;
    case 3:
        system("cls");
        findpatient();
        break;
    case 4:
        system("cls");
        findtime();
        break;
    case 5:
        return 5;
        break;
    default:
        otherinputinterface();
        break;

    }
    return 0;
}

void finddepart()
{
    int x=45;
    int y=6;
    gotoXY(x+2,y-1);
    printf("��ѯ����ҽ����Ϣ");
    gotoXY(x,y);
    printf("--------------------");
    gotoXY(x,y+14);
    printf("--------------------");

    int col=x+6;
    gotoXY(col,y+1);
    printf("10.��ǻ��");
    gotoXY(col,y+3);
    printf("20.����");
    gotoXY(col,y+5);
    printf("30.Ƥ����");
    gotoXY(col,y+7);
    printf("40.�ڿ�");
    gotoXY(col,y+9);
    printf("50.���");
    gotoXY(col,y+11);
    printf("60.�ۿ�");
    gotoXY(col,y+13);
    printf("70.������һ��");
    gotoXY(x-4,y+16);
    printf("����������ѯ�Ŀ��Ҷ�Ӧ���:");
}
void finddepartment()
{

    int department;
    while(1)
    {
        system("cls");
        finddepart();
        scanf("%d",&department);
        switch(department){
        case 10:
        {
            system("cls");
            gotoXY(45,6);
            printf("��ǻ��ҽ����Ϣ:");
            gotoXY(19,7);
            printf("-----------------------------------------------------------------------------");
            char departnum[3];
            itoa(department,departnum,10);
            Doctor* founddoctor=findDepartment(doctor,departnum);

            showdoctor(founddoctor);
            break;
        }
        case 20:
        {
            system("cls");
            gotoXY(45,6);
            printf("����ҽ����Ϣ:");
            gotoXY(19,7);
            printf("-----------------------------------------------------------------------------");
            char departnum[3];
            itoa(department,departnum,10);
            Doctor* founddoctor=findDepartment(doctor,departnum);

            showdoctor(founddoctor);
            break;
        }
        case 30:
        {
            system("cls");
            gotoXY(45,6);
            printf("Ƥ����ҽ����Ϣ:");
            gotoXY(19,7);
            printf("-----------------------------------------------------------------------------");
            char departnum[3];
            itoa(department,departnum,10);
            Doctor* founddoctor=findDepartment(doctor,departnum);

            showdoctor(founddoctor);
            break;
        }
        case 40:
        {
            system("cls");
            gotoXY(45,6);
            printf("�ڿ�ҽ����Ϣ:");
            gotoXY(19,7);
            printf("-----------------------------------------------------------------------------");
            char departnum[3];
            itoa(department,departnum,10);
            Doctor* founddoctor=findDepartment(doctor,departnum);

            showdoctor(founddoctor);
            break;
        }
        case 50:
        {
            system("cls");
            gotoXY(45,6);
            printf("���ҽ����Ϣ:");
            gotoXY(19,7);
            printf("-----------------------------------------------------------------------------");
            char departnum[3];
            itoa(department,departnum,10);
            Doctor* founddoctor=findDepartment(doctor,departnum);

            showdoctor(founddoctor);
            break;
        }
        case 60:
        {
            system("cls");
            gotoXY(45,6);
            printf("�ۿ�ҽ����Ϣ:");
            gotoXY(19,7);
            printf("-----------------------------------------------------------------------------");
            char departnum[3];
            itoa(department,departnum,10);
            Doctor* founddoctor=findDepartment(doctor,departnum);

            showdoctor(founddoctor);
            break;
        }
        case 70:
            break;
        default:
            otherinputinterface();
            break;
        }
        if(department==70)
            return;
        getchar();
        getchar();

    }

}
void finddoctor()
{
    system("cls");
    char doctorID[6];
    gotoXY(45,13);
    printf("������ҽ������:");
    scanf("%s",doctorID);
    Record* foundrecord=findDoctor(record,doctorID);
    foundrecord=foundrecord->next;
    int count=3;
    if(foundrecord==NULL)
    {
        while(count>=0)
        {
            system("cls");

            gotoXY(45,13);
            printf("��ҽ�������� (����%ds�󷵻���һ��)",count);
            count--;
            Sleep(800);
        }
        ;
        return;
    }


    system("cls");
    showdoctordetail(&foundrecord->doctor);
    gotoXY(40,13);
    printf("---------------------------------------------");
    gotoXY(45,15);
    printf("�Ƿ���Ҫ��ʾ��ػ�����Ϣ");
    gotoXY(45,17);
    printf("1.��ʾ��ػ�����Ϣ");
    gotoXY(65,17);
    printf("2.������һ��");
    gotoXY(45,19);
    printf("������ѡ���Ӧ���: ");
    int flag;
    scanf("%d",&flag);
    switch (flag) {
    case 1:
    {
        int line=15;
        while(foundrecord)
        {
            system("cls");
            showpatientsimple(&foundrecord->patient,line);
            foundrecord=foundrecord->next;
            line++;

        }
        getchar();

        break;
    }
    case 2:
        return;
    }
    getchar();
}
void findpatient()
{
    system("cls");
    char patientID[6];
    gotoXY(40,13);
    printf("�����뻼�����֤��:");
    scanf("%s",patientID);
    Record* foundrecord=findPatient(record,patientID);


    int count=3;
    if(foundrecord->next==NULL)
    {
        while(count>=0)
        {
            system("cls");

            gotoXY(45,13);
            printf("�û��߲����� (����%ds�󷵻���һ��)",count);
            count--;
            Sleep(800);
        }

        return;
    }

    system("cls");
    int line=9;
    showpatientdetail(foundrecord,line);

    getchar();
    getchar();
}
void findtime()
{
    system("cls");
    Date start;
    while(1)
    {
        system("cls");
        gotoXY(35,13);
        printf("�������ѯ��ʼ���ڵ�������: ");
        scanf("%d%d%d",&start.year,&start.mon,&start.day);
        start.hour=0;
        start.minute=0;
        if(judgedateformat(start))break;
        else errortimeinterface();
    }
    Date end;
    while(1)
    {
        gotoXY(35,13);
        printf("�������ѯ��ʼ���ڵ�������: %d %d %d",start.year,start.mon,start.day);
        gotoXY(35,15);
        printf("�������ѯ��ֹ���ڵ�������: ");
        scanf("%d%d%d",&end.year,&end.mon,&end.day);
        end.hour=23;
        end.minute=59;
        if(judgedateformat(end))break;
        else errortimeinterface();
    }
    Record* foundtime=findTime(record,start,end);


    int count=3;
    if(foundtime->next==NULL)
    {
        while(count>=0)
        {
            system("cls");

            gotoXY(35,13);
            printf("��ʱ�����δ���ҵ���Ϣ (����%ds�󷵻���һ��)",count);
            count--;
            Sleep(800);
        }

        return;
    }

    system("cls");
    int line=5;
    showfindtimepatient(foundtime,line);

    getchar();
    getchar();

}
