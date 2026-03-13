#ifndef _CAN_MANAGER_H_
#define _CAN_MANAGER_H_
#include "./CAN/can.h"
#include "./User/power_interface.h"
#include "FDCAN.h"
#include "HomePage.h"


// 1. ID 协议联合体 (29位扩展ID解析)
typedef union {
    uint32_t id;
    struct {
        uint32_t addr         :8;  // 0-7   设备地址
        uint32_t ch_num       :8;  // 8-15  通道号
        uint32_t device_type  :3;  // 16-18 设备类型
        uint32_t mode         :3;  // 19-21 模式
        uint32_t NC1          :1;  // 22    空
        uint32_t NC2          :1;  // 23    空
        uint32_t comm_type    :4;  // 24-27 指令类型
        uint32_t dir          :1;  // 28    数据方向，0接收，1发送
        uint32_t nc           :3;  // 29-31 空
    } id_bit;
} type_can_id;

// 2. 数据载荷联合体 (8字节解析)
typedef union {
    uint32_t  u32_data[2];
    float     f32_data[2];
    uint16_t  u16_data[4];
    uint8_t   u8_data[8];
} type_can_data;

// 3. 完整消息结构体
typedef struct {
    type_can_id   can_id;
    type_can_data can_data;
} type_can_message;


/************************************************************************************************************************/
/*1 ID_ADDR 设备地址宏定义*/
typedef enum
{
    CANID_ADDRALL=   0,
    CANID_ADDR1=     1,
    CANID_ADDR2=     2,
    CANID_ADDR3=     3
}e_can_addr;
/**************************************************/
/*2 ID_CH 设备内通道宏定义*/
typedef enum
{
  CANID_CHALL=0,
  CANID_CH1  =1,
  CANID_CH2  =2,
  CANID_CH3  =3
}e_ch_num;
/**************************************************/
/*3 ID_device_type 设备类型宏定义*/
typedef enum
{
 CANID_BUCK      =1,   //BUCK
 CANID_DBUCK     =2,   //双向BUCK
 CANID_DCDC      =3,   //隔离DCDC
 CANID_BUCK_DCDC =4,   //BUCK+隔离DCDC
 CANID_DBUCK_DCDC=5,   //双向BUCK+隔离DCDC
 CANID_PFC       =6,   //
 CANID_3AC_PFC   =7   //
}e_device_type;
/**************************************************/
/*4 ID_mode 指令模式宏定义*/
typedef enum
{
 CANID_MODE      =1, //模式切换切换到其他模式
 CANID_WORK_MODE =2, //正常工作模式
 CANID_UPAPP_MODE=3, //应用程序升级模式
 CANID_ADJ_MODE  =4, //精度校准模式
 CANID_TEST_MODE =5  //测试模式
}e_code_mode;
/**************************************************/

/*5 ID_comm_type 指令类型 宏定义*/
typedef enum
{
 ORDER_NULL        =0,  //空指令（心跳）
 ORDER_CONTROL     =1,  //动作控制
 ORDER_MODE_SWITCH =2,  //模式切换指令
 ORDER_DATA_SEND   =3,  //输出电流电压数据主动输出
 ORDER_TASK_CONTROL=4,  //测试模式指令
 ORDER_DATA_SET    =5,  //参数设置
 ORDER_DATA_READ   =6,  //读取数据
 ORDER_STATE_READ  =7,  //状态读取
 ORDER_VERSION_READ=8,  //版本读取
 ORDER_ADJ_CONTROL =9  //校准指令
}e_can_order;

