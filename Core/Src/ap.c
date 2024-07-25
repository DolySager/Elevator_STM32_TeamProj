
#include "ap.h"
#include "usart.h"


uint8_t is_motor_working = 0;
uint8_t direction = 0;	// 0: CW, 1: CCW
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	static uint16_t i;
	if (is_motor_working)
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

//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{
//	if(GPIO_Pin == button_2f_Pin)
//	{
//		direction = DIR_CCW;
//		is_motor_working = 1;
//	}
//	else if(GPIO_Pin == button_1f_Pin)
//	{
//		direction = DIR_CW;
//		is_motor_working = 1;
//	}
//	else if(GPIO_Pin == photoint_1f_Pin || GPIO_Pin == photoint_2f_Pin || GPIO_Pin == photoint_3f_Pin )
//	{
//		is_motor_working = 0;
//	}
//}
void apMain()
{


	direction = DIR_CCW;  // 하강시
	is_motor_working = 1; // 시작시
	// 포토 인터럽트 검출 시
	if(HAL_GPIO_ReadPin(photoint_1f_GPIO_Port, photoint_1f_Pin)|| HAL_GPIO_ReadPin(photoint_2f_GPIO_Port, photoint_2f_Pin) || HAL_GPIO_ReadPin(photoint_3f_GPIO_Port, photoint_3f_Pin))
		{
			is_motor_working = 0;		// 모터 정지
			updateCurrentFloor();			// 현재 층수 파악 후 case문 1 or 2 or 3  시작
		}


	HAL_TIM_Base_Start_IT(&htim10);

  while(1)
  {

  }

}









