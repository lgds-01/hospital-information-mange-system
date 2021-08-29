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
        printf("%d.医生姓名:%s",count++,p->name);
        gotoXY(col+25,line);
        printf("级别:");
        switch (p->level) {
        case 10:
            printf("主任医师");
            break;
        case 20:
            printf("副主任医师");
            break;
        case 30:
            printf("主治医师");
            break;
        case 40:
            printf("住院医师");
            break;
        }
        gotoXY(col+43,line);
        printf("工号:%s",p->ID);
        gotoXY(col+60,line);
        printf("出诊时间:");
        for(int i=0;i<7;i++)
        {
            switch (i) {
            case 0:
                if(p->time[i])
                    printf("星期一 ");
                break;
            case 1:
                if(p->time[i])
                    printf("星期二 ");
                break;
            case 2:
                if(p->time[i])
                    printf("星期三 ");
                break;
            case 3:
                if(p->time[i])
                    printf("星期四 ");
                break;
            case 4:
                if(p->time[i])
                    printf("星期五 ");
                break;
            case 5:
                if(p->time[i])
                    printf("星期六 ");
                break;
            case 6:
                if(p->time[i])
                    printf("星期日 ");
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
    printf("医生姓名:%s",p->name);
    gotoXY(col+33,line);
    printf("级别:");
    switch (p->level) {
    case 10:
        printf("主任医师");
        break;
    case 20:
        printf("副主任医师");
        break;
    case 30:
        printf("主治医师");
        break;
    case 40:
        printf("住院医师");
        break;
    }
    gotoXY(col+47,line);
    printf("工号:%s",p->ID);
    gotoXY(col+58,line);
    printf("出诊时间:");
    for(int i=0;i<7;i++)
    {
        switch (i) {
        case 0:
            if(p->time[i])
                printf("星期一 ");
            break;
        case 1:
            if(p->time[i])
                printf("星期二 ");
            break;
        case 2:
            if(p->time[i])
                printf("星期三 ");
            break;
        case 3:
            if(p->time[i])
                printf("星期四 ");
            break;
        case 4:
            if(p->time[i])
                printf("星期五 ");
            break;
        case 5:
            if(p->time[i])
                printf("星期六 ");
            break;
        case 6:
            if(p->time[i])
                printf("星期日 ");
            break;
        }
    }

}
void showpatientsimple(Patient* patient,int line)
{
    Patient* p=patient;
    int col=35;
    gotoXY(col-5,line-1);
    printf("患者姓名:%s",p->name);
    gotoXY(col+15,line-1);
    printf("患者年龄:%d",p->age);
    gotoXY(col+30,line-1);
    printf("患者ID:%s",p->ID);

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
        printf("单号:%s",p->ID);
        gotoXY(col+25,line+2);
        printf("医生名字:%s",p->doctor.name);
        gotoXY(col+43,line+2);
        printf("医生工号:%s",p->doctor.ID);

        Medicine* m=p->detail.medicine->next;
        for(int i=0;i<p->detail.medicinecount;i++)
        {
            gotoXY(col,line+3+i);
            printf("药品名字:%s 单价:%.2f 数量:%d   ",m->name,m->price,m->quantity);
            m=m->next;
        }
        Check* n=p->detail.check->next;
        for(int i=0;i<p->detail.checkcount;i++)
        {
            gotoXY(col,line+3+i+p->detail.medicinecount);
            printf("检查名字:%s 费用:%.2f",n->name,n->expense);
            n=n->next;
        }
        gotoXY(col,line+3+p->detail.medicinecount+p->detail.checkcount);
        printf("检查总费用:%.2f    药品总费用:%.2f    住院总费用:%.2f",p->detail.checkexpense,p->detail.medicineexpense,p->detail.inhosexpense);

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
        printf("患者姓名:%s   患者年龄:%d   患者挂号:%s",p->patient.name,p->patient.age,p->patient.registernum[0]);
        gotoXY(col,line++);
        printf("主治医生姓名:%s   医生工号:%s",p->doctor.name,p->doctor.ID);
        Medicine* m=p->detail.medicine->next;
        for(int i=0;i<p->detail.medicinecount;i++)
        {
            gotoXY(col,line++);
            printf("药品名字:%s 单价:%.2f 数量:%d   ",m->name,m->price,m->quantity);
            m=m->next;
        }
        Check* n=p->detail.check->next;
        for(int i=0;i<p->detail.checkcount;i++)
        {
            gotoXY(col,line++);
            printf("检查名字:%s 费用:%.2f",n->name,n->expense);
            n=n->next;
        }
        gotoXY(col,line++);
        printf("检查总费用:%.2f    药品总费用:%.2f    ",p->detail.checkexpense,p->detail.medicineexpense);
        if(p->detail.flag==1)
            printf("住院总费用:%.2f",p->detail.inhosexpense);
        p=p->next;
        line+=2;
    }
}

