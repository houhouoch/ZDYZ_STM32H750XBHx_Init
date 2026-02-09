#ifndef __CAN_H_
#define __CAN_H_

#include "main.h"


extern void DevBoard_Set_Host_Voltage(float voltage) ;


extern void DevBoard_Set_Host_Output(uint8_t state);

extern void DevBoard_Set_Host_Output_test(uint8_t state);
extern void DevBoard_Set_Host_Current(float current);
#endif 
