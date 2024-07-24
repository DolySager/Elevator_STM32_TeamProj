
#include "ap.h"
#include "usart.h"


void apInit()
{
  hwInit();
}


extern uint8_t rxData;


void apMain()
{

  HAL_UART_Receive_IT(&huart2, &rxData, sizeof(rxData));

  while(1)
  {
	if(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4))
		       {
					rotateDegrees(400, DIR_CW);
		       }


  }
}








