#include "stm32f4xx_hal.h"
#define R1L HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET)
#define R1H HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET)
#define R2L HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET)
#define R2H HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET)
#define R3L HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_RESET)
#define R3H HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,GPIO_PIN_SET)
#define R4L HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_RESET)
#define R4H HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,GPIO_PIN_SET)

#define C1 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)
#define C2 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5)
#define C3 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6)
#define C4 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_7)

unsigned char kb(void)
{
	unsigned char k=16;
	HAL_GPIO_WritePin(GPIOB,0xf,GPIO_PIN_SET);
		
		//--------ROW1---------------
		R1L;
		HAL_Delay(3);
		if(C1==0) {k=7;while(C1==0);}
		if(C2==0) {k=8;while(C2==0);}
		if(C3==0) {k=9;while(C3==0);}
		if(C4==0) {k=10;while(C4==0);}
		R1H;
		//--------ROW2---------------
		R2L;
		HAL_Delay(3);
		if(C1==0) {k=4;while(C1==0);}
		if(C2==0) {k=5;while(C2==0);}
		if(C3==0) {k=6;while(C3==0);}
		if(C4==0) {k=11;while(C4==0);}
		R2H;
		//--------ROW3---------------
		R3L;
		HAL_Delay(3);
		if(C1==0) {k=1;while(C1==0);}
		if(C2==0) {k=2;while(C2==0);}
		if(C3==0) {k=3;while(C3==0);}
		if(C4==0) {k=12;while(C4==0);}
		R3H;
		//--------ROW4---------------
		R4L;
		HAL_Delay(3);
		if(C1==0) {k=15;while(C1==0);}
		if(C2==0) {k=0;while(C2==0);}
		if(C3==0) {k=14;while(C3==0);}
		if(C4==0) {k=13;while(C4==0);}
		R4H;
		return k;
}
