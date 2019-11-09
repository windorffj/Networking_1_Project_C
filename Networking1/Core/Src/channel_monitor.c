
#include "channel_monitor.h"

static GPIO_TypeDef* location;
static uint16_t Pin;
enum STATE {IDLE,BUSY,COLLISION};
enum STATE state;
static  int flag;

void cm_init(GPIO_TypeDef* loc, uint16_t pin){
  	Pin = pin;
  	location = loc;
  	state = BUSY;
  	flag = 1; //start it high because the most likely behavior is that it is in idle
}

void cm_sc_inter(TIM_HandleTypeDef *htim, int flag){

	//switch polarity that we are on
	__disable_irq();

	//reset the timer
	HAL_TIM_Base_Stop_IT(htim);
	__HAL_TIM_SET_COUNTER(htim, 0);
	HAL_TIM_Base_Start_IT(htim);

	//we are busy
  	state = BUSY;
  	__enable_irq();
}

void cm_tim_inter(int pin_status){
	if(pin_status == flag){ //if the input has not changed
		if(pin_status == 1){ //check where the pin is at, if it is at low then it is a collision
			state = IDLE;
		} else { //if it is 1 then it is idle
			state = COLLISION;
		}
	} else {
		flag = pin_status;
	}
}

//idle flag is bit 0
//busy flag is bit 1
//collision flag is bit 2
uint16_t cm_get_state(){
	uint16_t ret = 0x7; //all lights on in error state
  	switch(state){
    	case IDLE:
      		ret = 0x1;
      		break;
    	case BUSY:
      		ret = 0x2;
      		break;
    	case COLLISION:
      		ret = 0x4;
      		break;
  	}
  	return ret;
}
