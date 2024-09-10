/*
 * Servo_Program.c
 *
 *  Created on: Aug 18, 2024
 *      Author: PC-SHOP
 */
#include "../../lib/STD_Types.h"
#include "../../lib/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include"../../MCAL/Timers/Timers_Interface.h"
#include "Servo_Config.h"
#include "Servo_Interface.h"


void Servo_voidInit(void){
DIO_voidSetPinDirection(Servo_OutPORT,Servo_OutPIN ,DIO_u8_OUTPUT);
}


