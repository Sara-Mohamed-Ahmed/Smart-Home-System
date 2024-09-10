/*
 * DIO_Interface.h
 *
 *  Created on: Jul 29, 2024
 *      Author: PC-SHOP
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_
#include "../../lib/STD_Types.h"


//Registers macros
#define DIO_u8_PORTA      0
#define DIO_u8_PORTB      1
#define DIO_u8_PORTC      2
#define DIO_u8_PORTD      3

//Pins macros
#define DIO_u8_PIN0       0
#define DIO_u8_PIN1       1
#define DIO_u8_PIN2       2
#define DIO_u8_PIN3       3
#define DIO_u8_PIN4       4
#define DIO_u8_PIN5       5
#define DIO_u8_PIN6       6
#define DIO_u8_PIN7       7

//Other macros
#define DIO_u8_LOW        0
#define DIO_u8_HIGH       1

#define DIO_u8_INPUT      0
#define DIO_u8_OUTPUT     1




void DIO_voidSetPinDirection(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Direction);
void DIO_voidSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8Value);
void DIO_voidSetPortDirection(u8 Copy_u8PortId, u8 Copy_u8Direction);
u8 DIO_voidGetPortValue(u8 Copy_u8PortId);
u8 DIO_voidGetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId);
u8 DIO_voidGetPortValue(u8 Copy_u8PortId);


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
