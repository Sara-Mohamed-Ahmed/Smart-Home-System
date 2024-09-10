/*
 * LDR_Program.c
 *
 *  Created on: Aug 19, 2024
 *      Author: PC-SHOP
 */
#include "../../lib/STD_Types.h"
#include "../../lib/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/ADC Driver/ADC_interface.h"
#include "LDR_Config.h"
#include "LDR_Interface.h"

u16 LDR_u16_LDRValue(void){
	// Get the LDR value
	u16 LDRValue = ADC_u8GetChannelReading(ADC_u8_CHANNEL_1);
	return LDRValue;
}



void LDR_GardenLights(void) {
    if (LDR_u16_LDRValue() > 512) {
        DIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN6, DIO_u8_HIGH);
    } else {
        DIO_voidSetPinValue(DIO_u8_PORTD, DIO_u8_PIN6, DIO_u8_LOW);
    }
}


void LDR_Init(void){
	DIO_voidSetPinDirection(LDR_u8OUTPort,LDR_u8OUTPin,DIO_u8_INPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTD, DIO_u8_PIN6,DIO_u8_OUTPUT);
}
