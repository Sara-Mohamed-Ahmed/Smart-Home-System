/*
 * USART_Interface.h
 *
 *  Created on: Aug 11, 2024
 *      Author: PC-SHOP
 */

#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_
void USART_voidInit(void);
void USART_voidSendByte(u8 Copy_u8Byte);
u8 USART_voidRecieveByte(void);

void USART_voidSendString(u8 *copy_pu8Ptr);
void  USART_voidRecieveString(u8 *copy_pu8Ptr);

u16 Check_UserName(u8 *receivedString, u8 *stringArray[], u16 arraySize);
u8 compareString(u8 Copy_u8arr1[], u8 Copy_u8arr2[]);

void DisplayCountdown(u16 seconds);
#endif /* MCAL_USART_USART_INTERFACE_H_ */
