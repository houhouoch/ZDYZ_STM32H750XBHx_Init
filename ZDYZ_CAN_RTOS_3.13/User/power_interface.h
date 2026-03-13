#ifndef POWER_INTERFACE_H
#define POWER_INTERFACE_H
#include "./CAN/can.h"

typedef struct {

    //输出设置
    double volt_set;
    double curr_set;
    double curr_set_neg;
    double ResIn_set;
    uint8_t onoff;
    //保护设置
    double ovp_set;
    double ocp_set;
    uint8_t ovp_onoff;
    uint8_t ocp_onoff;
    //电源斜率
    uint8_t SlewRate_Mode;
    float VSR_Up;
    float VSR_Down;
    float ISR_Up;
    float ISR_Down;

    uint8_t powerMode;      //电源模式
    uint8_t ac_down;        //掉电检测
    uint8_t power_on;       //上电输出
    uint8_t eLoad;          //泄放负载

    #if 1

    int16_t updateRate;     //回读速度

    int16_t ovp_delayTime;
    int16_t ocp_delayTime;
    int16_t otp_Temperature;
    int16_t on_delayTime;    //延时启动
    int16_t off_delayTime;   //延时关闭
    #endif



    uint8_t lock;
    uint8_t userGroup;          //用户组
    uint8_t slave_ID;           //从机通讯ID(用于外部并机)
    uint8_t brightness;         //亮度
    uint8_t language;           //系统语言
    uint8_t beeper_en;          //蜂鸣器
    uint8_t remoteLock;         //自动上锁
    uint8_t dhcp_en;            //DHCP
    uint8_t ip[4 + 1];          //IP
    uint8_t gatewate[4 + 1];    //网关地址
    uint8_t netmask[4 + 1];     //子网掩码
    uint8_t mac[6 + 1];         //MAC地址
    uint16_t scpiPort;          //Socket SCPI端口号
    //测试
    float senseVolt;            //远端补偿电压
    int8_t maxFan;              //最大风扇占空比(Debug)
    int8_t zeroCurrent_autoEn;  //开机自动清零
    //    int8_t debugEn;             //Debug日志
    //
    uint32_t localCookieID;

    char multCH_ModelName[64];
    uint8_t canGroup;
    uint16_t reserve;     //保留
    uint16_t crc;
} OutSet_Def;



typedef struct {
    OutSet_Def outSet;
    uint8_t workMode;
    struct {
        uint8_t powerID;
        uint8_t powerChannels;

        uint8_t canUpdata_event;
        uint8_t syncRequest;
        uint8_t setchannged;    //用于保存
        uint8_t groupChannged;  //组参数保存
        uint8_t webchannged;    //网页密码保存
        uint8_t netApply;       //网络设置保存

        uint64_t runTime_ms;
        //输出AD采集
        double volt_adc;
        double curr_sum_adc;
        double curr_front_adc;  //前面板输出电流
        //实际输出
        double volt_read;
        double volt_drv_read;
        double curr_read;
        double power_read;
        #if 0
        //滤波后
        double volt_read;
        double curr_read;
        double power_read;
        #endif



        double volt_read_total;
        double curr_read_total;
        double power_read_total;
        //校准状态
        uint8_t voltCalib_state;
        uint8_t currCalib_state;
        //
        uint8_t powerCount;
        uint8_t powerType;
        //
        uint8_t voltCalib_Count;
        uint8_t voltDrvCalib_Count;
        uint8_t currCalib_Count;
        //
        float voltage_step;
        float current_step;
        //
        uint8_t dhcp_en;            //DHCP
        uint8_t ip[4 + 1];          //IP
        uint8_t gatewate[4 + 1];    //网关地址
        uint8_t netmask[4 + 1];     //子网掩码

        uint32_t cookieID;
    } Read;

    struct {
        int16_t temp_ext_1;     //模组1温度
        int16_t temp_ext_2;     //模组2温度
        int16_t temp_ext_3;     //模组3温度
        int16_t temp_ext_4;     //模组4温度
        int16_t temp_ext_5;     //模组5温度
        int16_t temp_pcb;       //PCB温度
    } Temperature;

    union {
        uint64_t byte;
        struct {
            uint8_t Power_Link: 1;
            uint8_t Sample_Ready: 1;
            uint8_t CAN: 1;
            uint8_t USB_Host: 1;
            uint8_t USB_Device: 1;
            uint8_t LAN_Linked: 1;
            uint8_t LOCK: 1;
            uint8_t Remote: 1;
            uint8_t Web: 1;
            uint8_t Socket: 1;
            uint8_t USB: 1;
            uint8_t LAN_10M: 1;
            uint8_t LAN_100M: 1;
            uint8_t LAN_Tx: 1;
            uint8_t LAN_Rx: 1;
            uint8_t SDRAM: 1;
            uint8_t LAN_DP83848: 1;
            uint8_t LAN_LAN8720: 1;
            uint8_t zeroCurr: 1;

            uint8_t eeprom_setting_lost: 1;
            uint8_t network_init_failed: 1;
            uint8_t flash_init_failed: 1;

        } bits;
    } StateBar;


} PowerInfo_t;

extern PowerInfo_t PowerInfo;



// 函数接口
float IF_Power_Get_OutVolt(void);
void  IF_Power_Set_OutVolt(float value);

float IF_Power_Get_OutCurr(void);
void  IF_Power_Set_OutCurr(float value);

#endif
