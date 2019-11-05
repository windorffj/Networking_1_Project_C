#ifndef CHANNEL_MONITOR_H_
#define CHANNEL_MONITOR_H_

#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include "main.h"

void cm_init(GPIO_TypeDef* loc, uint16_t pin);
void cm_sc_inter(TIM_HandleTypeDef *htim, int flag);
void cm_tim_inter(int pin_status);
uint16_t cm_get_state();

#endif
