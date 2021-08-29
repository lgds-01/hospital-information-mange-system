#ifndef FINDFUNC_H
#define FINDFUNC_H
#include "doctor.h"
#include "record.h"
#include "stdbool.h"
Doctor* findDepartment(Doctor *doctor,
                       char    departnum[]); // 通过科室查找科室所有医生
Record* findDoctor(Record *record,
                   char    doctorID[]);      // 通过医生查找该医生所有患者诊疗纪录
Record* findPatient(Record *record,
                    char    patientID[]);    // 通过患者查找该患者所有诊疗纪录

Record* findTime(Record *record,
                 Date    start,
                 Date    end); // 查找一定时间范围内所有诊疗纪录
Record* findRecord(Record *,
                   char[]);    // 查找特定一条诊疗纪录
#endif // FINDFUNC_H
