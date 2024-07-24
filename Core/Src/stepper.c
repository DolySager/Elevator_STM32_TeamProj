#include "stepper.h"

uint8_t is_motor_working = 0;
uint8_t direction = 0;	// 0: CW, 1: CCW

bool stepperInit()
{
  bool ret = true;

  return ret;
}

void stepMotor(uint8_t step)
{
	HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, HALF_STEP_SEQ[step][0]);
	HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, HALF_STEP_SEQ[step][1]);
	HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, HALF_STEP_SEQ[step][2]);
	HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, HALF_STEP_SEQ[step][3]);
}



