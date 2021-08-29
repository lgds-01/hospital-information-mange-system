#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"date.h"
#include<stdbool.h>
/*初始化Date*/
Date initDate()
{
    Date now;
    time_t timep;
    struct tm *pp;
    time (&timep);
    pp = localtime(&timep);
    now.year = pp->tm_year+1900;
    now.mon = pp->tm_mon+1;
    now.day = pp->tm_mday;
    now.hour = pp->tm_hour+8;
    now.minute = pp->tm_min;
    return now;
}
/*根据一个Date,能够返回char*字符串，内容为年月日时分（无空格）DatetoChar */
char* DatetoChar(Date date)
{
    char* p = (char*)malloc(13*sizeof(char));
    char a2[3];
    char a3[3];
    char a4[3];
    char a5[3];
    itoa(date.year,p,10);

    itoa(date.mon,a2,10);
    if(a2[1]=='\0')
    {
        a2[1]=a2[0];
        a2[0]='0';
    }
    itoa(date.day,a3,10);
    if(a3[1]=='\0')
    {
        a3[1]=a3[0];
        a3[0]='0';
        a3[2]='\0';
    }
    itoa(date.hour,a4,10);
    if(a4[1]=='\0')
    {
        a4[1]=a4[0];
        a4[0]='0';
        a4[2]='\0';
    }
    itoa(date.minute,a5,10);
    if(a5[1]=='\0')
    {
        a5[1]=a5[0];
        a5[0]='0';
        a5[2]='\0';
    }
    strcat(p,a2);
    strcat(p,a3);
    strcat(p,a4);
    strcat(p,a5);
    p[12]='\0';
    return p;
}
//判断是否在一定的时间范围内
bool Datecmp(Date des, Date start, Date end)
{
    if ((des.year > start.year)&&(des.year < end.year))return true;
    else if(des.year==start.year||des.year==end.year)
    {
        if ((des.mon > start.mon)&&(des.mon < end.mon)) return true;
        else if(des.mon==start.mon||des.mon==end.mon)
        {
            if ((des.day < end.day) && (des.day > start.day)) return true;
            else if(des.day==start.day||des.day==end.day)
            {
                if ((des.hour < end.hour) && (des.hour > start.hour)) return true;
                else if(des.hour==start.hour||des.hour==end.hour)
                {
                    if ((des.minute <= end.minute) &&
                        (des.minute <= start.minute)) return true;
                    else return true;
                }
                else return false;
            }
            else return false;
        }
        else return false;
    }
    else return false;

}
bool Dateafter(Date des,Date end)
{
    if (des.year > end.year)return true;
    else if(des.year==end.year)
    {
        if (des.mon > end.mon) return true;
        else if(des.mon==end.mon)
        {
            if (des.day > end.day) return true;
            else if(des.day==end.day)
            {
                if (des.hour > end.hour) return true;
                else if(des.hour==end.hour)
                {
                    if (des.minute >= end.minute) return true;
                    else return true;
                }
                else return false;
            }
            else return false;
        }
        else return false;
    }
    else return false;

}
bool judgedateformat(Date date)
{
    bool flag=false;
    int monthday[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((date.year%4==0 && date.year%100!=0 )|| date.year%400==0 ){
        monthday[1]+=1;
    }
    if(date.year>=0 && date.mon>0 && date.mon<13 && date.day>0 && date.day<=monthday[date.mon-1]){
        flag=true;
    }
    return flag;
}
