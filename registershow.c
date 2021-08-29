#include"registershow.h"
#include"stdio.h"
#include"stdlib.h"
#include"interface.h"
#include"record.h"
#include"gobal.h"
#include"otherfunc.h"
#include"string.h"
#include"findfunc.h"
#include"show.h"

int registerd(char* ID)
{
    int modifyinput;
    scanf("%d",&modifyinput);
    system("cls");

  switch (modifyinput) {
    case 1:
    {
        int line=9;
        int col=47;

        Patient* p=(Patient*)malloc(sizeof(Patient));
        p->count=0;
        strcpy(p->ID,ID);
        Patient*m=patient->next;
        while(m)
        {
            if(strcmp(m->ID,p->ID)==0)
                break;
            m=m->next;
        }

        if(m==NULL)
        {
            gotoXY(col+5,line++);
            printf("新建患者信息");
            gotoXY(col-4,line++);
            printf("----------------------------");
            gotoXY(col-2,line++);
            printf("请输入患者姓名:");
            scanf("%s",p->name);
            gotoXY(col-2,line++);
            printf("请输入患者年龄:");
            scanf("%d",&p->age);
        }
        else
        {
            Date now=initDate();
            char* temp=DatetoChar(now);
            temp[8]='\0';
            char date[9];
            int u=0;
            for(int i=0;i<m->count;i++)
            {
                for(int j=0;j<8;j++)
                    date[j]=m->registernum[i][j];
                date[8]='\0';
                if(strcmp(date,temp)==0)u++;
                else strcpy(m->registernum[i]," ");
            }
            m->count=u;
            if(m->count==5)
            {
                system("cls");
                gotoXY(45,12);
                printf("您今日挂号次数已用完");
                getchar();
                getchar();

                return 0;
            }
        }
        gotoXY(col-6,line++);
        printf("1.口腔科 2.儿科 3.皮肤科 4.内科 5.外科 6.眼科");
        int flag;
        gotoXY(col-3,line++);
        printf("请输入挂号科室对应编号:");
        scanf("%d",&flag);
        switch (flag) {
        case 1:
        {
            do
            {
                if(m!=NULL)
                {
                    for(int i=0;i<m->count;i++)
                    {
                        Date now=initDate();
                        char* temp=DatetoChar(now);
                        temp[8]='\0';
                        char date[9];
                        for(int j=0;j<8;j++)
                            date[j]=m->registernum[i][j];
                        date[8]='\0';
                        char num[3];
                        num[0]=m->registernum[i][12];
                        num[1]=m->registernum[i][13];
                        num[2]='\0';
                        if(strcmp(temp,date)!=0||strcmp(num,"10")!=0)
                        {}
                        else
                        {

                            system("cls");
                            gotoXY(40,12);
                            printf("您今天已在该科室挂号，请勿重复挂号");
                            getchar();
                            getchar();
                            return 0;
                        }

                    }
                }
                if(makeregisternum(p,flag))break;
                else
                {
                    system("cls");
                    gotoXY(45,12);
                    printf("该医生门诊名额已满");
                    getchar();
                    getchar();
                }
            }while(1);
            break;
        }
        case 2:
        {
            do
            {
                if(m!=NULL)
                {
                    for(int i=0;i<m->count;i++)
                    {
                        Date now=initDate();
                        char* temp=DatetoChar(now);
                        temp[8]='\0';
                        char date[9];
                        for(int j=0;j<8;j++)
                            date[j]=m->registernum[i][j];
                        date[8]='\0';
                        char num[3];
                        num[0]=m->registernum[i][12];
                        num[1]=m->registernum[i][13];
                        num[2]='\0';
                        if(strcmp(temp,date)!=0||strcmp(num,"20")!=0)
                        {}
                        else
                        {

                            system("cls");
                            gotoXY(40,12);
                            printf("您今天已在该科室挂号，请勿重复挂号");
                            getchar();
                            getchar();
                            return 0;
                        }
                    }
                }
                if(makeregisternum(p,flag))break;
                else
                {
                    system("cls");
                    gotoXY(45,12);
                    printf("该医生门诊名额已满");
                    getchar();
                    getchar();
                }
            }while(1);
            break;
        }
        case 3:
        {
            do
            {
                if(m!=NULL)
                {
                    for(int i=0;i<m->count;i++)
                    {
                        Date now=initDate();
                        char* temp=DatetoChar(now);
                        temp[8]='\0';
                        char date[9];
                        for(int j=0;j<8;j++)
                            date[j]=m->registernum[i][j];
                        date[8]='\0';
                        char num[3];
                        num[0]=m->registernum[i][12];
                        num[1]=m->registernum[i][13];
                        num[2]='\0';
                        if(strcmp(temp,date)!=0||strcmp(num,"30")!=0)
                        {}
                        else
                        {

                            system("cls");
                            gotoXY(40,12);
                            printf("您今天已在该科室挂号，请勿重复挂号");
                            getchar();
                            getchar();
                            return 0;
                        }

                    }
                }
                if(makeregisternum(p,flag))break;
                else
                {
                    system("cls");
                    gotoXY(45,12);
                    printf("该医生门诊名额已满");
                    getchar();
                    getchar();
                }
            }while(1);
            break;
        }
        case 4:
        {
            do
            {
                if(m!=NULL)
                {
                    for(int i=0;i<m->count;i++)
                    {
                        Date now=initDate();
                        char* temp=DatetoChar(now);
                        temp[8]='\0';
                        char date[9];
                        for(int j=0;j<8;j++)
                            date[j]=m->registernum[i][j];
                        date[8]='\0';
                        char num[3];
                        num[0]=m->registernum[i][12];
                        num[1]=m->registernum[i][13];
                        num[2]='\0';
                        if(strcmp(temp,date)!=0||strcmp(num,"40")!=0)
                        {}
                        else
                        {

                            system("cls");
                            gotoXY(40,12);
                            printf("您今天已在该科室挂号，请勿重复挂号");
                            getchar();
                            getchar();
                            return 0;
                        }

                    }
                }
                if(makeregisternum(p,flag))break;
                else
                {
                    system("cls");
                    gotoXY(45,12);
                    printf("该医生门诊名额已满");
                    getchar();
                    getchar();
                }
            }while(1);
            break;
        }
        case 5:
        {
            do
            {
                if(m!=NULL)
                {
                    for(int i=0;i<m->count;i++)
                    {
                        Date now=initDate();
                        char* temp=DatetoChar(now);
                        temp[8]='\0';
                        char date[9];
                        for(int j=0;j<8;j++)
                            date[j]=m->registernum[i][j];
                        date[8]='\0';
                        char num[3];
                        num[0]=m->registernum[i][12];
                        num[1]=m->registernum[i][13];
                        num[2]='\0';
                        if(strcmp(temp,date)!=0||strcmp(num,"50")!=0)
                        {}
                        else
                        {

                            system("cls");
                            gotoXY(40,12);
                            printf("您今天已在该科室挂号，请勿重复挂号");
                            getchar();
                            getchar();
                            return 0;
                        }

                    }
                }
                if(makeregisternum(p,flag))break;
                else
                {
                    system("cls");
                    gotoXY(45,12);
                    printf("该医生门诊名额已满");
                    getchar();
                    getchar();
                }
            }while(1);
            break;
        }
        case 6:
        {
            do
            {
                if(m!=NULL)
                {
                    for(int i=0;i<m->count;i++)
                    {
                        Date now=initDate();
                        char* temp=DatetoChar(now);
                        temp[8]='\0';
                        char date[9];
                        for(int j=0;j<8;j++)
                            date[j]=m->registernum[i][j];
                        date[8]='\0';
                        char num[3];
                        num[0]=m->registernum[i][12];
                        num[1]=m->registernum[i][13];
                        num[2]='\0';
                        if(strcmp(temp,date)!=0||strcmp(num,"60")!=0)
                        {}
                        else
                        {

                            system("cls");
                            gotoXY(40,12);
                            printf("您今天已在该科室挂号，请勿重复挂号");
                            getchar();
                            getchar();
                            return 0;
                        }

                    }
                }
                if(makeregisternum(p,flag))break;
                else
                {
                    system("cls");
                    gotoXY(45,12);
                    printf("该医生门诊名额已满");
                    getchar();
                    getchar();
                }
            }while(1);
            break;
        }
        }
        system("cls");
        gotoXY(40,12);
        printf("您的挂号是:%s",p->registernum[0]);

        p->count++;

        if(m==NULL)
        {
            p->next=patient->next->next;
            patient->next->next=p;
            gotoXY(43,14);
            printf("今日剩余挂号次数:%d",4);
        }
        else
        {
            Date now=initDate();
            char *date=DatetoChar(now);

            if(m->count==5)
            {

                for(int i=0;i<m->count;i++)
                {
                    if(strncmp(date,m->registernum[i],strlen(date))!=0)
                    {
                        strcpy(m->registernum[i],p->registernum[0]);
                        break;
                    }

                }
            }
            else
            {
                strcpy(m->registernum[m->count],p->registernum[0]);
                m->count++;
            }
            gotoXY(43,14);
            printf("今日剩余挂号次数:%d",5-m->count);
        }
        break;

    }
    case 2:
    {

        system("cls");
        Date now=initDate();
        Patient*p=patient->next;
        while(p)
        {
            if(strcmp(p->ID,ID)==0)
                break;
            p=p->next;
        }
        if(p==NULL)
        {
            system("cls");
            gotoXY(45,15);
            printf("未找到患者挂号信息");
            break;
        }
        char *date;
        date=DatetoChar(now);
        date[8]='\0';
        int count=1;
        int line=8;
        for(int i=0;i<5;i++)
        {
            if(strncmp(p->registernum[i],date,strlen(date))==0)
            {
                gotoXY(35,line++);
                printf("%d.%s 科室:",count,p->registernum[i]);
                char t[6];
                t[0]=p->registernum[i][12];
                t[1]=p->registernum[i][13];
                t[2]=p->registernum[i][14];
                t[3]=p->registernum[i][15];
                t[4]=p->registernum[i][16];
                t[5]='\0';
                Doctor* p=doctor->next;
                while(p)
                {
                    if(strcmp(p->ID,t)==0)
                    {
                        switch (p->department) {
                        case 10:
                                printf("口腔科");
                                break;
                        case 20:
                                printf("儿科");
                                break;
                        case 30:
                                printf("皮肤科");
                                break;
                        case 40:
                                printf("内科");
                                break;
                        case 50:
                            printf("外科");
                            break;
                        case 60:
                             printf("眼科");
                             break;
                        }
                        printf("  医生姓名:%s  医生工号:%s",p->name,p->ID);
                        break;
                    }
                    p=p->next;
                }
                count++;
            }
        }
        if(count==1)
        {
            gotoXY(45,line++);
            printf("今日未挂号");
        }
        gotoXY(45,line);
        printf("今日剩余挂号次数:%d",6-count);

        break;

    }
    case 3:
        return 3;
        break;

    default:
        otherinputinterface();
        break;

    }
    getchar();
    getchar();
    return 0;

}


