#ifndef SHOW_H
#define SHOW_H
#include "record.h"
#include "findshow.h"
#include "storeshow.h"
#include "statisticsshow.h"
#include "modifyshow.h"
#include "registershow.h"
#include "payshow.h"
void showdepartmentdetail();
void showdoctor(Doctor *founddoctor);
void showdoctordetail(Doctor *doctor
                      );
void showpatientsimple(Patient *,
                       int);
void showpatientdetail(Record *,
                       int);
void showfindtimepatient(Record *,
                         int);
#endif // SHOW_H
