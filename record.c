#include"record.h"
#include<stdlib.h>
#include"copyfunc.h"
#include"string.h"

Record * delRecord(Record* p,Record *record)//ɾ�����Ƽ�¼����p�ڵ㣬����ɾ���ڵ�ǰһ�ڵ��ָ��
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
Record * addRecord(Record *new,Record *record)//����ĳһ���Ƽ�¼��p�ڵ�֮��
{

    new->next=record->next->next;
    record->next=new;
    return record;
}
