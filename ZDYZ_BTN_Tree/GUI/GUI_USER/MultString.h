#ifndef _MULT_STRING_H_
#define _MULT_STRING_H_


#include <stdint.h>
#include <stddef.h>
#include <main.h>
//多国语言结构体定义
typedef struct {
    const char *strCH;
    const char *strEN;
    const char *strDE;
} MultStr_Def;

enum LANGUAGE_ENUM {
    LANGUAGE_EN = 0,        //英语
    LANGUAGE_CH,            //简体中文
    LANGUAGE_DE,

    LANGUAGE_MIN = LANGUAGE_EN,
    LANGUAGE_MAX = LANGUAGE_DE,
};
/*
 * @brief       const char* MultStr_GetS(const MultStr_Def* multStr)
 * @details     返回当前语言的字符串
 */
const char *MultStr_GetS(const MultStr_Def *multStr);


#define VOID_MULTSTR(X) const MultStr_Def X

extern VOID_MULTSTR(mStr_Root);


#endif
