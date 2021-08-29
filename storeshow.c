#include"storeshow.h"
#include"storefunc.h"
#include"gobal.h"
#include"stdio.h"
#include"interface.h"
#include<windows.h>
#include"otherfunc.h"

int store()
{
    int storeinput;
    scanf("%d",&storeinput);
    switch (storeinput) {
    case 1:
        storeDoctor(doctor);
        storeRecord(record);
        storePatient(patient);
        int count=2;
        while(count>0)
        {
            system("cls");
            gotoXY(55,13);
            printf("±£´æ³É¹¦");
            Sleep(600);
            count--;
        }
    case 2:
        return 2;
    default:
        otherinputinterface();

    }
    return 0;

}
