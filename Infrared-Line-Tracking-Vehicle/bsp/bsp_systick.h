#ifndef _BSP_SYSYTICK_H_
#define _BSP_SYSYTICK_H_

#define TICK_PER_SECOND	1000
#define TICK_US	(1000000/TICK_PER_SECOND)

#include "n32g45x.h"


void SysTick_Init(uint16_t time_ms);
void SysTick_Handler(void);
uint32_t SYSTICK_GetTime_Ms(void);
uint32_t SYSTICK_GetTime_Us(void);
void SysTick_DelayUS(uint32_t n);
void SysTick_DelayMS(uint32_t n);
 



#endif
