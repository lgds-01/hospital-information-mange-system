#ifndef COPYFUNC_H
#define COPYFUNC_H
#include "doctor.h"
#include "record.h"
void DoctorCopy(Doctor *des,
                Doctor *src);     // 类似于doctor的赋值函数 des=src
void PatientCopy(Patient *des,
                 Patient *src);   // 类似于patient的赋值函数 des=src
void CheckCopy(Check *des,
               Check *src);       // 类似于check的赋值函数 des=src
void CheckListCopy(Check *des,
                   Check *src);   // 类似于checklist的赋值函数 des=src
void MedicineCopy(Medicine *des,
                  Medicine *src); // 类似于medicinelist的赋值函数 des=src
void MedicineListCopy(Medicine *des,
                      Medicine *src);
void DetailCopy(Detail *des,
                Detail *src); // 类似于detail的赋值函数 des=src
void RecordCopy(Record *des,
                Record *src); // 类似于record的赋值函数 des=src

#endif // COPYFUNC_H
