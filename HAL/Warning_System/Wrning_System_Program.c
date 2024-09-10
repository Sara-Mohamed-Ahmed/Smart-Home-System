/*
 * Wrning_System_Program.c
 *
 *  Created on: Aug 18, 2024
 *      Author: PC-SHOP
 */
#include "../../lib/STD_Types.h"
#include "../../lib/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../Warning_System/Wrning_System_Config.h"
#include "../Warning_System/Wrning_System_Interface.h"

void Warning_LED_On(void){
	DIO_voidSetPinValue(Warning_LED_OutPort,Warning_LED_OutPin, DIO_u8_HIGH);

}
void Warning_LED_Off(void){
	DIO_voidSetPinValue(Warning_LED_OutPort,Warning_LED_OutPin, DIO_u8_LOW);
}
void Warning_Buzzer_On(void){
	DIO_voidSetPinValue(Warning_Buzzer_OutPort,Warning_Buzzer_OutPin, DIO_u8_HIGH);
}
void Warning_Buzzer_Off(void){
	DIO_voidSetPinValue(Warning_Buzzer_OutPort,Warning_Buzzer_OutPin, DIO_u8_LOW);


}

void Warning_LED_Init(void){
	DIO_voidSetPinDirection(Warning_LED_OutPort,Warning_LED_OutPin,DIO_u8_OUTPUT);
}
void Warning_Buzzer_Init(void){
	DIO_voidSetPinDirection(Warning_Buzzer_OutPort,Warning_Buzzer_OutPin,DIO_u8_OUTPUT);
}
