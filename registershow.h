#ifndef REGISTERSHOW_H
#define REGISTERSHOW_H
#include "patient.h"
#include <stdbool.h>
int  registerd(char *);
bool makeregisternum(Patient *p,
                     int      flag);
bool judgedoctorfree(char *);
#endif // REGISTERSHOW_H
