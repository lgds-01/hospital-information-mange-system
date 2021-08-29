#ifndef RECORD_H
#define RECORD_H
#include "doctor.h"
#include "patient.h"
#include "detail.h"

typedef struct Record Record;
struct Record // 诊疗纪录
{
    Doctor  doctor;
    Patient patient;
    Detail  detail; // 诊疗情况
    Date    date;   // 时间
    char    ID[19]; // 单号 年（4位）月（2位）+日（2位）+时（2位）+分（2位）+医生工号（5位）+患者挂号（4位）
    Record *next;
};
Record* delRecord(Record *p,
                  Record *record);
Record *addRecord(Record * newl, Record *record);
#endif // RECORD_H
