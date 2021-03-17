/*
 * ADC.c
 *
 *  Created on: Mar 16, 2021
 *      Author: JUANITA
 */

#include "ADC.h"
#include "main.h"

ADC_HandleTypeDef hadc1;

uint16_t  read_ADC(void)
{
		uint16_t  Read;
	   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);

	    // Get ADC value
	    HAL_ADC_Start(&hadc1);
	    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	    Read = HAL_ADC_GetValue(&hadc1);

	    // Test: Set GPIO pin low
	    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);

	    return Read;
}

