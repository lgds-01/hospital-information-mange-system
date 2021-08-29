#ifndef STROEFUNC_H
#define STROEFUNC_H
#include "record.h"

bool storeRecord(Record *record);    // 存储record链表内容
bool storePatient(Patient *patient); // 存储patient链表内容
bool storeDoctor(Doctor *doctor);    // 存储doctor链表内容
void storeall();                     // 存储所有内容
#endif // STROEFUNC_H
