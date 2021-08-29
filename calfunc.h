#ifndef CALFUNC_H
#define CALFUNC_H
#include "record.h"
#include <stdbool.h>
float calcheck(Check *);                              // 计算检查总费用
float calmedicine(Medicine *);                        // 计算药品总费用
float calhoscost(Detail *);                           // 计算住院总费用
float totalcost(Record *record);                      // 计算患者总费用
float calhostotal(Record *, Date, Date);              // 计算医院营业额
int   calday(Date date);                              // 计算该日期是一年中第几天
bool  judgegurantee(Record *record);                  // 判断押金是否足够
int caldoctorbusy(Record *,
                  char doctorID[], Date start, Date); // 计算医生繁忙程度
#endif // CALFUNC_H
