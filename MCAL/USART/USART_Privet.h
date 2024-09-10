/*
 * USART_Privet.h
 *
 *  Created on: Aug 11, 2024
 *      Author: PC-SHOP
 */

#ifndef MCAL_USART_USART_PRIVET_H_
#define MCAL_USART_USART_PRIVET_H_
#define USART_u8_UCSRA  *((volatile u8 *)0x2B)
#define USART_u8_UCSRB  *((volatile u8 *)0x2A)
#define USART_u8_UCSRC  *((volatile u8 *)0x40)
#define USART_u8_UBRRL  *((volatile u8 *)0x29)
#define USART_u8_UBRRH  *((volatile u8 *)0x40)
#define USART_u8_UDR  *((volatile u8 *)0x2C)


#endif /* MCAL_USART_USART_PRIVET_H_ */
