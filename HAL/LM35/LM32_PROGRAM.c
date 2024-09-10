/*
 * LM32_PROGRAM.c
 *
 *  Created on: Aug 12, 2024
 *      Author: PC-SHOP
 */
#include "../../lib/STD_Types.h"
#include "../../lib/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/ADC Driver/ADC_interface.h"
#include "../Warning_System/Wrning_System_Interface.h"
#include "../Warning_System/Wrning_System_Interface.h"
#include "../DC_Fan/FAN_interface.h"
#include "LM32_CONFIG.h"
#include "LM32_INTERFACE.h"
#include "LM32_PRIVET.h"




void LM35_FireAlarmSystem(){

	if (LM35_u16_TempValue() >= 70)
	    {
		Warning_Buzzer_On();
	    }
	    else if (LM35_u16_TempValue() >= 30)
	    {
	    Fan_On();
	    }
	    else if (LM35_u16_TempValue() < 20)
	    	    {
	    	    Fan_Off();
	    	    }
}

u16 LM35_u16_TempValue(){
u16 Local_u16Digital_Value;
u16 Local_u16Analog_Value;
u16 Local_u16Temp_Value;
Local_u16Digital_Value= ADC_u8GetChannelReading(LM35_u8OUTPin);
Local_u16Analog_Value=((Local_u16Digital_Value*2560UL)/1024);
Local_u16Temp_Value=Local_u16Analog_Value/10;
return Local_u16Temp_Value;
}


void LM_35_Init(void){
	DIO_voidSetPinDirection(LM35_u8OUTPort,LM35_u8OUTPin,DIO_u8_INPUT);
}
