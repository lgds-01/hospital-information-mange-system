#ifndef DATE_H
#define DATE_H
#include <stdbool.h>
typedef struct Date Date;
struct Date
{
    int year;                // 年
    int mon;                 // 月
    int day;                 // 天
    int hour;                // 时
    int minute;              // 分
};
Date  initDate();            // 获取系统时间初始化Date
char* DatetoChar(Date date); // 将一个Date转化为一个字符串
bool  Datecmp(Date des,
              Date start,
              Date end);     // 比较日期，在日期范围内返回真
bool  judgedateformat(Date date);
bool  Dateafter(Date des,
                Date end);
#endif // DATE_H
