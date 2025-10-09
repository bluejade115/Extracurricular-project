#include "n32g45x.h"
#include "stdio.h"
#include <stdint.h>
#include "Drv_led.h"


void LED_Init(void)
{
	GPIO_InitType GPIO_InitStructure;
	//使能LED的GPIO时钟
	RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOB, ENABLE);
	RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOA, ENABLE);
	GPIO_InitStruct(&GPIO_InitStructure);
	
	GPIO_ConfigPinRemap(GPIO_RMP_SW_JTAG_NO_NJTRST,ENABLE);
	
	GPIO_InitStructure.Pin=GPIO_PIN_5;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitPeripheral(GPIOB,&GPIO_InitStructure);
	
	GPIO_InitStructure.Pin=GPIO_PIN_4;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitPeripheral(GPIOB,&GPIO_InitStructure);
	
	GPIO_InitStructure.Pin=GPIO_PIN_8;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitPeripheral(GPIOA,&GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB,GPIO_PIN_4);
	GPIO_SetBits(GPIOB,GPIO_PIN_5);
	GPIO_SetBits(GPIOA,GPIO_PIN_8);	
	
}

void Drv_LED_ON(LEDx x)
{
	if(x==LED_1)
	{
		GPIO_SetBits(GPIOB,GPIO_PIN_4);
	}
	
	if(x==LED_2)
	{
		GPIO_SetBits(GPIOB,GPIO_PIN_5);
	}
	
	if(x==LED_3)
	{
		GPIO_SetBits(GPIOA,GPIO_PIN_8);
	}
}

void Drv_LED_OFF(LEDx x)
{
	if(x==LED_1)
	{
		GPIO_ResetBits(GPIOB,GPIO_PIN_4);
	}
	
	if(x==LED_2)
	{
		GPIO_ResetBits(GPIOB,GPIO_PIN_5);
	}
	
	if(x==LED_3)
	{
		GPIO_ResetBits(GPIOA,GPIO_PIN_8);
	}
}

void Drv_LED_Toggle(LEDx x)
{
	if(x==LED_1)
	{
		if(GPIO_ReadOutputDataBit(GPIOB,GPIO_PIN_4))
		{
			GPIO_ResetBits(GPIOB,GPIO_PIN_4);
		}
		else
		{
			GPIO_SetBits(GPIOB,GPIO_PIN_4);
		}
	}
	
	if(x==LED_2)
	{
		if(GPIO_ReadOutputDataBit(GPIOB,GPIO_PIN_5))
		{
			GPIO_ResetBits(GPIOB,GPIO_PIN_5);
		}
		else
		{
			GPIO_SetBits(GPIOB,GPIO_PIN_5);
		}		
	}
	
	if(x==LED_3)
	{
		if(GPIO_ReadOutputDataBit(GPIOB,GPIO_PIN_8))
		{
			GPIO_ResetBits(GPIOA,GPIO_PIN_8);
		}
		else
		{
			GPIO_SetBits(GPIOA,GPIO_PIN_8);
		}
	}
	
	
}
