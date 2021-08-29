#include"storefunc.h"
#include<stdio.h>
#include"gobal.h"
#include<string.h>

bool storeRecord(Record *record)//将诊疗记录存入文件
{
    Date date=initDate();
    char* now=DatetoChar(date);
    now[8]='\0';
    char filename[18]="record";
    strcat(filename,now);
    strcat(filename,".txt");
    FILE* fp=fopen(filename,"w");
    Record* p=record->next;
    while(p)
    {
        fprintf(fp,"%s %d %d %s ",p->doctor.name,p->doctor.level,p->doctor.department,p->doctor.ID);
        for(int i=0;i<7;i++)fprintf(fp,"%d ",p->doctor.time[i]);
        fprintf(fp,"%s %d %s %d ",p->patient.name,p->patient.age,p->patient.ID,p->patient.count);
        for(int i=0;i<p->patient.count;i++)fprintf(fp,"%s ",p->patient.registernum[i]);
        fprintf(fp,"%d %d ",p->detail.checkcount,p->detail.medicinecount);
        Check*m=p->detail.check->next;
        while(m)
        {
            fprintf(fp,"%s %f ",m->name,m->expense);
            m=m->next;

        }
        Medicine* n=p->detail.medicine->next;
        while(n)
        {
            fprintf(fp,"%s %f %d ",n->name,n->price,n->quantity);
            n=n->next;
        }
        fprintf(fp,"%d ",p->detail.flag);
        fprintf(fp,"%d %d %d %d %d ",p->detail.inhos.start.year,p->detail.inhos.start.mon,p->detail.inhos.start.day,p->detail.inhos.start.hour,p->detail.inhos.start.minute);
        fprintf(fp,"%d %d %d %d %d %f ",p->detail.inhos.planed.year,p->detail.inhos.planed.mon,p->detail.inhos.planed.day,p->detail.inhos.planed.hour,p->detail.inhos.planed.minute,p->detail.inhos.guarantee);
        fprintf(fp,"%d %d %d %d %d %s\n",p->date.year,p->date.mon,p->date.day,p->date.hour,p->date.minute,p->ID);
        p=p->next;
    }
    fclose(fp);
    return true;
}
bool storePatient(Patient *patient)//将患者表存入文件
{
    FILE* fp=fopen("patient.txt","w");
    Patient*p=patient->next;
    while(p)
    {
        fprintf(fp,"%s %d %s %d ",p->name,p->age,p->ID,p->count);
        for(int i=0;i<p->count;i++)fprintf(fp,"%s ",p->registernum[i]);
        fprintf(fp,"\n");
        p=p->next;
    }
    fclose(fp);
    return true;

}
bool storeDoctor(Doctor *doctor)//将医生表存入文件
{
    FILE* fp=fopen("doctor.txt","w");
    Doctor*p=doctor->next;
    while(p)
    {
        fprintf(fp,"%s %d %d %s ",p->name,p->level,p->department,p->ID);
        for(int i=0;i<7;i++)fprintf(fp,"%d ",p->time[i]);
        fprintf(fp,"\n");
        p=p->next;
    }
    fclose(fp);
    return true;
}

void storeall()
{
    storePatient(patient);
    storeDoctor(doctor);
    storeRecord(record);
}
