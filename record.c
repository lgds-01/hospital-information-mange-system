#include"record.h"
#include<stdlib.h>
#include"copyfunc.h"
#include"string.h"

Record * delRecord(Record* p,Record *record)//删除诊疗记录表中p节点，返回删除节点前一节点的指针
{
    Record *re,*r;
    r=record;
    re=r->next;
    while(re!=NULL)
    {
        if(strcmp(re->ID,p->ID)==0)break;
        r=r->next;
        re=re->next;
    }
    r->next=re->next;
    free(re);
    return r;
}
Record * addRecord(Record *new,Record *record)//增加某一诊疗记录到p节点之后
{

    new->next=record->next->next;
    record->next=new;
    return record;
}
