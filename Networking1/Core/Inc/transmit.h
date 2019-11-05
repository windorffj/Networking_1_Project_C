


#ifndef TRANSMIT_H_
#define TRANSMIT_H_

#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "main.h"
#include "channel_monitor.h"
#include "crc.h"


void tm_init(GPIO_TypeDef* loc, int pin,TIM_HandleTypeDef *HTIM, data_struct* rx);
void tm_send(uint8_t* data, uint8_t dest);
int tm_next_byte();
void tm_change_pin();
void tm_calc_next();

#endif
