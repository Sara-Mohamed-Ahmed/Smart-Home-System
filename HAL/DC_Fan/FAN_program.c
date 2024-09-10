/*
 * Fan_Program.c
 *
 *  Created on: Aug 18, 2024
 *      Author: PC-SHOP
 */

#include "../../lib/STD_Types.h"
#include "../../lib/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Fan_Config.h"
#include"Fan_Interface.h"


void Fan_Init(void){
	DIO_voidSetPinDirection(DC_Fan_OutPort,DC_Fan_OutPin,DIO_u8_OUTPUT);
}
void Fan_On(void){
	DIO_voidSetPinValue(DC_Fan_OutPort,DC_Fan_OutPin,DIO_u8_HIGH);
}
void Fan_Off(void){
	DIO_voidSetPinValue(DC_Fan_OutPort,DC_Fan_OutPin,DIO_u8_LOW);
}
