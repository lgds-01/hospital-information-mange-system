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
            printf("�������ѯ�Ŀ�ʼʱ��(������): ");
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
            printf("�������ѯ�Ŀ�ʼʱ��(������): %d %d %d",start.year,start.mon,start.day);
            gotoXY(30,14);
            printf("�������ѯ�Ľ���ʱ��(������): ");
            scanf("%d%d%d",&now.year,&now.mon,&now.day);
            now.hour=0;
            now.minute=0;
            if(judgedateformat(now))break;
            else errortimeinterface();
        }
        gotoXY(45,16);
        printf("��Ӫҵ��:%.2lf",calhostotal(record,start,now));
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
                printf("��������:%s ��������:%d ���߹Һ�:%s",p->patient.name,p->patient.age,p->ID);
                gotoXY(col,line++);
                printf("����ҽ��:%s ҽ������:%s",p->doctor.name,p->doctor.ID);
                gotoXY(col,line++);
                printf("סԺ��ʼ����:%d��%d��%d��  ",p->detail.inhos.start.year,p->detail.inhos.start.mon,p->detail.inhos.start.day);
                printf("Ԥ�Ƴ�Ժʱ��:%d��%d��%d��",p->detail.inhos.planed.year,p->detail.inhos.planed.mon,p->detail.inhos.planed.day);
                line++;
                count++;
            }
            p=p->next;
        }
        gotoXY(col,line++);
        printf("����סԺ����:%d",count);
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
            printf("1.��ǻ�� 2.���� 3.Ƥ���� 4.�ڿ� 5.��� 6.�ۿ� 7.������һ��");
            gotoXY(col+5,line+2);
            printf("�������ѯ�Ŀ��Ҷ�Ӧ���: ");
            int num;
            scanf("%d",&num);
            if(num==7||(num!=1||num!=2||num!=3||num!=4||num!=5||num!=6))
                break;
            Date start;
            while(1)
            {
                system("cls");
                gotoXY(col,line);
                printf("1.��ǻ�� 2.���� 3.Ƥ���� 4.�ڿ� 5.��� 6.�ۿ� 7.������һ��");
                gotoXY(col+5,line+2);
                printf("�������ѯ�Ŀ��Ҷ�Ӧ���: %d",num);
                gotoXY(col,line+4);
                printf("�������ѯ�Ŀ�ʼʱ��(������): ");
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
                printf("1.��ǻ�� 2.���� 3.Ƥ���� 4.�ڿ� 5.��� 6.�ۿ� 7.������һ��");
                gotoXY(col+5,line+2);
                printf("�������ѯ�Ŀ��Ҷ�Ӧ���: %d",num);
                gotoXY(col,line+4);
                printf("�������ѯ�Ŀ�ʼʱ��(������): %d %d %d",start.year,start.mon,start.day);
                gotoXY(col,line+5);
                printf("�������ѯ�Ľ���ʱ��(������): ");
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
                    printf("ҽ������:%s   ��æ�̶�:",p->name);
                    if(caldoctorbusy(record,p->ID,start,now)>1)
                        printf("��æ");
                    else if(caldoctorbusy(record,p->ID,start,now)==1)
                        printf("�ȽϷ�æ");
                    else printf("����");

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
                    printf("ҽ������:%s   ��æ�̶�:",p->name);
                    if(caldoctorbusy(record,p->ID,start,now)>1)
                        printf("��æ");
                    else if(caldoctorbusy(record,p->ID,start,now)==1)
                        printf("�ȽϷ�æ");
                    else printf("����");

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
                    printf("ҽ������:%s   ��æ�̶�:",p->name);
                    if(caldoctorbusy(record,p->ID,start,now)>1)
                        printf("��æ");
                    else if(caldoctorbusy(record,p->ID,start,now)==1)
                        printf("�ȽϷ�æ");
                    else printf("����");

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
                    printf("ҽ������:%s   ��æ�̶�:",p->name);
                    if(caldoctorbusy(record,p->ID,start,now)>1)
                        printf("��æ");
                    else if(caldoctorbusy(record,p->ID,start,now)==1)
                        printf("�ȽϷ�æ");
                    else printf("����");

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
                    printf("ҽ������:%s   ��æ�̶�:",p->name);
                    if(caldoctorbusy(record,p->ID,start,now)>1)
                        printf("��æ");
                    else if(caldoctorbusy(record,p->ID,start,now)==1)
                        printf("�ȽϷ�æ");
                    else printf("����");

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
                    printf("ҽ������:%s   ��æ�̶�:",p->name);
                    if(caldoctorbusy(record,p->ID,start,now)>1)
                        printf("��æ");
                    else if(caldoctorbusy(record,p->ID,start,now)==1)
                        printf("�ȽϷ�æ");
                    else printf("����");

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
