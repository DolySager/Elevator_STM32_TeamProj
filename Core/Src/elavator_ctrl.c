#include "elavator_ctrl.h"
#include "stepper.h"


int currentfloor;

extern uint8_t is_motor_working;
extern uint8_t direction;	// DIR_CW(high), DIR_CCW (low)


void updateCurrentFloor() {
    if (!HAL_GPIO_ReadPin(photoint_1f_GPIO_Port, photoint_1f_Pin)) {
        currentfloor = 1; // 현재 1층
    } else if (!HAL_GPIO_ReadPin(photoint_2f_GPIO_Port, photoint_2f_Pin)) {
        currentfloor = 2; // 현재 2층
    } else if (!HAL_GPIO_ReadPin(photoint_3f_GPIO_Port, photoint_3f_Pin)) {
        currentfloor = 3; // 현재 3층
    }
}




void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{


	switch (currentfloor)
	{
	case 1:

		// 1번 버튼 (이미 1층이니 동작x)
		if(GPIO_Pin == button_1f_Pin)
		    {
				is_motor_working = 0;		// 모터 정지 및 알림
				updateCurrentFloor();			// 현재 층수 파악
		    }

		// 2번 버튼
		else if(GPIO_Pin == button_2f_Pin)
		    {
				direction = DIR_CW;	// 1 -> 2 상승
				is_motor_working = 1;

			// 상승 중 포토인터럽트 2번 검출 시
			if (GPIO_Pin == photoint_2f_Pin)
					{
						is_motor_working = 0;		// 모터 정지
						updateCurrentFloor();			// 현재 층수 파악
					}
		    }

		// 3번 버튼
		else if(GPIO_Pin == button_3f_Pin)
		    {
				direction = DIR_CW;	// 1 -> 3 상승
				is_motor_working = 1;

			// 상승 중 포토인터럽트 3번 검출 시
			if (GPIO_Pin == photoint_3f_Pin)
					{
						is_motor_working = 0;		// 모터 정지
						updateCurrentFloor();			// 현재 층수 파악
					}
		    }

		break;

	case 2:

		// 2번 버튼 (이미 2층이니 동작x)
		if(GPIO_Pin == button_2f_Pin)
		    {
				is_motor_working = 0;		// 모터 정지 및 알림
				updateCurrentFloor();			// 현재 층수 파악
		    }

		// 1번 버튼
		else if(GPIO_Pin == button_1f_Pin)
		    {
				direction = DIR_CCW;	// 2 -> 1 하강
				is_motor_working = 1;

			// 하강 중 포토인터럽트 2번 검출 시
			if (GPIO_Pin == photoint_2f_Pin)
					{
						is_motor_working = 0;		// 모터 정지
						updateCurrentFloor();			// 현재 층수 파악
					}
		    }

		// 3번 버튼
		else if(GPIO_Pin == button_3f_Pin)
		    {
				direction = DIR_CW;	// 2 -> 3 상승
				is_motor_working = 1;

			// 상승 중 포토인터럽트 3번 검출 시
			if (GPIO_Pin == photoint_3f_Pin)
					{
						is_motor_working = 0;		// 모터 정지
						updateCurrentFloor();			// 현재 층수 파악
					}
		    }

		break;


	case 3:

		// 3번 버튼 (이미 3층이니 동작x)
		if(GPIO_Pin == button_3f_Pin)
		    {
				is_motor_working = 0;		// 모터 정지 및 알림
				updateCurrentFloor();			// 현재 층수 파악
		    }

		// 1번 버튼
		else if(GPIO_Pin == button_1f_Pin)
		    {
				direction = DIR_CCW;	// 3 -> 1 하강
				is_motor_working = 1;

			// 하강 중 포토인터럽트 1번 검출 시
			if (GPIO_Pin == photoint_1f_Pin)
					{
						is_motor_working = 0;			// 모터 정지
						updateCurrentFloor();			// 현재 층수 파악
					}
		    }

		// 2번 버튼
		else if(GPIO_Pin == button_2f_Pin)
		    {
				direction = DIR_CCW;	// 3 -> 2 하강
				is_motor_working = 1;

			// 하강 중 포토인터럽트 2번 검출 시
			if (GPIO_Pin == photoint_2f_Pin)
					{
						is_motor_working = 0;		// 모터 정지
						updateCurrentFloor();			// 현재 층수 파악
					}
		    }

		break;
		}
}


