#include "findfunc.h"
#include "statisticsshow.h"
#include "record.h"
#include <stdio.h>
#include <windows.h>
#include "gobal.h"
#include "interface.h"
#include "otherfunc.h"
#include "calfunc.h"
int statistics()
{
    int statisticsinput;
    scanf("%d",&statisticsinput);
    switch (statisticsinput) {
    case 1:
    {
        Date start;
        while(1)
        {
            system("cls");
            gotoXY(30,13);
            printf("请输入查询的开始时间(年月日): ");
            scanf("%d%d%d",&start.year,&start.mon,&start.day);
            start.hour=0;
            start.minute=0;
            if(judgedateformat(start))break;
            else errortimeinterface();
        }
        Date now;
        while(1)
        {
            system("cls");
            gotoXY(30,13);
            printf("请输入查询的开始时间(年月日): %d %d %d",start.year,start.mon,start.day);
            gotoXY(30,14);
            printf("请输入查询的结束时间(年月日): ");
            scanf("%d%d%d",&now.year,&now.mon,&now.day);
            now.hour=0;
            now.minute=0;
            if(judgedateformat(now))break;
            else errortimeinterface();
        }
        gotoXY(45,16);
        printf("总营业额:%.2lf",calhostotal(record,start,now));
        getchar();
        getchar();

    }
        break;
    case 2:
    {
        system("cls");
        Date date=initDate();

        Record* p=record->next;
        int line=2;
        int col=25;
        int count=0;
        while(p)
        {
            if(Dateafter(p->detail.inhos.planed,date))
            {
                gotoXY(col,line++);
                printf("患者姓名:%s 患者年龄:%d 患者挂号:%s",p->patient.name,p->patient.age,p->ID);
                gotoXY(col,line++);
                printf("主治医生:%s 医生工号:%s",p->doctor.name,p->doctor.ID);
                gotoXY(col,line++);
                printf("住院开始日期:%d年%d月%d日  ",p->detail.inhos.start.year,p->detail.inhos.start.mon,p->detail.inhos.start.day);
                printf("预计出院时间:%d年%d月%d日",p->detail.inhos.planed.year,p->detail.inhos.planed.mon,p->detail.inhos.planed.day);
                line++;
                count++;
            }
            p=p->next;
        }
        gotoXY(col,line++);
        printf("现有住院人数:%d",count);
        getchar();
        getchar();
        break;

    }
    case 3:
    {
        while(1)
        {
            system("cls");
            int line=8;
            int col=27;
            gotoXY(col,line);
            printf("1.口腔科 2.儿科 3.皮肤科 4.内科 5.外科 6.眼科 7.返回上一级");
            gotoXY(col+5,line+2);
            printf("请输入查询的科室对应编号: ");
            int num;
            scanf("%d",&num);
            if(num==7||(num!=1||num!=2||num!=3||num!=4||num!=5||num!=6))
                break;
            Date start;
            while(1)
            {
                system("cls");
                gotoXY(col,line);
                printf("1.口腔科 2.儿科 3.皮肤科 4.内科 5.外科 6.眼科 7.返回上一级");
                gotoXY(col+5,line+2);
                printf("请输入查询的科室对应编号: %d",num);
                gotoXY(col,line+4);
                printf("请输入查询的开始时间(年月日): ");
                scanf("%d%d%d",&start.year,&start.mon,&start.day);
                start.hour=0;
                start.minute=0;
                if(judgedateformat(start))break;
                else errortimeinterface();
            }
            Date now;
            while(1)
            {
                system("cls");
                gotoXY(col,line);
                printf("1.口腔科 2.儿科 3.皮肤科 4.内科 5.外科 6.眼科 7.返回上一级");
                gotoXY(col+5,line+2);
                printf("请输入查询的科室对应编号: %d",num);
                gotoXY(col,line+4);
                printf("请输入查询的开始时间(年月日): %d %d %d",start.year,start.mon,start.day);
                gotoXY(col,line+5);
                printf("请输入查询的结束时间(年月日): ");
                scanf("%d%d%d",&now.year,&now.mon,&now.day);
                now.hour=0;
                now.minute=0;
                if(judgedateformat(now))break;
                else errortimeinterface();
            }
            switch (num) {
            case 1:
            {
                system("cls");
                Doctor* founddoctor=findDepartment(doctor,"10");
                Doctor*p=founddoctor->next;
                int count=0;
                while(p)
                {
                    gotoXY(col+15,line+count);
                    printf("医生姓名:%s   繁忙程度:",p->name);
                    if(caldoctorbusy(record,p->ID,start,now)>1)
                        printf("繁忙");
                    else if(caldoctorbusy(record,p->ID,start,now)==1)
                        printf("比较繁忙");
                    else printf("空闲");

                    count+=2;
                    p=p->next;
                }
                getchar();
                getchar();
                break;
            }
            case 2:
            {
                system("cls");
                Doctor* founddoctor=findDepartment(doctor,"20");
                Doctor*p=founddoctor->next;
                int count=0;
                while(p)
                {
                    gotoXY(col+15,line+count);
                    printf("医生姓名:%s   繁忙程度:",p->name);
                    if(caldoctorbusy(record,p->ID,start,now)>1)
                        printf("繁忙");
                    else if(caldoctorbusy(record,p->ID,start,now)==1)
                        printf("比较繁忙");
                    else printf("空闲");

                    count+=2;
                    p=p->next;
                }
                getchar();
                getchar();
                break;
            }
            case 3:
            {
                system("cls");
                Doctor* founddoctor=findDepartment(doctor,"30");
                Doctor*p=founddoctor->next;
                int count=0;
                while(p)
                {
                    gotoXY(col+15,line+count);
                    printf("医生姓名:%s   繁忙程度:",p->name);
                    if(caldoctorbusy(record,p->ID,start,now)>1)
                        printf("繁忙");
                    else if(caldoctorbusy(record,p->ID,start,now)==1)
                        printf("比较繁忙");
                    else printf("空闲");

                    count+=2;
                    p=p->next;
                }
                getchar();
                getchar();
                break;
            }
            case 4:
            {
                system("cls");
                Doctor* founddoctor=findDepartment(doctor,"40");
                Doctor*p=founddoctor->next;
                int count=0;
                while(p)
                {
                    gotoXY(col+15,line+count);
                    printf("医生姓名:%s   繁忙程度:",p->name);
                    if(caldoctorbusy(record,p->ID,start,now)>1)
                        printf("繁忙");
                    else if(caldoctorbusy(record,p->ID,start,now)==1)
                        printf("比较繁忙");
                    else printf("空闲");

                    count+=2;
                    p=p->next;
                }
                getchar();
                getchar();
                break;
            }
            case 5:
            {
                system("cls");
                Doctor* founddoctor=findDepartment(doctor,"50");
                Doctor*p=founddoctor->next;
                int count=0;
                while(p)
                {
                    gotoXY(col+15,line+count);
                    printf("医生姓名:%s   繁忙程度:",p->name);
                    if(caldoctorbusy(record,p->ID,start,now)>1)
                        printf("繁忙");
                    else if(caldoctorbusy(record,p->ID,start,now)==1)
                        printf("比较繁忙");
                    else printf("空闲");

                    count+=2;
                    p=p->next;
                }
                getchar();
                getchar();
                break;
            }
            case 6:
            {
                system("cls");
                Doctor* founddoctor=findDepartment(doctor,"60");
                Doctor*p=founddoctor->next;
                int count=0;
                while(p)
                {
                    gotoXY(col+15,line+count);
                    printf("医生姓名:%s   繁忙程度:",p->name);
                    if(caldoctorbusy(record,p->ID,start,now)>1)
                        printf("繁忙");
                    else if(caldoctorbusy(record,p->ID,start,now)==1)
                        printf("比较繁忙");
                    else printf("空闲");

                    count+=2;
                    p=p->next;
                }
                getchar();
                getchar();
                break;
            }

            default:
                break;
            }
        }
    }
    case 4:
        return 4;
        break;
    default:
        otherinputinterface();
        break;
    }
    return 0;
}
