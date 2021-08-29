#include"copyfunc.h"
#include<string.h>
#include<stdlib.h>

void DoctorCopy(Doctor *des, Doctor *src)
{

    strcpy(des->ID,   src->ID);
    strcpy(des->name, src->name);
    des->department = src->department;
    des->level      = src->level;

    for (int i = 0; i <= 6; i++) des->time[i] = src->time[i];
    des->next = NULL;
}
void PatientCopy(Patient *des, Patient *src)
{

    strcpy(des->ID,   src->ID);
    des->age = src->age;
    strcpy(des->name, src->name);
    des->count=src->count;

    for (int i = 0; i < src->count; i++) strcpy(des->registernum[i], src->registernum[i]);
    des->next = NULL;
}
void CheckCopy(Check *des, Check *src)
{
    des->expense = src->expense;
    strcpy(des->name, src->name);
    des->next = NULL;
}
void CheckListCopy(Check *des, Check *src)
{
    Check *p = (Check *)malloc(sizeof(Check));

    des->next = p;
    Check *m     = src->next;
    Check *front = des;
    Check *q     = NULL;

    while (m)
    {
        CheckCopy(p, m);
        q       = (Check *)malloc(sizeof(Check));
        p->next = q;
        p       = q;
        m       = m->next;
        front   = front->next;
    }
    free(p);
    front->next = NULL;
}

void MedicineCopy(Medicine *des, Medicine *src)
{
    strcpy(des->name, src->name);
    des->price    = src->price;
    des->quantity = src->quantity;
    des->next     = NULL;
}
void MedicineListCopy(Medicine *des, Medicine *src)
{
    Medicine *p = (Medicine *)malloc(sizeof(Medicine));

    des->next = p;
    Medicine *m     = src->next;
    Medicine *front = des;
    Medicine *q     =NULL;

    while (m)
    {
        MedicineCopy(p, m);
        q       = (Medicine *)malloc(sizeof(Medicine));
        p->next = q;
        p       = q;
        m       = m->next;
        front   = front->next;
    }
    free(p);
    front->next = NULL;
}
void DetailCopy(Detail *des, Detail *src)
{

    CheckListCopy(des->check, src->check);
    des->checkexpense = src->checkexpense;
    des->inhos        = src->inhos;
    des->inhosexpense = src->inhosexpense;
    des->flag=src->flag;
    des->checkcount=src->checkcount;
    des->medicinecount=src->medicinecount;
    MedicineListCopy(des->medicine, src->medicine);
    des->medicineexpense = src->medicineexpense;
}
void RecordCopy(Record *des, Record *src)
{
    des->detail.medicine=(Medicine*)malloc(sizeof(Medicine));
    des->detail.check=(Check*)malloc(sizeof(Check));
    strcpy(des->ID, src->ID);
    des->date = src->date;
    DetailCopy(&des->detail, &src->detail);
    DoctorCopy(&des->doctor, &src->doctor);
    PatientCopy(&des->patient, &src->patient);
    des->next = NULL;
}
