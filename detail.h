#ifndef DETAIL_H
#define DETAIL_H

#include "date.h"
#include <stdbool.h>

typedef struct Check      Check;
typedef struct Medicine   Medicine;
typedef struct inHospital inHospital;
typedef struct Detail     Detail;
struct Check         // 检查
{
    char   name[20]; // 检查的名字
    float  expense;  // 该检查费用
    Check *next;
};

struct Medicine         // 开药
{
    char      name[20]; // 药品名字
    float     price;    // 药品单价
    int       quantity; // 药品数量
    Medicine *next;
};

struct inHospital               // 住院
{
    Date  start;                // 住院开始日期
    Date  planed;               // 预计出院日期
    float guarantee;            // 押金
};

struct Detail                   // 诊疗情况
{
    int        checkcount;      // 检查项目个数
    int        medicinecount;   // 药品种类数量
    Check     *check;           // 检查
    Medicine  *medicine;        // 开药
    bool       flag;            // 是否住院
    inHospital inhos;           // 住院
    float      checkexpense;    // 检查总费用
    float      medicineexpense; // 药品总费用
    float      inhosexpense;    // 住院总费用
};

#endif // DETAIL_H
