#include "MultString.h"

/*
 * @brief       const char* MultStr_GetS(const MultStr_Def* multStr)
 * @details     鏉╂柨娲栬ぐ鎾冲?犵拠锟界懛鈧?閻ㄥ嫬鐡х粭锔胯??
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

VOID_MULTSTR(mStr_Root)         = {"根节点", "Root", "Stamm"};
VOID_MULTSTR(mStr_Home)         = {"主界面", "Home", "Startseite"};
VOID_MULTSTR(mStr_Menu)         = {"菜单", "Menu", "Menü"};

/* --- 主菜单子页面 --- */
VOID_MULTSTR(mStr_Menu_Config)  = {"系统配置", "Config", "Konfig"};
VOID_MULTSTR(mStr_Menu_Protect) = {"保护设置", "Protect", "Schutz"};
VOID_MULTSTR(mStr_Menu_Measure) = {"测量分析", "Measure", "Messen"};
VOID_MULTSTR(mStr_Menu_Trigger) = {"触发控制", "Trigger", "Ausl?ser"};
VOID_MULTSTR(mStr_Menu_Recall)  = {"文件读取", "Recall", "Aufrufen"};
VOID_MULTSTR(mStr_Menu_Save)    = {"数据保存", "Save", "Speichern"};
VOID_MULTSTR(mStr_Menu_Meter)   = {"仪表模式", "Meter", "Anzeige"};
VOID_MULTSTR(mStr_Menu_Recorder)= {"记录仪", "Recorder", "Rekorder"};

/* --- 新增 13 个功能页面 --- */
VOID_MULTSTR(mStr_Menu_Function)      = {"辅助功能", "Function", "Funktionen"};
VOID_MULTSTR(mStr_Menu_Delays)        = {"延时输出", "Delays", "Verz?gerung"};
VOID_MULTSTR(mStr_Menu_Coupling)      = {"耦合控制", "Coupling", "Kopplung"};
VOID_MULTSTR(mStr_Menu_Group)         = {"分组管理", "Group", "Gruppe"};
VOID_MULTSTR(mStr_Menu_General)       = {"通用设置", "General", "Allgemein"};
VOID_MULTSTR(mStr_Menu_Digital_IO)    = {"数字 I/O", "Digital IO", "Digitaler I/O"};
VOID_MULTSTR(mStr_Menu_Preference)    = {"用户偏好", "Preference", "Pr?ferenz"};
VOID_MULTSTR(mStr_Menu_Log)           = {"系统日志", "Log", "Protokoll"};
VOID_MULTSTR(mStr_Menu_Admin)         = {"管理权限", "Admin", "Admin"};
VOID_MULTSTR(mStr_Menu_Communication) = {"通讯配置", "Comm", "Kommunikation"};
VOID_MULTSTR(mStr_Menu_Info)          = {"设备信息", "Info", "Ger?teinfo"};
VOID_MULTSTR(mStr_Menu_Energy)        = {"能量统计", "Energy", "Energie"};
VOID_MULTSTR(mStr_Menu_Date)          = {"日期时间", "Date", "Datum"};
