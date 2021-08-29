#ifndef DOCTOR_H
#define DOCTOR_H
#include <stdbool.h>
typedef struct Doctor Doctor;
struct Doctor
{
    char    name[20];   //名字
    int     level;      // 级别 10主任医师 20副主任医师 30主治医师 40住院医师
    int     department; // 科室 同级别一样用数字代替（最多9个）如外科10 内科20
    char    ID[6];      // 工号 唯一 5位 科室+级别+序列 如10201
    bool    time[7];    // 出诊时间 0周一 1周二 2周三。。。5周六 6周日
    Doctor *next;
};
#endif // DOCTOR_H
