#include"string.h"
#include"calfunc.h"
#include<stdio.h>
/*���㵥�������ܼ�����*/
float calcheck(Check *check)
{
    float cost=0;
    Check *p = check->next;
    while(p){
        cost += p->expense;
        p=p->next;
    }
    return cost;
}

/*���㵥��������ҩƷ����*/
float calmedicine(Medicine *medicine)
{
    float cost=0;
    Medicine *p =medicine->next;
    while(p){
        cost +=p->price*p->quantity;
        p=p->next;
    }
    return cost;
}

int calday(Date date)//�����������һ���еڼ���
{
    int x=0;
    if((date.year%4==0 && date.year%100!=0) || (date.year%400==100))x = 1;
    int day[12]={0,31,28+x,31,30,31,30,31,31,30,31,30};
    int a1=0;
    for(int i=1;i<date.mon;i++)a1+=day[i];
    a1 +=date.day;
    return a1;
}
/*����סԺ�ܷ���*/
float calhoscost(Detail *detail)
{
    if(detail->flag)
        return 0;
    float cost=200;
    Date startdate = detail->inhos.start;
    Date enddate = detail->inhos.planed;
    int startday=calday(startdate);
    int endday=calday(enddate);
    int day=endday-startday;
    if(enddate.hour>=8){day +=1;}
    cost= cost*day;
    return cost;
}
/*����ĳ�����ƻ����ܷ���*/
float totalcost(Record *record)
{
    float cost = 0;
    cost = record->detail.inhosexpense + record->detail.checkexpense + record->detail.medicineexpense;
    return cost;
}

/*�ж�Ѻ���Ƿ��㹻*/
bool judgegurantee(Record *record)
{
    bool flag = true;
    if(record->detail.inhos.guarantee<1000){
        flag = false;
    }
    return flag;
}
//����ҽԺӪҵ��
float calhostotal(Record*record,Date start,Date now)
{
    Record*p=record->next;
    double result=0;

    while(p)
    {
        if(Datecmp(p->date,start,now))
            result += (p->detail.checkexpense + p->detail.medicineexpense + p->detail.inhosexpense);

        p=p->next;
    }
    return result;
}
//����ҽԺ��æ�̶�
int caldoctorbusy(Record*record,char doctorID[],Date start,Date end)
{
    Record*p=record->next;
    int times=0;
    while(p)
    {
        if(strcmp(p->doctor.ID,doctorID)==0&&Datecmp(p->date,start,end))
            times++;
        p=p->next;
    }
    return times;
}
