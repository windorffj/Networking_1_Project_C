/*
 * crc.c
 *
 *  Created on: Nov 5, 2019
 *      Author: James Windorff
 */

#include "crc.h"


uint8_t gen_crc(uint8_t *data, uint8_t len, uint8_t crc_given){
    uint8_t crc = 0xff;
    uint8_t i, j;
    for (i = 0; i < len; i++) {
        crc ^= data[i];
        for (j = 0; j < 8; j++) {
            if ((crc & 0x80) != 0)
                crc = (uint8_t)((crc << 1) ^ CRC_CHECK);
            else
                crc <<= 1;
        }
    }
    if(crc_given != 0x00){
    	crc ^= crc_given; //this should return 0x00 if correct
    }
    return crc;
}
