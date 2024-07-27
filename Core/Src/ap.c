
#include "ap.h"
#include "usart.h"

#define DOOR_OPEN_TIME_MS 2000	// 문 열림 시간 (ms 단위)

uint8_t is_motor_working = 0;
uint8_t direction = 0;	// 0: CW, 1: CCW
extern uint8_t is_door_open;
uint8_t is_stop = 0;
// 1ms 마다 호출
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	Buzzer_Update();

	static uint16_t i;
	static uint32_t stop_time_counter = 0;


	if (is_motor_working)
	{
		if(is_stop)
		{
			if(htim == &htim10)
			{
				stop_time_counter++;
				if(stop_time_counter >= 500)
				{
					is_motor_working = 0;
					is_stop = 0;
					stop_time_counter = 0;
					i = 0;
				}
			}

		}
	else
	{
		uint8_t step;
		if(direction == DIR_CW)
		{
			step = 7 - (i % 8);
		}
		else
		{
			step = i % 8;
		}
		stepMotor(step);
		i++;
	}
	}

	else if(is_stop)
	{
		is_stop = 0;
		stop_time_counter = 0;
		i = 0;
	}


	// 엘레베이터 문 열림 조절
	if (htim == &htim10)
	{
		static uint32_t door_open_time_index = 0;
		if (is_door_open)
		{
			door_open_time_index += 1;
			if (door_open_time_index >=DOOR_OPEN_TIME_MS)
			{
				is_door_open = 0;
			}
		}
		else
		{
			door_open_time_index = 0;
		}
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
	Buzzer_Init(&htim11, TIM_CHANNEL_1);

	if (!(HAL_GPIO_ReadPin(photoint_1f_GPIO_Port, photoint_1f_Pin) || HAL_GPIO_ReadPin(photoint_2f_GPIO_Port, photoint_2f_Pin) || HAL_GPIO_ReadPin(photoint_3f_GPIO_Port, photoint_3f_Pin)))
	{
		is_motor_working = 1;
		direction = DIR_CCW;
	}



	HAL_TIM_Base_Start_IT(&htim10);


  while(1)
  {

  }

}









