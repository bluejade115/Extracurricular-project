#include "n32g45x.h"                    // Device header
#include "bsp_pwm.h"
#include "bsp_gpio.h"
void pwm_init_(void){
	//结构体定义
	
	TIM_TimeBaseInitType TIM_TimeBaseInitStructure;
	OCInitType OCInitStructure;
	//时钟
	RCC_EnableAPB2PeriphClk(RCC_APB2_PERIPH_GPIOA|RCC_APB2_PERIPH_GPIOB| RCC_APB2_PERIPH_AFIO, ENABLE);
	RCC_EnableAPB1PeriphClk(RCC_APB1_PERIPH_TIM4,ENABLE);//APB1 默认最大频率72Mhz
	

	TIM_ConfigInternalClk(TIM4);//选择内部时钟
	uint16_t PrescalerValue = 0;
	PrescalerValue =(uint16_t)(SystemCoreClock / 24000000) - 1;
	TIM_InitTimBaseStruct(&TIM_TimeBaseInitStructure);
	TIM_TimeBaseInitStructure.ClkDiv=TIM_CLK_DIV1;
	TIM_TimeBaseInitStructure.CntMode=TIM_CNT_MODE_UP;//向上计数
	TIM_TimeBaseInitStructure.Period=655;//655 每秒
	TIM_TimeBaseInitStructure.Prescaler=PrescalerValue;
	TIM_InitTimeBase(TIM4,&TIM_TimeBaseInitStructure);
	
	TIM_InitOcStruct(&OCInitStructure);
	OCInitStructure.OcMode=TIM_OCMODE_PWM1;//
	OCInitStructure.OcPolarity=TIM_OC_POLARITY_HIGH;
	OCInitStructure.OutputState=TIM_OUTPUT_STATE_ENABLE;
	OCInitStructure.Pulse=0;
	TIM_InitOc1(TIM4,&OCInitStructure);//通道1初始 PB6
	TIM_InitOc2(TIM4,&OCInitStructure);//通道2     PB7
	TIM_ConfigOc1Preload(TIM4,TIM_OC_PRE_LOAD_ENABLE);
	TIM_ConfigOc2Preload(TIM4,TIM_OC_PRE_LOAD_ENABLE);
	TIM_Enable(TIM4,ENABLE);
	
}
	//AIN1写1 AIN2写0，正转
	//AIN1写0 AIN2写1，反转
	//默认正转
