#ifndef _DRV_LED_H_
#define _DRV_LED_H_

typedef enum
{
	LED_1,
	LED_2,
	LED_3,
}LEDx;

void LED_Init(void);
void Drv_LED_ON(LEDx x);
void Drv_LED_OFF(LEDx x);
void Drv_LED_Toggle(LEDx x);

#endif
