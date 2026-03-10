#include "./User/power_interface.h"

PowerInfo_t PowerInfo = {

};

/*
 * @brief
 * @details     输出电压设置
 */
float IF_Power_Get_OutVolt(void)
{
    return PowerInfo.outSet.volt_set;
}
void IF_Power_Set_OutVolt(float value)
{
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
        float setVol = value;
        PowerInfo.outSet.volt_set = setVol;    
        // 5. 释放锁
    osMutexRelease(can_tx_mutex_handle);
}


/*
 * @brief
 * @details     输出电流设置
 */
float IF_Power_Get_OutCurr(void)
{
    return PowerInfo.outSet.curr_set;
}
void IF_Power_Set_OutCurr(float value)
{
    if (osMutexAcquire(can_tx_mutex_handle, 1000) != osOK) return;
        float setCurr = value;
        PowerInfo.outSet.curr_set = setCurr;
    osMutexRelease(can_tx_mutex_handle);
}

