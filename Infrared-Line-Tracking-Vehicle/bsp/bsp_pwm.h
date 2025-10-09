#ifndef _BSP_PWM_
#define _BSP_PWM_
#include "n32g45x.h"                    // Device header

//bsp_pwm.h
//电机代号定义
#define MAIN 10
#define MBIN 11
//电机方向代号定义
#define AIN_T 0x01
#define AIN_F 0x02
#define AIN_S 0x03
#define BIN_T 0x04
#define BIN_F 0x05
#define BIN_S 0x06
//速度大小定义
#define Speed_High 600
#define Speed_Middle 450
#define Speed_Low 300
#define Speed_VeryLow 250

void pwm_init_(void);
void ChangeDirection(u8 xIN_x);
void ChangeSpeed(int xIN, int Speed);
void AdjustSpeed(int xIN,u32 speed);
u8 GetInputData(void);
void Track_Adjust(void);
void AllFunction(void);
#endif
