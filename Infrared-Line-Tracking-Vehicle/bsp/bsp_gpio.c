#include "n32g45x.h"   
#include "bsp_gpio.h"// Device header
void Config_GPIO(void){
//已在bsp_pwm.c文件中开启GPIOA、GPIOB的时钟
//IO口配置
	GPIO_InitType GPIO_InitStructure;
	GPIO_InitStructure.Pin=GPIO_PIN_AIN1;//AIN1：PA8
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitPeripheral(GPIOx_AIN1,&GPIO_InitStructure);
	
	GPIO_InitStructure.Pin=GPIO_PIN_AIN2;//AIN2：PA9
	GPIO_InitPeripheral(GPIOx_AIN2,&GPIO_InitStructure);
	
	GPIO_InitStructure.Pin=GPIO_PIN_BIN1;//BIN1：PA10
	GPIO_InitPeripheral(GPIOx_BIN1,&GPIO_InitStructure);
	
	GPIO_InitStructure.Pin=GPIO_PIN_BIN2;//BIN2：PA11
	GPIO_InitPeripheral(GPIOx_BIN2,&GPIO_InitStructure);

	GPIO_InitStructure.Pin=GPIO_PIN_PWMA;//PWMA:PB6
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_AF_PP;
	GPIO_InitPeripheral(GPIOx_PWMA,&GPIO_InitStructure);
	
	GPIO_InitStructure.Pin=GPIO_PIN_PWMB;//PWMB:PB7
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_AF_PP;
	GPIO_InitPeripheral(GPIOx_PWMB,&GPIO_InitStructure);
	//
	GPIO_InitStructure.Pin=GPIO_PIN_OUT1;// OUT1 PB11
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//上拉输入
	GPIO_InitPeripheral(GPIOx_OUT1,&GPIO_InitStructure);
	GPIO_InitStructure.Pin=GPIO_PIN_OUT2;// OUT2 PB12
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//上拉输入
	GPIO_InitPeripheral(GPIOx_OUT2,&GPIO_InitStructure);
	GPIO_InitStructure.Pin=GPIO_PIN_OUT3;// OUT3 PB13
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//上拉输入
	GPIO_InitPeripheral(GPIOx_OUT3,&GPIO_InitStructure);
	GPIO_InitStructure.Pin=GPIO_PIN_OUT4;// OUT4 PB14
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//上拉输入
	GPIO_InitPeripheral(GPIOx_OUT4,&GPIO_InitStructure);
	GPIO_InitStructure.Pin=GPIO_PIN_OUT5;// OUT5 PB15
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//上拉输入
	GPIO_InitPeripheral(GPIOx_OUT5,&GPIO_InitStructure);
	
}
void initKey(void){
	//PA4 Start PA5 Stop
	GPIO_InitType GPIO_InitStructure;
	RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOA, ENABLE);
	RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_AFIO,ENABLE);
	GPIO_InitStruct(&GPIO_InitStructure);
	GPIO_InitStructure.Pin=GPIO_PIN_4|GPIO_PIN_5;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitPeripheral(GPIOA,&GPIO_InitStructure);
	
	GPIO_ConfigEXTILine(GPIOA_PORT_SOURCE,GPIO_PIN_SOURCE4);
	GPIO_ConfigEXTILine(GPIOA_PORT_SOURCE,GPIO_PIN_SOURCE5);
	
	EXTI_InitType EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line=EXTI_LINE4;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;
	EXTI_InitPeripheral(&EXTI_InitStructure);
	EXTI_InitStructure.EXTI_Line=EXTI_LINE5;
	EXTI_InitPeripheral(&EXTI_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitType NVIC_InitSturcture;
	NVIC_InitSturcture.NVIC_IRQChannel=EXTI4_IRQn;
	NVIC_InitSturcture.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitSturcture.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitSturcture.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitSturcture);
	NVIC_InitSturcture.NVIC_IRQChannel=EXTI9_5_IRQn;
	NVIC_InitSturcture.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_Init(&NVIC_InitSturcture);
}



	
	