bool makeregisternum(Patient* p,int flag)
{
    system("cls");
    Doctor* founddoctor;
    switch (flag) {
    case 1:
       founddoctor=findDepartment(doctor,"10");
       break;
    case 2:
       founddoctor=findDepartment(doctor,"20");
       break;
    case 3:
        founddoctor=findDepartment(doctor,"30");
        break;
    case 4:
        founddoctor=findDepartment(doctor,"40");
        break;
    case 5:
        founddoctor=findDepartment(doctor,"50");
        break;
    case 6:
        founddoctor=findDepartment(doctor,"60");
        break;
    }

    Doctor*pp=founddoctor->next;
    int line=8;
    int col=30;
    int count=1;
    while(pp)
    {
        gotoXY(col,line);
        printf("%d.医生姓名:%s",count++,pp->name);
        gotoXY(col+25,line);
        printf("级别:");
        switch (pp->level) {
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
        printf("工号:%s",pp->ID);
        pp=pp->next;
        line++;
    }
    gotoXY(35,14);
    printf("请输入医生对应编号:");
    int num;
    scanf("%d",&num);
    switch (num) {
    case 1:
    {
        Date now=initDate();
        char *date=DatetoChar(now);

        Doctor*t=founddoctor;
        int temp=0;
        while(temp<num)
        {
            t=t->next;
            temp++;
        }
        char aa[19]="\0";
        strcat(aa,date);
        strcat(aa,t->ID);

        char a[2];
        itoa(p->count,a,10);
        strcat(aa,a);
        strcpy(p->registernum[0],aa);
        break;

    }
    case 2:
    {
        Date now=initDate();
        char *date=DatetoChar(now);

        Doctor*t=founddoctor;
        int temp=0;
        while(temp<num)
        {
            t=t->next;
            temp++;
        }
        char aa[19]="\0";
        strcat(aa,date);
        strcat(aa,t->ID);

        char a[2];
        itoa(p->count,a,10);
        strcat(aa,a);
        strcpy(p->registernum[0],aa);
        break;

    }
    case 3:
    {
        Date now=initDate();
        char *date=DatetoChar(now);

        Doctor*t=founddoctor;
        int temp=0;
        while(temp<num)
        {
            t=t->next;
            temp++;
        }
        char aa[19]="\0";
        strcat(aa,date);
        strcat(aa,t->ID);

        char a[2];
        itoa(p->count,a,10);
        strcat(aa,a);
        strcpy(p->registernum[0],aa);
        break;

    }
    case 4:
    {
        Date now=initDate();
        char *date=DatetoChar(now);

        Doctor*t=founddoctor;
        int temp=0;
        while(temp<num)
        {
            t=t->next;
            temp++;
        }
        char aa[19]="\0";
        strcat(aa,date);
        strcat(aa,t->ID);

        char a[2];
        itoa(p->count,a,10);
        strcat(aa,a);
        strcpy(p->registernum[0],aa);
        break;

    }
    case 5:
    {
        Date now=initDate();
        char *date=DatetoChar(now);

        Doctor*t=founddoctor;
        int temp=0;
        while(temp<num)
        {
            t=t->next;
            temp++;
        }
        char aa[19]="\0";
        strcat(aa,date);
        strcat(aa,t->ID);

        char a[2];
        itoa(p->count,a,10);
        strcat(aa,a);
        strcpy(p->registernum[0],aa);
        break;

    }
    }
    char t[6];
    t[0]=p->registernum[0][12];
    t[1]=p->registernum[0][13];
    t[2]=p->registernum[0][14];
    t[3]=p->registernum[0][15];
    t[4]=p->registernum[0][16];
    t[5]='\0';
    if(judgedoctorfree(t))return true;
    else return false;
}

bool judgedoctorfree(char* doctorID)
{
    Date now=initDate();
    char* temp=DatetoChar(now);
    temp[8]='\0';
    Patient* m=patient->next;
    char date[9];
    int count=0;
    while(m)
    {
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<8;j++)
                date[j]=m->registernum[i][j];
            date[8]='\0';
            char num[6];
            num[0]=m->registernum[i][12];
            num[1]=m->registernum[i][13];
            num[2]=m->registernum[i][14];
            num[3]=m->registernum[i][15];
            num[4]=m->registernum[i][16];
            num[5]='\0';

            if(strcmp(temp,date)==0&&strcmp(num,doctorID)==0)
                count++;
        }
        m=m->next;
    }
    if(count>=20)return false;
    else return true;
}
