
#include "ap.h"
#include "usart.h"



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	static uint16_t i;
	if (is_motor_working)
	{
		while (is_motor_working)
		{
			// 회전 방향에 맞춰서 스텝 패턴 설정
			uint8_t step;
			if(direction == DIR_CW)
			{
				step = 7 - (i % 8);		// 시계
			}
			else
			{
				step = i % 8;			// 반시계
			}
			stepMotor(step);
			i++;
		}
	}
	else
	{
		i = 0;
	}

}

void apInit()
{
  hwInit();
}


extern uint8_t rxData;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == photoint_3f_Pin)
	{

	}
}
void apMain()
{

  while(1)
  {

  }
}








