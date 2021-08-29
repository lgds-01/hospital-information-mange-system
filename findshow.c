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
    printf("查询科室医生信息");
    gotoXY(x,y);
    printf("--------------------");
    gotoXY(x,y+14);
    printf("--------------------");

    int col=x+6;
    gotoXY(col,y+1);
    printf("10.口腔科");
    gotoXY(col,y+3);
    printf("20.儿科");
    gotoXY(col,y+5);
    printf("30.皮肤科");
    gotoXY(col,y+7);
    printf("40.内科");
    gotoXY(col,y+9);
    printf("50.外科");
    gotoXY(col,y+11);
    printf("60.眼科");
    gotoXY(col,y+13);
    printf("70.返回上一级");
    gotoXY(x-4,y+16);
    printf("请输入所查询的科室对应编号:");
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
            printf("口腔科医生信息:");
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
            printf("儿科医生信息:");
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
            printf("皮肤科医生信息:");
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
            printf("内科医生信息:");
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
            printf("外科医生信息:");
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
            printf("眼科医生信息:");
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
    printf("请输入医生工号:");
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
            printf("该医生不存在 (将在%ds后返回上一级)",count);
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
    printf("是否需要显示相关患者信息");
    gotoXY(45,17);
    printf("1.显示相关患者信息");
    gotoXY(65,17);
    printf("2.返回上一级");
    gotoXY(45,19);
    printf("请输入选择对应编号: ");
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
    printf("请输入患者身份证号:");
    scanf("%s",patientID);
    Record* foundrecord=findPatient(record,patientID);


    int count=3;
    if(foundrecord->next==NULL)
    {
        while(count>=0)
        {
            system("cls");

            gotoXY(45,13);
            printf("该患者不存在 (将在%ds后返回上一级)",count);
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
        printf("请输入查询开始日期的年月日: ");
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
        printf("请输入查询开始日期的年月日: %d %d %d",start.year,start.mon,start.day);
        gotoXY(35,15);
        printf("请输入查询终止日期的年月日: ");
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
            printf("该时间段内未查找到信息 (将在%ds后返回上一级)",count);
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