void ChangeDirection(u8 xIN_x){
	if(xIN_x==AIN_T){//A电机正向
	GPIO_SetBits(GPIOx_AIN1,GPIO_PIN_AIN1);
	GPIO_ResetBits(GPIOx_AIN2,GPIO_PIN_AIN2);
	}
	else if(xIN_x==AIN_F){//A电机反向
	GPIO_SetBits(GPIOx_AIN2,GPIO_PIN_AIN2);
	GPIO_ResetBits(GPIOx_AIN1,GPIO_PIN_AIN1);
	}
	else if(xIN_x==AIN_S){//A电机停止
	GPIO_ResetBits(GPIOx_AIN2,GPIO_PIN_AIN2);
	GPIO_ResetBits(GPIOx_AIN1,GPIO_PIN_AIN1);
	}	
	else if(xIN_x==BIN_T){//B电机正向
	GPIO_SetBits(GPIOx_BIN1,GPIO_PIN_BIN1);
	GPIO_ResetBits(GPIOx_BIN2,GPIO_PIN_BIN2);
	}
	else if(xIN_x==AIN_F){//B电机反向
	GPIO_SetBits(GPIOx_BIN2,GPIO_PIN_BIN2);
	GPIO_ResetBits(GPIOx_BIN1,GPIO_PIN_BIN1);
	}	
	
	else if(xIN_x==BIN_S){//B电机停止
	GPIO_ResetBits(GPIOx_BIN2,GPIO_PIN_BIN2);
	GPIO_ResetBits(GPIOx_BIN1,GPIO_PIN_BIN1);
	}	
}
void ChangeSpeed(int xIN, int Speed){//废弃该函数
	if(xIN==MAIN){
		if(Speed==Speed_High){
		TIM_SetCmp1(TIM4,900);
		}
		else if(Speed==Speed_Middle){
		TIM_SetCmp1(TIM4,700);
		}
		else if(Speed==Speed_Low){
		TIM_SetCmp1(TIM4,500);
		}
	}
	else if(xIN==MBIN){
		if(Speed==Speed_High){
		TIM_SetCmp2(TIM4,900);
		}
		else if(Speed==Speed_Middle){
		TIM_SetCmp2(TIM4,700);
		}
		else if(Speed==Speed_Low){
		TIM_SetCmp2(TIM4,500);
		}
		
	}
}
//任意调速
void AdjustSpeed(int xIN,u32 speed){ //xIN标明电机
	if(xIN==MAIN){
		TIM_SetCmp1(TIM4,speed);
	}
	else if(xIN==MBIN){
		TIM_SetCmp2(TIM4,speed);
	}
}
//红外检测，黑线0，白线1
u8 GetInputData(void){//废弃该函数
	u8 State=0;
	State=(u8)(GPIO_ReadInputData(GPIOx_OUT)>>11)&0x001F;
	return State;
}
void Track_Adjust(void){
//  	u8 OUT1,OUT2,OUT3,OUT4,OUT5;
//OUT1=GPIO_ReadInputDataBit(GPIOx_OUT1,GPIO_PIN_OUT1);
//	OUT2=GPIO_ReadInputDataBit(GPIOx_OUT2,GPIO_PIN_OUT2);
//	OUT3=GPIO_ReadInputDataBit(GPIOx_OUT3,GPIO_PIN_OUT3);
//	OUT4=GPIO_ReadInputDataBit(GPIOx_OUT4,GPIO_PIN_OUT4);
//	OUT5=GPIO_ReadInputDataBit(GPIOx_OUT5,GPIO_PIN_OUT5);
//	int OUT=OUT1*10000+OUT2*1000+OUT3*100+OUT4*10+OUT5;
////黑线0，否则1
//	if(OUT==11011||OUT==10001||OUT==00000){
//		ChangeDirection(AIN_T);
//		ChangeDirection(BIN_T);
//		AdjustSpeed(MAIN,Speed_High);//快速
//		AdjustSpeed(MBIN,Speed_High);//快速
//	}
//	//小幅右转
//	else if(OUT==11101||OUT==11001){
//    ChangeDirection(BIN_T);
//					ChangeDirection(AIN_F);
//					AdjustSpeed(MBIN,Speed_Middle);//中速
//					AdjustSpeed(MAIN,Speed_Low);//慢速
//	}
//	//小幅左转
//	else if(OUT==10111||OUT==10011){
//    ChangeDirection(AIN_T);
//					ChangeDirection(BIN_F);
//					AdjustSpeed(MAIN,Speed_Middle);//中速
//					AdjustSpeed(MBIN,Speed_Low);//慢速
//	}
//	//大幅右转
//	else if(OUT==11110||OUT==11100||OUT==11000){
//		ChangeDirection(BIN_T);			
//    ChangeDirection(AIN_F);
//					AdjustSpeed(MBIN,Speed_Middle);//中速
//					AdjustSpeed(MAIN,Speed_VeryLow);//极慢速
//	}
//	//大幅左转
//	else if(OUT==01111||OUT==00111||OUT==00011){
//    ChangeDirection(AIN_T);
//					ChangeDirection(BIN_F);
//					AdjustSpeed(MAIN,Speed_Middle);//中速
//					AdjustSpeed(MBIN,Speed_VeryLow);//极慢速
//	}
//	}


	//读取输入寄存器
	u8 OUT1,OUT2,OUT3,OUT4,OUT5;
	OUT1=GPIO_ReadInputDataBit(GPIOx_OUT1,GPIO_PIN_OUT1);
	OUT2=GPIO_ReadInputDataBit(GPIOx_OUT2,GPIO_PIN_OUT2);
	OUT3=GPIO_ReadInputDataBit(GPIOx_OUT3,GPIO_PIN_OUT3);
	OUT4=GPIO_ReadInputDataBit(GPIOx_OUT4,GPIO_PIN_OUT4);
	OUT5=GPIO_ReadInputDataBit(GPIOx_OUT5,GPIO_PIN_OUT5);
	int OUT=OUT1*10000+OUT2*1000+OUT3*100+OUT4*10+OUT5;
	//正常行驶 
  if(OUT==11011||OUT==10001||OUT==10101||OUT==01110){
    ChangeDirection(AIN_T);
					ChangeDirection(BIN_T);
					AdjustSpeed(MAIN,Speed_High);//快速
					AdjustSpeed(MBIN,Speed_High);//快速
  
  
  }
  else if(OUT==11101||OUT==11001){
  
  ChangeDirection(AIN_T);
					ChangeDirection(BIN_F);
					AdjustSpeed(MAIN,Speed_Middle);//中速
					AdjustSpeed(MBIN,Speed_Low);//慢速
  
  }
  else if(OUT==11100||OUT==11110){
    ChangeDirection(AIN_T);
					ChangeDirection(BIN_F);
					AdjustSpeed(MAIN,Speed_Middle);//中速
					AdjustSpeed(MBIN,Speed_VeryLow);//极慢速
  
  }
  else if(OUT==10011||OUT==10111){
    ChangeDirection(BIN_T);ChangeDirection(AIN_F);
					AdjustSpeed(MBIN,Speed_Middle);//中速
					AdjustSpeed(MAIN,Speed_Low);//慢速
  

  }
  else if(OUT==01111||OUT==00111){
  
  ChangeDirection(BIN_T);
					ChangeDirection(AIN_F);
					AdjustSpeed(MBIN,Speed_Middle);//中速
					AdjustSpeed(MAIN,Speed_VeryLow);//极慢速
  }
}
//	if(OUT1==1&&OUT2==1&&OUT3==0&&OUT4==1&&OUT5==1){  		 //11011
//		ChangeDirection(AIN_T);
//		ChangeDirection(BIN_T);
//		AdjustSpeed(MAIN,Speed_High);//快速
//		AdjustSpeed(MBIN,Speed_High);//快速
//	}
//	else if(OUT1==1&&OUT2==0&&OUT3==0&&OUT4==0&&OUT5==1){  //10001
//				  ChangeDirection(AIN_T);
//					ChangeDirection(BIN_T);
//					AdjustSpeed(MAIN,Speed_High);//快速
//					AdjustSpeed(MBIN,Speed_High);//快速
//	}
//	else if(OUT1==1&&OUT2==0&&OUT3==1&&OUT4==0&&OUT5==1){  //10101
//				  ChangeDirection(AIN_T);
//					ChangeDirection(BIN_T);
//					AdjustSpeed(MAIN,Speed_High);//快速
//					AdjustSpeed(MBIN,Speed_High);//快速
//	}
//	else if(OUT1==0&&OUT2==1&&OUT3==1&&OUT4==1&&OUT5==0){  //01110
//				  ChangeDirection(AIN_T);
//					ChangeDirection(BIN_T);
//					AdjustSpeed(MAIN,Speed_High);//快速
//					AdjustSpeed(MBIN,Speed_High);//快速
//	}
//	
//	//小左偏
//	else if(OUT1==1&&OUT2==1&&OUT3==0&&OUT4==0&&OUT5==1){		//11001
//    ChangeDirection(AIN_T);
//					ChangeDirection(BIN_F);
//					AdjustSpeed(MAIN,Speed_Middle);//中速
//					AdjustSpeed(MBIN,Speed_Low);//慢速
//	}
//	else if(OUT1==1&&OUT2==1&&OUT3==1&&OUT4==0&&OUT5==1){		//11101
//    ChangeDirection(AIN_T);
//					ChangeDirection(BIN_F);
//					AdjustSpeed(MAIN,Speed_Middle);//中速
//					AdjustSpeed(MBIN,Speed_Low);//慢速
//	}
//	//大左偏
//	else if(OUT1==1&&OUT2==1&&OUT3==1&&OUT4==0&&OUT5==0){  //11100
//    ChangeDirection(AIN_T);
//					ChangeDirection(BIN_F);
//					AdjustSpeed(MAIN,Speed_Middle);//中速
//					AdjustSpeed(MBIN,Speed_VeryLow);//极慢速
//	}
//	else if(OUT1==1&&OUT2==1&&OUT3==1&&OUT4==1&&OUT5==0){		//11110
//    ChangeDirection(AIN_T);
//					ChangeDirection(BIN_F);
//					AdjustSpeed(MAIN,Speed_Middle);//中速
//					AdjustSpeed(MBIN,Speed_VeryLow);//极慢速
//	}
//	//小右偏
//	else if(OUT1==1&&OUT2==0&&OUT3==0&&OUT4==1&&OUT5==1){		//10011
//					
//    ChangeDirection(BIN_T);ChangeDirection(AIN_F);
//					AdjustSpeed(MBIN,Speed_Middle);//中速
//					AdjustSpeed(MAIN,Speed_Low);//慢速
//	}
//	else if(OUT1==1&&OUT2==0&&OUT3==1&&OUT4==1&&OUT5==1){		//10111
//					
//    ChangeDirection(BIN_T);ChangeDirection(AIN_F);
//					AdjustSpeed(MBIN,Speed_Middle);//中速
//					AdjustSpeed(MAIN,Speed_Low);//慢速
//	}
//	//大右偏	
//	else if(OUT1==0&&OUT2==0&&OUT3==1&&OUT4==1&&OUT5==1){  	//00111
//		ChangeDirection(BIN_T);			
//    ChangeDirection(AIN_F);
//					AdjustSpeed(MBIN,Speed_Middle);//中速
//					AdjustSpeed(MAIN,Speed_VeryLow);//极慢速
//	}

//	else if(OUT1==0&&OUT2==1&&OUT3==1&&OUT4==1&&OUT5==1){		//01111
//          ChangeDirection(BIN_T);
//					ChangeDirection(AIN_F);
//					AdjustSpeed(MBIN,Speed_Middle);//中速
//					AdjustSpeed(MAIN,Speed_VeryLow);//极慢速
//	}
//}

void AllFunction(void){
  pwm_init_();//PWM初始化
	Config_GPIO();//所有引脚的初始化
	initKey();//开关初始化
	
	
}




