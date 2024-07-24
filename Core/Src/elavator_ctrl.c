#include "elavator_ctrl.h"


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(!HAL_GPIO_ReadPin(photoint_1f_GPIO_Port, photoint_1f_Pin))
    {

    }
	else
	{

    }


	if(!HAL_GPIO_ReadPin(photoint_2f_GPIO_Port, photoint_2f_Pin))
    {

    }
	else
	{

    }


	if(!HAL_GPIO_ReadPin(photoint_3f_GPIO_Port, photoint_3f_Pin))
    {

    }
	else
	{

    }


	if(!HAL_GPIO_ReadPin(button_1f_GPIO_Port, button_1f_Pin))
    {

    }
	else
	{

    }


	if(!HAL_GPIO_ReadPin(button_2f_GPIO_Port, button_2f_Pin))
    {

    }
	else
	{

    }


	if(!HAL_GPIO_ReadPin(button_3f_GPIO_Port, button_3f_Pin))
    {

    }
	else
	{

    }
}