/*① CANID_CONTROL 动作控制*/
/* 发送指令*/
typedef enum
{
 CONTROL_OUT_STOP        =0,//BUCK停止
 CONTROL_OUT_EN          =1,//BUCK启动
 CONTROL_SET_OUTSI       =2,//buck输出电流设置*
 CONTROL_SET_OUTLI       =3,//buck输入电流设置*
 CONTROL_SET_OUTV        =4,//输出电压设置*
 CONTROL_SIGN_RESET      =5,//输出，BUCK 故障复位
 CONTROL_OUT_POWER       =6,//输出功率
 CONTROL_IN_POWER        =7,//输入功率
 CONTROL_SOURCE_R        =8,//电源内阻，
 CONTROL_SINLK_CR        =9,//负载内阻，CR模式内阻
 CONTROL_CC_CV           =10,//CC,CV优先切换，
 CONTROL_LOAD_MODE       =11,//负载模式
 CONTROL_BUCK_PWMT       =20,//BUCK PWM频率下发*
 CONTROL_BUCK_PWMC       =21,//buck PWMD下发*

 CONTROL_DC_STOP         =10,
 CONTROL_DC_EN           =11,
 CONTROL_DC_OUTI         =12, //LLC输出电流设置 预留
 CONTROL_DC_OUTV         =14, //LLC输出电压设置 预留
 CONTROL_DC_SIGN_RESET   =15, // LLC 故障复位
 CONTROL_DC_PWMF         =16, //LLC谐振频率
 CONTROL_DC_PWMD         =17, //LLC谐振脉宽设置
 CONTROL_DC_PWMPP        =18, //PWM移相角设置

 CONTROL_PFC_STOP        =20,
 CONTROL_PFC_EN          =21,
 CONTROL_PFC_OUTI        =22, //PFC输出电流设置 预留
 CONTROL_PFC_OUTV        =24, //PFC输出电压设置 预留
 CONTROL_PFC_SIGN_RESET  =25, // PFC故障复位
 CONTROL_PFC_PWMF        =26, //PFCpwm频率
 CONTROL_PFC_PWMDA       =27, //PFC A相脉宽设置
 CONTROL_PFC_PWMDB       =28, //PFC B相脉宽设置
 CONTROL_PFC_PWMDC       =29  //PFC C相脉宽设置
}e_can_control;
typedef enum
{
 /*CANID_CONTROL 回复数据*/
 ANALYSIS_ERROR          =0,//接收到 解析失败
 ANALYSIS_CORRECT        =1//接收到 解析成功
}e_can_reply;

