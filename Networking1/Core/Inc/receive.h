#ifndef RECIEVE_H_
#define RECIEVE_H_

#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "main.h"
#include "channel_monitor.h"
#include "crc.h"

void rc_init(TIM_HandleTypeDef *HTIM, UART_HandleTypeDef *HUART, data_struct* rx);
int rc_receive( uint8_t* store, data_struct* rx);
int rc_store(uint8_t* store, data_struct* rx);
void rc_send(uint8_t* store, data_struct* rx);
int rc_timeout(uint8_t* store, data_struct* rx);
void rc_reset(data_struct* rx);

#endif
