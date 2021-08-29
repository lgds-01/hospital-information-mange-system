#include"findfunc.h"
#include<stdlib.h>
#include<string.h>
#include"copyfunc.h"
#include"date.h"
//通过科室查找科室所有医生
Doctor* findDepartment(Doctor *doctor, char departnum[])
{
    Doctor *m      = doctor->next;
    Doctor *result = (Doctor *)malloc(sizeof(Doctor));
    Doctor *p      = (Doctor *)malloc(sizeof(Doctor));

    result->next = p;
    Doctor *front = result;
    Doctor *q     = NULL;

    while (m)
    {
        if (strncmp(m->ID, departnum, 2) == 0)
        {
            DoctorCopy(p, m);
            q       = (Doctor *)malloc(sizeof(Doctor));
            p->next = q;
            p       = q;
            front = front->next;
        }
        m     = m->next;

    }
    free(q);
    front->next = NULL;
    return result;
}
//通过医生查找该医生所有患者诊疗纪录
Record* findDoctor(Record *record, char doctorID[])
{
    Record *m      = record->next;
    Record *result = (Record *)malloc(sizeof(Record));
    Record *p      = (Record *)malloc(sizeof(Record));

    result->next = p;
    Record *front = result;
    Record *q     = NULL;

    while (m)
    {
        if (strcmp(m->doctor.ID, doctorID) == 0)
        {
            RecordCopy(p, m);
            q       = (Record *)malloc(sizeof(Record));
            p->next = q;
            p       = q;
            front = front->next;
        }
        m     = m->next;

    }
    free(q);
    front->next = NULL;
    return result;
}
//通过患者查找该患者所有诊疗纪录
Record* findPatient(Record *record, char patientID[])
{
    Record *m      = record->next;
    Record *result = (Record *)malloc(sizeof(Record));
    Record *p      = (Record *)malloc(sizeof(Record));

    result->next = p;
    Record *front = result;
    Record *q     = NULL;

    while (m)
    {
        if (strcmp(m->patient.ID, patientID) == 0)
        {
            RecordCopy(p, m);
            q       = (Record *)malloc(sizeof(Record));
            p->next = q;
            p       = q;
            front = front->next;
        }
        m     = m->next;

    }
    free(q);
    front->next = NULL;
    return result;
}
//查找一定时间范围内所有诊疗纪录
Record* findTime(Record *record, Date start, Date end)
{
    Record *m      = record->next;
    Record *result = (Record *)malloc(sizeof(Record));
    Record *p      = (Record *)malloc(sizeof(Record));

    result->next = p;
    Record *front = result;
    Record *q     = NULL;

    while (m)
    {
        if (Datecmp(m->date, start, end))
        {
            RecordCopy(p, m);
            q       = (Record *)malloc(sizeof(Record));
            p->next = q;
            p       = q;
            front = front->next;
        }
        m     = m->next;

    }
    free(q);
    front->next = NULL;
    return result;
}
//查找特定一条诊疗纪录
Record* findRecord(Record*record,char recordID[])
{
    Record *m      = record->next;
    Record *result=NULL;


    while (m)
    {
        if (strcmp(m->ID,recordID)==0)
        {
            result=m;
        }
        m     = m->next;

    }

    return result;
}
