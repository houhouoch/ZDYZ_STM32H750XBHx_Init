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
extern VOID_MULTSTR(mStr_Menu);
extern VOID_MULTSTR(mStr_Menu_Config);
extern VOID_MULTSTR(mStr_Menu_Protect);
extern VOID_MULTSTR(mStr_Menu_Measure);
extern VOID_MULTSTR(mStr_Menu_Trigger);
extern VOID_MULTSTR(mStr_Menu_Recall);
extern VOID_MULTSTR(mStr_Menu_Save);
extern VOID_MULTSTR(mStr_Menu_Meter);
extern VOID_MULTSTR(mStr_Menu_Recorder);


/* 新增 13 个 */
extern VOID_MULTSTR(mStr_Menu_Function);
extern VOID_MULTSTR(mStr_Menu_Delays);
extern VOID_MULTSTR(mStr_Menu_Coupling);
extern VOID_MULTSTR(mStr_Menu_Group);
extern VOID_MULTSTR(mStr_Menu_General);
extern VOID_MULTSTR(mStr_Menu_Digital_IO);
extern VOID_MULTSTR(mStr_Menu_Preference);
extern VOID_MULTSTR(mStr_Menu_Log);
extern VOID_MULTSTR(mStr_Menu_Admin);
extern VOID_MULTSTR(mStr_Menu_Communication);
extern VOID_MULTSTR(mStr_Menu_Info);
extern VOID_MULTSTR(mStr_Menu_Energy);
extern VOID_MULTSTR(mStr_Menu_Date);

#endif
