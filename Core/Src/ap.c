
#include "ap.h"
#include "usart.h"


void apInit()
{
  hwInit();
}


extern uint8_t rxData;


void apMain()
{

	direction = DIR_CCW;  // 하강시
	is_motor_working = 1; // 시작시

	// 포토 인터럽트 검출 시
	if(GPIO_Pin == photoint_1f_Pin || GPIO_Pin == photoint_2f_Pin || GPIO_Pin == photoint_3f_Pin)
		{
			is_motor_working = 0;		// 모터 정지
			updateCurrentFloor();			// 현재 층수 파악 후 case문 1 or 2 or 3  시작
		}



  while(1)
  {

  }

}









