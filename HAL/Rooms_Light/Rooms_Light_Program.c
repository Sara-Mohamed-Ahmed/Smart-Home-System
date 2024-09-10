/*
 * Rooms_Light_Program.c
 *
 *  Created on: Aug 18, 2024
 *      Author: PC-SHOP
 */

#include "../../lib/STD_Types.h"
#include "../../lib/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Rooms_Light_Config.h"
#include "Rooms_Light_Interface.h"

void RoomLights_Init(void){
	DIO_voidSetPinDirection(Room1_Light_OutPort,Room1_Light_OutPin,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(Room2_Light_OutPort,Room2_Light_OutPin,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(Room3_Light_OutPort,Room3_Light_OutPin,DIO_u8_OUTPUT);
}
void Room1_Light_On(void){
	DIO_voidSetPinValue(Room1_Light_OutPort,Room1_Light_OutPin,DIO_u8_HIGH);
}
void Room1_Light_Off(void){
	DIO_voidSetPinValue(Room1_Light_OutPort,Room1_Light_OutPin,DIO_u8_LOW);
}
void Room2_Light_On(void){
	DIO_voidSetPinValue(Room2_Light_OutPort,Room2_Light_OutPin,DIO_u8_HIGH);
}
void Room2_Light_Off(void){
	DIO_voidSetPinValue(Room2_Light_OutPort,Room2_Light_OutPin,DIO_u8_LOW);
}
void Room3_Light_On(void){
	DIO_voidSetPinValue(Room3_Light_OutPort,Room3_Light_OutPin,DIO_u8_HIGH);

}
void Room3_Light_Off(void){
	DIO_voidSetPinValue(Room3_Light_OutPort,Room3_Light_OutPin,DIO_u8_LOW);
}
