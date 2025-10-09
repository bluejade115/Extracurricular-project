#include "n32g45x.h"

uint32_t boot_time_ms; // ϵͳ����ʱ��
uint16_t time_uint_ms; // ��ʱ������һ���ж�ʱ��
// systick : 0~ms   99 = 0xFFFFFF / (168M / 1000)
void SysTick_Init(uint16_t time_ms)
{
	time_uint_ms = time_ms;
	// ��ʼ��ϵͳ��ʱ�����ж� ���򿪶�ʱ��
	SysTick_Config(SystemCoreClock / 1000 * time_ms);
	/**
	 * 1s���� SystemCoreClock
	 * 1ms���� SystemCoreClock / 1000
	 * 1us���� SystemCoreClock / 1000000
	 */
}

// �δ�ʱ���жϴ�����
void SysTick_Handler(void)
{
	boot_time_ms += time_uint_ms;
}
// ��ȡ��ǰʱ�������
uint32_t SYSTICK_GetTime_Ms(void)
{
	return boot_time_ms;
}
// ��ȡ��ǰʱ��΢����
uint32_t SYSTICK_GetTime_Us(void)
{
	return boot_time_ms * 1000 + SysTick->VAL / (SystemCoreClock / 1000000);
}
// �ӳ�n us
void SysTick_DelayUS(uint32_t n)
{
	uint32_t ticks;
	uint32_t told;
	uint32_t tnow;
	uint32_t tcnt = 0;
	uint32_t reload;
	reload = SysTick->LOAD;
	ticks = n * (SystemCoreClock / 1000000); /* ��Ҫ�Ľ����� */
	tcnt = 0;
	told = SysTick->VAL; /* �ս���ʱ�ļ�����ֵ */
	while (1)
	{
	    tnow = SysTick->VAL;
		if (tnow != told)
		{
		/* SYSTICK��һ���ݼ��ļ����� */
		if (tnow < told)
		{
			tcnt += told - tnow;
		}
		/* ����װ�صݼ� */
		else
		{
			tcnt += reload - tnow + told;
		}
		told = tnow;
		/* ʱ�䳬��/����Ҫ�ӳٵ�ʱ��,���˳� */
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
