#ifndef _BSP_GPIO_
#define _BSP_GPIO_
//#include "bsp_gpio.h"
//PWM模块引脚定义
//GPIOx
#define GPIOx_AIN1 GPIOA
#define GPIOx_AIN2 GPIOA
#define GPIOx_BIN1 GPIOA
#define GPIOx_BIN2 GPIOA
#define GPIOx_PWMA GPIOB
#define GPIOx_PWMB GPIOB 
//PINx
#define GPIO_PIN_AIN1 GPIO_PIN_8 
#define GPIO_PIN_AIN2 GPIO_PIN_9
#define GPIO_PIN_BIN1 GPIO_PIN_10
#define GPIO_PIN_BIN2 GPIO_PIN_11
#define GPIO_PIN_PWMA GPIO_PIN_6
#define GPIO_PIN_PWMB GPIO_PIN_7

//红外模块引脚定义
//GPIOx
#define GPIOx_OUT1 GPIOB
#define GPIOx_OUT2 GPIOB
#define GPIOx_OUT3 GPIOB
#define GPIOx_OUT4 GPIOB
#define GPIOx_OUT5 GPIOB

#define GPIOx_OUT GPIOB
//PINx
#define GPIO_PIN_OUT1 GPIO_PIN_11
#define GPIO_PIN_OUT2 GPIO_PIN_12
#define GPIO_PIN_OUT3 GPIO_PIN_13
#define GPIO_PIN_OUT4 GPIO_PIN_14
#define GPIO_PIN_OUT5 GPIO_PIN_15
//中断线配置
#define GPIO_PortSourceGPIO_OUT1 GPIO_PortSourceGPIOB
#define GPIO_PortSourceGPIO_OUT2 GPIO_PortSourceGPIOB
#define GPIO_PortSourceGPIO_OUT3 GPIO_PortSourceGPIOB
#define GPIO_PortSourceGPIO_OUT4 GPIO_PortSourceGPIOB
#define GPIO_PortSourceGPIO_OUT5 GPIO_PortSourceGPIOB
//中断引脚配置
#define GPIO_PinSource_OUT1 GPIO_PinSource11
#define GPIO_PinSource_OUT2 GPIO_PinSource12
#define GPIO_PinSource_OUT3 GPIO_PinSource13
#define GPIO_PinSource_OUT4 GPIO_PinSource14
#define GPIO_PinSource_OUT5 GPIO_PinSource15

void Config_GPIO(void);
void initKey(void);
#endif
