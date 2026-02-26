#include "MultString.h"

/*
 * @brief       const char* MultStr_GetS(const MultStr_Def* multStr)
 * @details     返回当前语言的字符串
 */
const char *MultStr_GetS(const MultStr_Def *multStr)
{
    if(multStr == NULL) {
        return "";
    }    
    switch(0) {
        case LANGUAGE_CH: {
            return multStr->strCH;
        }
        case LANGUAGE_EN: {
            return multStr->strEN;
        }
        case LANGUAGE_DE: {
            return multStr->strDE;
        }
        default: {
            return "unknow";
        }
    }
}




VOID_MULTSTR(mStr_Root) = {"root", "root", "root"};

