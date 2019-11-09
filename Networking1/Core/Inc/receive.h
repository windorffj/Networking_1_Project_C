#ifndef RECIEVE_H_
#define RECIEVE_H_

#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "channel_monitor.h"
#include "crc.h"

void rc_init(uint8_t* Store, TIM_HandleTypeDef *HTIM, UART_HandleTypeDef *HUART, data_struct* RX);
int rc_receive();
int rc_store();
void rc_send();
int rc_timeout();
void rc_reset();

#endif
