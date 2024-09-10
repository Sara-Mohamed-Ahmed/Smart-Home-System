/*
 * HC_05_Program.c
 *
 *  Created on: Aug 18, 2024
 *      Author: PC-SHOP
 */
#include "../../lib/STD_Types.h"
#include "../../lib/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "HC_05_Config.h"
#include "HC_05_Interface.h"

void BluetoothModule_Init(void){
	DIO_voidSetPinDirection(HC_05_Port,HC_05_RX,DIO_u8_INPUT);
	DIO_voidSetPinDirection(HC_05_Port,HC_05_TX,DIO_u8_OUTPUT);

}
