//#include "Compare_Output.h"

//Compare_Output TIM1_CH1;
//Compare_Output TIM1_CH2;

//void Compare_Output_Init(Compare_Output *TIMxCHn,uint16_t DUTY,uint16_t PULSE)
//{
//	TIMxCHn ->OC_Capture_TIMx_CHn = 0;
//	TIMxCHn ->OC_TIM_CHANNEL_DUTY = DUTY;
//	TIMxCHn ->OC_TIM_CHANNEL_PULSE = PULSE;
//	TIMxCHn ->High_time_compare = 0;
//	TIMxCHn ->Low_time_compare = 0;
//}
//	
////定时器1通道1
//void Compare_Output_Realize_TIM1_CH1(TIM_HandleTypeDef *htim,Compare_Output * TIMxCHn)
//{
//		TIMxCHn -> OC_Capture_TIMx_CHn = __HAL_TIM_GetCompare(htim,TIM_CHANNEL_1);
//		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_8) == GPIO_PIN_RESET)//更改
//		{
//			TIMxCHn ->High_time_compare = TIMxCHn->OC_Capture_TIMx_CHn + TIMxCHn->OC_TIM_CHANNEL_PULSE - TIMxCHn->OC_TIM_CHANNEL_DUTY * TIMxCHn->OC_TIM_CHANNEL_PULSE / (float)100;
//			__HAL_TIM_SET_COMPARE(htim,TIM_CHANNEL_1,  TIMxCHn->High_time_compare);	//下降沿，输出低电
////			printf("The high time value is : %d\r\n",TIMxCHn->High_time_compare);
////			__HAL_TIM_SET_COMPARE(htim,TIM_CHANNEL_1,  TIMxCHn -> OC_Capture_TIMx_CHn + 5000 - 30 * 5000 / (float)100);	//下降沿，输出低电
////			HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
//		}
//		else
//		{
//			TIMxCHn ->Low_time_compare = TIMxCHn -> OC_Capture_TIMx_CHn + TIMxCHn->OC_TIM_CHANNEL_DUTY * TIMxCHn->OC_TIM_CHANNEL_PULSE /(float)100;
//			__HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_1, TIMxCHn ->Low_time_compare);	//上升沿，输出高电
////			printf("The low compare value is : %d\r\n",TIMxCHn->Low_time_compare);
////			printf("*************\r\n");
////			HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
//		}
//}

////定时器1通道2
//void Compare_Output_Realize_TIM1_CH2(TIM_HandleTypeDef *htim,Compare_Output * TIMxCHn)
//{
//		TIMxCHn -> OC_Capture_TIMx_CHn = __HAL_TIM_GetCompare(htim,TIM_CHANNEL_2);
//		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9) == GPIO_PIN_RESET)//更改
//		{
//			TIMxCHn->High_time_compare = TIMxCHn -> OC_Capture_TIMx_CHn + TIMxCHn->OC_TIM_CHANNEL_PULSE - TIMxCHn->OC_TIM_CHANNEL_DUTY * TIMxCHn->OC_TIM_CHANNEL_PULSE / (float)100;
//			__HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_2, TIMxCHn->High_time_compare);	//下降沿，输出低电
//		}
//		else
//		{
//			TIMxCHn->Low_time_compare = TIMxCHn -> OC_Capture_TIMx_CHn + TIMxCHn -> OC_TIM_CHANNEL_DUTY * TIMxCHn->OC_TIM_CHANNEL_PULSE / (float)100;
//			__HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_2, TIMxCHn->Low_time_compare );	//上升沿，输出高电
//		}
//}
//	
//void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
//{
//	if(htim == &htim1)
//	{
//		TIM1_CH1.OC_Capture_TIMx_CHn = 0;
//		TIM1_CH2.OC_Capture_TIMx_CHn = 0;
//		if(htim ->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
//		{
////			__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,500);
//			Compare_Output_Realize_TIM1_CH1(&htim1,&TIM1_CH1);
////			HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
//		}
//		else if(htim ->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
//		{
//			Compare_Output_Realize_TIM1_CH2(&htim1,&TIM1_CH2);
////			HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
//		}
//	}
//}

#include "Compare_Output.h"