/*⑤ CANID_DATA_SET CANID_DATA_READ 参数设置读取*/
typedef enum
{
    CDATA_ADJ_VOUT    =0,  //校准后输出电压
    CDATA_ADJ_IOUT    =1,   //输出电流
    CDATA_ADJ_DVOUT   =2,   //端口电压
    CDATA_ADJ_CVOUT   =3,   //24位电容电压
    CDATA_ROUT        =4,   //输出电压补偿值
    CDATA_RKEY        =5,   //输出开关压降
    CDATA_LODE_TEMP   =6,
    CDATA_BUCK_PATTERN=7,
    CDATA_CVOUT       =8,   //16位电容电压
    CDATA_BUCK_IL1    =9,   //电感电流1
    CDATA_BUCK_TEMP1  =10,   //功率温度1
    CDATA_BUCK_IL2    =11,
    CDATA_BUCK_TEMP2  =12,
    CDATA_BUCK_VIN    =13,   //输入电压
    CDATA_BUCK_IIN    =14,   //输入电流

    CDATA_BUCK_D_AMP     =48,   //PWM 占空比 PID参数放大后给到COT控制
    CDATA_BUCK_COT_CHT   =49,   //固定导通时间控制比较器值
    CDATA_BUCK_FMAX      =50,   //BUCK调频最大值
    CDATA_BUCK_FMIN      =51,   //BUCK调频最小值
    CDATA_OUT_V_MAX      =52,
    CDATA_OUT_I_MAX      =53,
    CDATA_OUT_I_MIN      =54,
    CDATA_OUT_I_RANGE    =55,
    CDATA_OUT_I_OFFSET   =56,
    CDATA_OUT_V_RANGE    =57,
    CDATA_OUT_V_OFFSET   =58,
    CDATA_BUCK_CV_RANGE  =59,
    CDATA_BUCK_CV_OFFSET =60,
    CDATA_BUCK_LI_RANGE  =61,
    CDATA_BUCK_LI_OFFSET =62,
    CDATA_BUCK_INV_RANGE =63,
    CDATA_BUCK_INV_OFFSET=64,
    CDATA_BUCK_INI_RANGE =65,
    CDATA_BUCK_INI_OFFSET=66,

    CDATA_IOUT_PROTER_H      =100,
    CDATA_IOUT_PROTER_L      =101,
    CDATA_VOUT_PROTER_H      =102,
    CDATA_VOUT_PROTER_L      =103,
    CDATA_ROUT_PROTER_H      =104,
    CDATA_RKEY_PROTER_H      =105,
    CDATA_LOAD_TEMP_PROTER_H =106,
    CDATA_BUCK_CVOUT_PROTER_H=107,
    CDATA_BUCK_LI_PROTER_H   =108,
    CDATA_BUCK_TEMP_PROTER_H =109,
    CDATA_BUCK_IL_EQUAL      =110,
    CDATA_BUCK_VIN_PROTER_H  =111,
    CDATA_BUCK_VIN_PROTER_L  =112,
    CDATA_BUCK_IIN_PROTER_H  =113,
    CDATA_BUCK_CV_CMPSS_H    =114,
    CDATA_BUCK_LI_CMPSS_H    =115,
    CDATA_BUCK_LI_CMPSS_L    =116,
    CDATA_BUCK_VIN_CMPSS_H   =117,
    CDATA_BUCK_VIN_CMPSS_L   =118,

    CDATA_DCDC_VOUT =150,
    CDATA_DCDC_IOUT =151,
    CDATA_DCDC_ILL1 =152,
    CDATA_DCDC_TEMP1=153,
    CDATA_DCDC_IHL1 =156,
    CDATA_DCDC_TEMP2=157,
    CDATA_DCDC_IIN  =160,
    CDATA_DCDC_VIN  =161,

    CDATA_DCDC_PWMF     =200,
    CDATA_DC_OUTV_RANGE =201,
    CDATA_DC_OUTV_OFFSET=202,
    CDATA_DC_OUTI_RANGE =203,
    CDATA_DC_OUTI_OFFSET=204,
    CDATA_DC_LLI_RANGE  =205,
    CDATA_DC_LLI_OFFSET =206,
    CDATA_DC_HLI_RANGE  =207,
    CDATA_DC_HLI_OFFSET =208,
    CDATA_DC_INI_RANGE  =209,
    CDATA_DC_INI_OFFSET =210,
    CDATA_DC_INV_RANGE  =211,
    CDATA_DC_INV_OFFSET =212,

    CDATA_DC_VOUT_PROTER_H  =250,
    CDATA_DC_VOUT_PROTER_L  =251,
    CDATA_DC_IOUT_PROTER_H  =252,
    CDATA_DC_TEMP1_PROTER_H =253,
    CDATA_DC_LLI_PROTER_H   =254,
    CDATA_DC_HLI_PROTER_H   =255,
    CDATA_DC_TEMP2_PROTER_H =256,
    CDATA_DC_VIN_PROTER_H   =257,
    CDATA_DC_VIN_PROTER_L   =258,
    CDATA_DC_IIN_PROTER_H   =259,
    CDATA_DC_LLI_CMPSS_H    =260,
    CDATA_DC_LLI_CMPSS_L    =261,
    CDATA_DC_HLI_CMPSS_H    =262,
    CDATA_DC_HLI_CMPSS_L    =263,
    CDATA_DC_VIN_CMPSS_H    =264,
    CDATA_DC_VIN_CMPSS_L    =265,

    CDATA_PFC_VA    =300,
    CDATA_PFC_IA    =301,
    CDATA_PFC_VB    =302,
    CDATA_PFC_IB    =303,
    CDATA_PFC_VC    =304,
    CDATA_PFC_IC    =305,
    CDATA_PFC_TEMP1 =306,
    CDATA_PFC_TEMP2 =307,
    CDATA_PFC_VOUT  =308,
    CDATA_PFC_IOUT  =309,

    CDATA_PFC_PWMF       =350,
    CDATA_PFC_VAC_RANGE  =351,
    CDATA_PFC_VAC_OFFSET =352,
    CDATA_PFC_IAC_RANGE  =353,
    CDATA_PFC_IAC_OFFSET =354,
    CDATA_PFC_VOUT_RANGE =355,
    CDATA_PFC_VOUT_OFFSET=356,
    CDATA_PFC_IOUT_RANGE =357,
    CDATA_PFC_IOUT_OFFSET=358,

    CDATA_PFC_VIN_PROTER_H  =400,
    CDATA_PFC_VIN_PROTER_L  =401,
    CDATA_PFC_IIN_PROTER_H  =402,
    CDATA_PFC_TEMP_PROTER_H =403,
    CDATA_PFC_VOUT_PROTER_H =404,
    CDATA_PFC_VOUT_PROTER_L =405,
    CDATA_PFC_IOUT_PROTER_H =406,

    CDATA_SYS_ADDR                  =450,
    CDATA_SYS_DEVICE_TYPE           =451,
    CDATA_SYS_TASK_MODE             =452,
    CDATA_SYS_OUT_KEY               =453,
    CDATA_SYS_BUCK_MODULE_NUM       =454,
    CDATA_SYS_BUCK_MODULE_UNION_TYPE=455,
    CDATA_SYS_DSP_UNION_TYPE        =456,
    CDATA_SYS_BUCK_CH_NUM           =457,
    CDATA_SYS_DSP_MASTER            =458,
    CDATA_SYS_CODE_VERSION          =459,

    CDATA_TEMP_PROTER_L  =500,
    CDATA_SYS_TEMP       =501,
    CDATA_SYS_FAN        =502,
    CDATA_SYS_TEMP_HT    =503,
    CDATA_SYS_LTEMP_FAN  =504,

    CDATA_OUT_VUP_SLOPE  =520,
    CDATA_OUT_VDOWN_SLOPE=521,
    CDATA_OUT_IUP_SLOPE  =522,
    CDATA_OUT_IDOWN_SLOPE=523,
    CDATA_OUT_PUP_SLOPE  =524,
    CDATA_OUT_PDOWN_SLOPE=525,
    CDATA_OUT_V_COM_EN   =526,

    CDATA_BUCK_PID_INT_V_P      =600,
    CDATA_BUCK_PID_INT_V_I      =601,
    CDATA_BUCK_PID_INT_V_D      =602,
    CDATA_BUCK_PID_INT_V_OUT_MAX=603,

    CDATA_BUCK_PID_INT_I_P      =604,
    CDATA_BUCK_PID_INT_I_I      =605,
    CDATA_BUCK_PID_INT_I_D      =606,
    CDATA_BUCK_PID_INT_I_OUT_MAX=607,

    CDATA_BUCK_PFM_PWMD         =610,

    CDATA_BUCK_UNION_PID_I_P      =680,
    CDATA_BUCK_UNION_PID_I_I      =681,
    CDATA_BUCK_UNION_PID_I_D      =682,
    CDATA_BUCK_UNION_PID_I_OUT_MAX=683,

    CDATA_DSP_UNION_PID_I_P      =690,
    CDATA_DSP_UNION_PID_I_I      =691,
    CDATA_DSP_UNION_PID_I_D      =692,
    CDATA_DSP_UNION_PID_I_OUT_MAX=693,

    CDATA_SAVE_SET_DATA=699,

    CDATA_ADJ_I_READ_DATA_1=700,
    CDATA_ADJ_I_READ_K_1   =701,
    CDATA_ADJ_I_READ_B_1   =702,
    CDATA_ADJ_I_READ_DATA_2=703,
    CDATA_ADJ_I_READ_K_2   =704,
    CDATA_ADJ_I_READ_B_2   =705,
    CDATA_ADJ_I_READ_DATA_3=706,
    CDATA_ADJ_I_READ_K_3   =707,
    CDATA_ADJ_I_READ_B_3   =708,
    CDATA_ADJ_I_READ_DATA_4=709,
    CDATA_ADJ_I_READ_K_4   =710,
    CDATA_ADJ_I_READ_B_4   =711,
    CDATA_ADJ_I_READ_DATA_5=712,
    CDATA_ADJ_I_READ_K_5   =713,
    CDATA_ADJ_I_READ_B_5   =714,
    CDATA_ADJ_I_READ_DATA_6=715,
    CDATA_ADJ_I_READ_K_6   =716,
    CDATA_ADJ_I_READ_B_6   =717,
    CDATA_ADJ_I_READ_DATA_7=718,
    CDATA_ADJ_I_READ_K_7   =719,
    CDATA_ADJ_I_READ_B_7   =720,
    CDATA_ADJ_I_READ_DATA_8=721,
    CDATA_ADJ_I_READ_K_8   =722,
    CDATA_ADJ_I_READ_B_8   =723,

    CDATA_ADJ_I_SET_DATA_1=750,
    CDATA_ADJ_I_SET_K_1   =751,
    CDATA_ADJ_I_SET_B_1   =752,
    CDATA_ADJ_I_SET_DATA_2=753,
    CDATA_ADJ_I_SET_K_2   =754,
    CDATA_ADJ_I_SET_B_2   =755,
    CDATA_ADJ_I_SET_DATA_3=756,
    CDATA_ADJ_I_SET_K_3   =757,
    CDATA_ADJ_I_SET_B_3   =758,
    CDATA_ADJ_I_SET_DATA_4=759,
    CDATA_ADJ_I_SET_K_4   =760,
    CDATA_ADJ_I_SET_B_4   =761,
    CDATA_ADJ_I_SET_DATA_5=762,
    CDATA_ADJ_I_SET_K_5   =763,
    CDATA_ADJ_I_SET_B_5   =764,
    CDATA_ADJ_I_SET_DATA_6=765,
    CDATA_ADJ_I_SET_K_6   =766,
    CDATA_ADJ_I_SET_B_6   =767,
    CDATA_ADJ_I_SET_DATA_7=768,
    CDATA_ADJ_I_SET_K_7   =769,
    CDATA_ADJ_I_SET_B_7   =770,
    CDATA_ADJ_I_SET_DATA_8=771,
    CDATA_ADJ_I_SET_K_8   =772,
    CDATA_ADJ_I_SET_B_8   =773,

    CDATA_ADJ_CV_READ_DATA_1=800,
    CDATA_ADJ_CV_READ_K_1   =801,
    CDATA_ADJ_CV_READ_B_1   =802,
    CDATA_ADJ_CV_READ_DATA_2=803,
    CDATA_ADJ_CV_READ_K_2   =804,
    CDATA_ADJ_CV_READ_B_2   =805,
    CDATA_ADJ_CV_READ_DATA_3=806,
    CDATA_ADJ_CV_READ_K_3   =807,
    CDATA_ADJ_CV_READ_B_3   =808,
    CDATA_ADJ_CV_READ_DATA_4=809,
    CDATA_ADJ_CV_READ_K_4   =810,
    CDATA_ADJ_CV_READ_B_4   =811,
    CDATA_ADJ_CV_READ_DATA_5=812,
    CDATA_ADJ_CV_READ_K_5   =813,
    CDATA_ADJ_CV_READ_B_5   =814,
    CDATA_ADJ_CV_READ_DATA_6=815,
    CDATA_ADJ_CV_READ_K_6   =816,
    CDATA_ADJ_CV_READ_B_6   =817,
    CDATA_ADJ_CV_READ_DATA_7=818,
    CDATA_ADJ_CV_READ_K_7   =819,
    CDATA_ADJ_CV_READ_B_7   =820,
    CDATA_ADJ_CV_READ_DATA_8=821,
    CDATA_ADJ_CV_READ_K_8   =822,
    CDATA_ADJ_CV_READ_B_8   =823,

    CDATA_ADJ_CV_SET_DATA_1=850,
    CDATA_ADJ_CV_SET_K_1   =851,
    CDATA_ADJ_CV_SET_B_1   =852,
    CDATA_ADJ_CV_SET_DATA_2=853,
    CDATA_ADJ_CV_SET_K_2   =854,
    CDATA_ADJ_CV_SET_B_2   =855,
    CDATA_ADJ_CV_SET_DATA_3=856,
    CDATA_ADJ_CV_SET_K_3   =857,
    CDATA_ADJ_CV_SET_B_3   =858,
    CDATA_ADJ_CV_SET_DATA_4=859,
    CDATA_ADJ_CV_SET_K_4   =860,
    CDATA_ADJ_CV_SET_B_4   =861,
    CDATA_ADJ_CV_SET_DATA_5=862,
    CDATA_ADJ_CV_SET_K_5   =863,
    CDATA_ADJ_CV_SET_B_5   =864,
    CDATA_ADJ_CV_SET_DATA_6=865,
    CDATA_ADJ_CV_SET_K_6   =866,
    CDATA_ADJ_CV_SET_B_6   =867,
    CDATA_ADJ_CV_SET_DATA_7=868,
    CDATA_ADJ_CV_SET_K_7   =869,
    CDATA_ADJ_CV_SET_B_7   =870,
    CDATA_ADJ_CV_SET_DATA_8=871,
    CDATA_ADJ_CV_SET_K_8   =872,
    CDATA_ADJ_CV_SET_B_8   =873,

    CDATA_ADJ_DV_READ_DATA_1=900,
    CDATA_ADJ_DV_READ_K_1   =901,
    CDATA_ADJ_DV_READ_B_1   =902,
    CDATA_ADJ_DV_READ_DATA_2=903,
    CDATA_ADJ_DV_READ_K_2   =904,
    CDATA_ADJ_DV_READ_B_2   =905,
    CDATA_ADJ_DV_READ_DATA_3=906,
    CDATA_ADJ_DV_READ_K_3   =907,
    CDATA_ADJ_DV_READ_B_3   =908,
    CDATA_ADJ_DV_READ_DATA_4=909,
    CDATA_ADJ_DV_READ_K_4   =910,
    CDATA_ADJ_DV_READ_B_4   =911,
    CDATA_ADJ_DV_READ_DATA_5=912,
    CDATA_ADJ_DV_READ_K_5   =913,
    CDATA_ADJ_DV_READ_B_5   =914,
    CDATA_ADJ_DV_READ_DATA_6=915,
    CDATA_ADJ_DV_READ_K_6   =916,
    CDATA_ADJ_DV_READ_B_6   =917,
    CDATA_ADJ_DV_READ_DATA_7=918,
    CDATA_ADJ_DV_READ_K_7   =919,
    CDATA_ADJ_DV_READ_B_7   =920,
    CDATA_ADJ_DV_READ_DATA_8=921,
    CDATA_ADJ_DV_READ_K_8   =922,
    CDATA_ADJ_DV_READ_B_8   =923,

    CDATA_ADJ_V_READ_DATA_1=950,
    CDATA_ADJ_V_READ_K_1   =951,
    CDATA_ADJ_V_READ_B_1   =952,
    CDATA_ADJ_V_READ_DATA_2=953,
    CDATA_ADJ_V_READ_K_2   =954,
    CDATA_ADJ_V_READ_B_2   =955,
    CDATA_ADJ_V_READ_DATA_3=956,
    CDATA_ADJ_V_READ_K_3   =957,
    CDATA_ADJ_V_READ_B_3   =958,
    CDATA_ADJ_V_READ_DATA_4=959,
    CDATA_ADJ_V_READ_K_4   =960,
    CDATA_ADJ_V_READ_B_4   =961,
    CDATA_ADJ_V_READ_DATA_5=962,
    CDATA_ADJ_V_READ_K_5   =963,
    CDATA_ADJ_V_READ_B_5   =964,
    CDATA_ADJ_V_READ_DATA_6=965,
    CDATA_ADJ_V_READ_K_6   =966,
    CDATA_ADJ_V_READ_B_6   =967,
    CDATA_ADJ_V_READ_DATA_7=968,
    CDATA_ADJ_V_READ_K_7   =969,
    CDATA_ADJ_V_READ_B_7   =970,
    CDATA_ADJ_V_READ_DATA_8=971,
    CDATA_ADJ_V_READ_K_8   =972,
    CDATA_ADJ_V_READ_B_8   =973
}e_can_data;
/*⑨ CANID_ADJ_CONTROL 校准指令*/
typedef enum
{
    CADJ_INPUT_DATA=1,
    CADJ_SAVE_KB   =2,
    CADJ_TYPE_SET  =3,
    CADJ_CLEAR_DATA=4,
    CADJ_CLEAR_KB  =5
}e_adj_order;
/**************************************************/

//6 ID_IDR 方向宏定义
typedef enum
{
    CANID_DIR_TX=1,    //DSP发送出去数据
    CANID_DIR_RX=0    //发送给DSP数据
}e_can_dir;


void CAN_Task_App_Start(void); // 导出启动接口
void CAN_Msg_Process_Task(void *argument);


#endif /* _CAN_MANAGER_H_ */
