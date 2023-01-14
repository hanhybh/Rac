/*****************************************************************************************************
Tim3: Dùng làm hàm Delay
Tim2: Dung lam chan PWM 

*****************************************************************************************************/
#include "delay_timer.h"

extern TIM_HandleTypeDef htim3;

void delayus(uint16_t us)
{
	htim3.Instance = TIM3;
  htim3.Init.Prescaler = 71;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = us;
  HAL_TIM_Base_Init(&htim3);
  HAL_TIM_Base_Start_IT(&htim3);
	__HAL_TIM_CLEAR_FLAG(&htim3,TIM_FLAG_UPDATE);
  while(!__HAL_TIM_GET_FLAG(&htim3,TIM_FLAG_UPDATE));
}

void Delayms(uint16_t ms)
{
	for(uint16_t i = 0; i < ms; i++)
	{
		delayus(1000);
	}
}