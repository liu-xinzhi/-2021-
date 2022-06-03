#ifndef __HAL_Compare
#define __HAL_Compare
#include "tim.h"
#include "stm32f1xx_hal.h"
#include "stdio.h"

typedef struct TIM_Compare_Mode
{
	uint16_t OC_TIM_CHANNEL_DUTY;
	uint16_t OC_TIM_CHANNEL_PULSE;
	uint16_t OC_Capture_TIMx_CHn;				//传输过程的标志位
	uint16_t High_time_compare;
	uint16_t Low_time_compare;
}Compare_Output;

void Compare_Output_Init(Compare_Output *TIMxCHn,uint16_t DUTY,uint16_t PULSE);

void Compare_Output_Realize_TIM1_CH1(TIM_HandleTypeDef *htim,Compare_Output * TIMxCHn);
void Compare_Output_Realize_TIM1_CH2(TIM_HandleTypeDef *htim,Compare_Output * TIMxCHn);

void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim);

#endif