Compare_Output TIM1_CH1;
Compare_Output TIM1_CH2;

void Compare_Output_Init(Compare_Output *TIMxCHn,uint16_t DUTY,uint16_t PULSE)
{
	TIMxCHn ->OC_Capture_TIMx_CHn = 0;
	TIMxCHn ->OC_TIM_CHANNEL_DUTY = DUTY;
	TIMxCHn ->OC_TIM_CHANNEL_PULSE = PULSE;
	TIMxCHn ->High_time_compare = 0;
	TIMxCHn ->Low_time_compare = 0;
//	HAL_TIM_OC_Start_IT(&htim1,TIM_CHANNEL_2);
}
	
//定时器1通道1
void Compare_Output_Realize_TIM1_CH1(TIM_HandleTypeDef *htim,Compare_Output * TIMxCHn)
{
		TIMxCHn -> OC_Capture_TIMx_CHn = __HAL_TIM_GetCompare(htim,TIM_CHANNEL_1);
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_8) == GPIO_PIN_RESET)																													//更改
		{
			TIMxCHn -> High_time_compare = TIMxCHn->OC_Capture_TIMx_CHn + TIMxCHn->OC_TIM_CHANNEL_PULSE - TIMxCHn->OC_TIM_CHANNEL_DUTY * TIMxCHn->OC_TIM_CHANNEL_PULSE / (float)100;
			__HAL_TIM_SET_COMPARE(htim,TIM_CHANNEL_1,  TIMxCHn->High_time_compare);																					//下降沿，输出低电
//			printf("The high time value is : %d\r\n",TIMxCHn->High_time_compare);
//			__HAL_TIM_SET_COMPARE(htim,TIM_CHANNEL_1,  TIMxCHn -> OC_Capture_TIMx_CHn + 5000 - 30 * 5000 / (float)100);		//下降沿，输出低电
//			HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
		}
		else
		{
			TIMxCHn -> Low_time_compare = TIMxCHn -> OC_Capture_TIMx_CHn + TIMxCHn -> OC_TIM_CHANNEL_DUTY * TIMxCHn -> OC_TIM_CHANNEL_PULSE /(float)100;
			__HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_1, TIMxCHn ->Low_time_compare);	//上升沿，输出高电
//			printf("The low compare value is : %d\r\n",TIMxCHn->Low_time_compare);
//			printf("*************\r\n");
//			HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
		}
}

//定时器1通道2
void Compare_Output_Realize_TIM1_CH2(TIM_HandleTypeDef *htim,Compare_Output * TIMxCHn)
{
		TIMxCHn -> OC_Capture_TIMx_CHn = __HAL_TIM_GetCompare(htim,TIM_CHANNEL_2);
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_9) == GPIO_PIN_RESET)//更改
		{
			TIMxCHn->High_time_compare = TIMxCHn -> OC_Capture_TIMx_CHn + TIMxCHn->OC_TIM_CHANNEL_PULSE - TIMxCHn->OC_TIM_CHANNEL_DUTY * TIMxCHn->OC_TIM_CHANNEL_PULSE / (float)100;
//			TIMxCHn->High_time_compare = 5000 - 5000 * 30 / (float)100;
			__HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_2, TIMxCHn->High_time_compare);	//下降沿，输出低电
		}
		else
		{
			TIMxCHn->Low_time_compare = TIMxCHn -> OC_Capture_TIMx_CHn + TIMxCHn -> OC_TIM_CHANNEL_DUTY * TIMxCHn->OC_TIM_CHANNEL_PULSE / (float)100;
//			TIMxCHn->Low_time_compare = 5000 * 30  / (float) 100;
			__HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_2, TIMxCHn->Low_time_compare );	//上升沿，输出高电
		}
}
	
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim == &htim1)
	{
		TIM1_CH1.OC_Capture_TIMx_CHn = 0;
		TIM1_CH2.OC_Capture_TIMx_CHn = 0;
		if(htim ->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
		{
//			__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,500);
			Compare_Output_Realize_TIM1_CH1(&htim1,&TIM1_CH1);
//			HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
		}
		else if(htim ->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
		{
			Compare_Output_Realize_TIM1_CH2(&htim1,&TIM1_CH2);
//			HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
		}
	}
}

