#include "n32g45x.h"

uint32_t boot_time_ms; // 系统运行时间
uint16_t time_uint_ms; // 定时器产生一次中断时间
// systick : 0~ms   99 = 0xFFFFFF / (168M / 1000)
void SysTick_Init(uint16_t time_ms)
{
	time_uint_ms = time_ms;
	// 初始化系统定时器及中断 并打开定时器
	SysTick_Config(SystemCoreClock / 1000 * time_ms);
	/**
	 * 1s计数 SystemCoreClock
	 * 1ms计数 SystemCoreClock / 1000
	 * 1us计数 SystemCoreClock / 1000000
	 */
}

// 滴答定时器中断处理函数
void SysTick_Handler(void)
{
	boot_time_ms += time_uint_ms;
}
// 获取当前时间毫秒数
uint32_t SYSTICK_GetTime_Ms(void)
{
	return boot_time_ms;
}
// 获取当前时间微秒数
uint32_t SYSTICK_GetTime_Us(void)
{
	return boot_time_ms * 1000 + SysTick->VAL / (SystemCoreClock / 1000000);
}
// 延迟n us
void SysTick_DelayUS(uint32_t n)
{
	uint32_t ticks;
	uint32_t told;
	uint32_t tnow;
	uint32_t tcnt = 0;
	uint32_t reload;
	reload = SysTick->LOAD;
	ticks = n * (SystemCoreClock / 1000000); /* 需要的节拍数 */
	tcnt = 0;
	told = SysTick->VAL; /* 刚进入时的计数器值 */
	while (1)
	{
	    tnow = SysTick->VAL;
		if (tnow != told)
		{
		/* SYSTICK是一个递减的计数器 */
		if (tnow < told)
		{
			tcnt += told - tnow;
		}
		/* 重新装载递减 */
		else
		{
			tcnt += reload - tnow + told;
		}
		told = tnow;
		/* 时间超过/等于要延迟的时间,则退出 */
		if (tcnt >= ticks)
		{
			break;
		}
	    }
	}
}
void SysTick_DelayMS(uint32_t n)
{
	SysTick_DelayUS(n*1000);
}
