#include "main.h"
#include <stdio.h>
#include <stdint.h>
#include "Drv_led.h"
#include "bsp_systick.h"
#include "bsp_task.h"
#include "bsp_Delay.h"

/**
 * @brief  Inserts a delay time.
 * @param count specifies the delay time length.
 */
void Delay(uint32_t count)
{
    for (; count > 0; count--)
        ;
}

void HardWare_Init(void)
{
	SystemInit();//时钟初始化
	SysTick_Init(1);//系统时钟初始化
}


/**
*/
int main(void)
{
	HardWare_Init();
	Scheduler_Setup();
	
}

/**
 * @brief Assert failed function by user.
 * @param file The name of the call that failed.
 * @param line The source line number of the call that failed.
 */
#ifdef USE_FULL_ASSERT
void assert_failed(const uint8_t* expr, const uint8_t* file, uint32_t line)
{
    while (1)
    {
    }
}
#endif // USE_FULL_ASSERT


