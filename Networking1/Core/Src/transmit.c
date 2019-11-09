#include "transmit.h"
#include <string.h>

#define address_min 0x00
#define address_max 0x38

GPIO_TypeDef* location;
int Pin;

enum SPOT {START, MID};
enum SPOT sp;
int where;
uint8_t to_send;
int bit;
TIM_HandleTypeDef *htim;
int data;
int wait;
data_struct* tx;
int i;

void tm_init(GPIO_TypeDef* loc, int pin, TIM_HandleTypeDef *HTIM, data_struct* rx){
	tx = rx;
	location = loc;
	Pin = pin;
	htim = HTIM;
	tm_reset();
}

int tm_next_byte(){
	int ret;
	if(where < 5){
		to_send = *((uint8_t*)tx + where);
		where++;
		ret = 1;
	} else if(where == 5){
		to_send = tx->data[i];
		i++;
		if(i == tx->length){
			where++;
		}
	} else if(where == 6){
		to_send = tx->crc;
		where++;
	}else {
		if(wait != 0){
			wait--;
		} else {
			//stop the timer here
			HAL_TIM_Base_Stop_IT(htim);
			__HAL_TIM_SET_COUNTER(htim, 0);
			tm_reset();
			ret = 0;
		}
	}
	bit = 7;
	return ret;
}


void tm_send(uint8_t* data, uint8_t dest){
	sp = START;

	tx->src = SOURCE;
	tx->pre = SOH;
	tx->dest = dest;
	tx->length = strlen((char*)data);
	strcpy((char*)tx->data, (char*)data);

	tx->crcf = CRC_NO;
	tx->crc = CRC_NOT_CHECK;
	//TODO: set the CRC flag an calculate CRC
	//tx->crcf = CRC_YES
	//tx->crc = gencrc(data,tx->length, 0x00);

	where = 0;

    //Message
	tm_next_byte();

	//Start timer here.
	HAL_TIM_Base_Start_IT(htim);
}

void tm_calc_next(){
	if(cm_get_state() != 0x4){ //not in collision

		if(bit >= 0){
			uint8_t test = to_send;
			int current = ((test>>bit) & 0x1);
			int sent = 0;
			switch(sp){
			case START:
				sent = !current;
				sent = (sent & 0x1);
				sp = MID;
				break;
			case MID:
				sent = current;
				sp = START;
				bit--;
				break;
			}
			data = sent;
		}

		if(bit < 0){
			tm_next_byte();
		}

	} else {
		//restart the transmission or wait until the line is idle
		tm_reset();
		int r = rand() % 1000; //max value of 1000. this sets our time to 1 ms with a max of 1 second
		HAL_Delay(r);
	}
}



void tm_change_pin(){
	HAL_GPIO_WritePin(location,Pin,data);
}

void tm_reset(){
	HAL_GPIO_WritePin(location,Pin,1); //idle high
	where = 0;
	wait = 2;
	bit = 7;
	to_send = *(tx->data + where);
	data = 1;
	i = 0;
}
