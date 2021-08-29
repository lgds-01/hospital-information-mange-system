#include"findfunc.h"
#include<stdlib.h>
#include<string.h>
#include"copyfunc.h"
#include"date.h"
//ͨ�����Ҳ��ҿ�������ҽ��
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
//ͨ��ҽ�����Ҹ�ҽ�����л������Ƽ�¼
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
//ͨ�����߲��Ҹû����������Ƽ�¼
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
//����һ��ʱ�䷶Χ���������Ƽ�¼
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
//�����ض�һ�����Ƽ�¼
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
