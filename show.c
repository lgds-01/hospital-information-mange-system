#include"show.h"
#include"otherfunc.h"
#include"stdio.h"

void showdoctor(Doctor* founddoctor)
{
    Doctor*p=founddoctor->next;
    int line=8;
    int col=20;
    int count=1;
    while(p)
    {
        gotoXY(col,line);
        printf("%d.ҽ������:%s",count++,p->name);
        gotoXY(col+25,line);
        printf("����:");
        switch (p->level) {
        case 10:
            printf("����ҽʦ");
            break;
        case 20:
            printf("������ҽʦ");
            break;
        case 30:
            printf("����ҽʦ");
            break;
        case 40:
            printf("סԺҽʦ");
            break;
        }
        gotoXY(col+43,line);
        printf("����:%s",p->ID);
        gotoXY(col+60,line);
        printf("����ʱ��:");
        for(int i=0;i<7;i++)
        {
            switch (i) {
            case 0:
                if(p->time[i])
                    printf("����һ ");
                break;
            case 1:
                if(p->time[i])
                    printf("���ڶ� ");
                break;
            case 2:
                if(p->time[i])
                    printf("������ ");
                break;
            case 3:
                if(p->time[i])
                    printf("������ ");
                break;
            case 4:
                if(p->time[i])
                    printf("������ ");
                break;
            case 5:
                if(p->time[i])
                    printf("������ ");
                break;
            case 6:
                if(p->time[i])
                    printf("������ ");
                break;
            }
        }
        p=p->next;
        line++;
    }
}
void showdoctordetail(Doctor* doctor)
{
    int line=11;
    int col=20;
    Doctor* p=doctor;

    gotoXY(col+15,line);
    printf("ҽ������:%s",p->name);
    gotoXY(col+33,line);
    printf("����:");
    switch (p->level) {
    case 10:
        printf("����ҽʦ");
        break;
    case 20:
        printf("������ҽʦ");
        break;
    case 30:
        printf("����ҽʦ");
        break;
    case 40:
        printf("סԺҽʦ");
        break;
    }
    gotoXY(col+47,line);
    printf("����:%s",p->ID);
    gotoXY(col+58,line);
    printf("����ʱ��:");
    for(int i=0;i<7;i++)
    {
        switch (i) {
        case 0:
            if(p->time[i])
                printf("����һ ");
            break;
        case 1:
            if(p->time[i])
                printf("���ڶ� ");
            break;
        case 2:
            if(p->time[i])
                printf("������ ");
            break;
        case 3:
            if(p->time[i])
                printf("������ ");
            break;
        case 4:
            if(p->time[i])
                printf("������ ");
            break;
        case 5:
            if(p->time[i])
                printf("������ ");
            break;
        case 6:
            if(p->time[i])
                printf("������ ");
            break;
        }
    }

}
void showpatientsimple(Patient* patient,int line)
{
    Patient* p=patient;
    int col=35;
    gotoXY(col-5,line-1);
    printf("��������:%s",p->name);
    gotoXY(col+15,line-1);
    printf("��������:%d",p->age);
    gotoXY(col+30,line-1);
    printf("����ID:%s",p->ID);

}
void showpatientdetail(Record*foundrecord,int line)
{
    Record*p=foundrecord->next;
    int col=30;
    showpatientsimple(&p->patient,line);
    gotoXY(col-4,line);
    printf("------------------------------------------------------------------");
    while(p)
    {
        gotoXY(col,line+2);
        printf("����:%s",p->ID);
        gotoXY(col+25,line+2);
        printf("ҽ������:%s",p->doctor.name);
        gotoXY(col+43,line+2);
        printf("ҽ������:%s",p->doctor.ID);

        Medicine* m=p->detail.medicine->next;
        for(int i=0;i<p->detail.medicinecount;i++)
        {
            gotoXY(col,line+3+i);
            printf("ҩƷ����:%s ����:%.2f ����:%d   ",m->name,m->price,m->quantity);
            m=m->next;
        }
        Check* n=p->detail.check->next;
        for(int i=0;i<p->detail.checkcount;i++)
        {
            gotoXY(col,line+3+i+p->detail.medicinecount);
            printf("�������:%s ����:%.2f",n->name,n->expense);
            n=n->next;
        }
        gotoXY(col,line+3+p->detail.medicinecount+p->detail.checkcount);
        printf("����ܷ���:%.2f    ҩƷ�ܷ���:%.2f    סԺ�ܷ���:%.2f",p->detail.checkexpense,p->detail.medicineexpense,p->detail.inhosexpense);

        p=p->next;
        line+=6;
    }
}

void showfindtimepatient(Record*foundtime,int line)
{
    Record*p=foundtime->next;
    int col=30;

    while(p)
    {
        gotoXY(col,line++);
        printf("��������:%s   ��������:%d   ���߹Һ�:%s",p->patient.name,p->patient.age,p->patient.registernum[0]);
        gotoXY(col,line++);
        printf("����ҽ������:%s   ҽ������:%s",p->doctor.name,p->doctor.ID);
        Medicine* m=p->detail.medicine->next;
        for(int i=0;i<p->detail.medicinecount;i++)
        {
            gotoXY(col,line++);
            printf("ҩƷ����:%s ����:%.2f ����:%d   ",m->name,m->price,m->quantity);
            m=m->next;
        }
        Check* n=p->detail.check->next;
        for(int i=0;i<p->detail.checkcount;i++)
        {
            gotoXY(col,line++);
            printf("�������:%s ����:%.2f",n->name,n->expense);
            n=n->next;
        }
        gotoXY(col,line++);
        printf("����ܷ���:%.2f    ҩƷ�ܷ���:%.2f    ",p->detail.checkexpense,p->detail.medicineexpense);
        if(p->detail.flag==1)
            printf("סԺ�ܷ���:%.2f",p->detail.inhosexpense);
        p=p->next;
        line+=2;
    }
}

