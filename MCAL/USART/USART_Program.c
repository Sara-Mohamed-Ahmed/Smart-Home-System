/*
 * USART_Program.c
 *
 *  Created on: Aug 11, 2024
 *      Author: PC-SHOP
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "USART_Confug.h"
#include "USART_Interface.h"
#include "USART_Privet.h"
#include <string.h>
#include <util/delay.h>
#include "../../HAL/CLCD/CLCD_interface.h"
void USART_voidInit(void){
	u16 Local_u8BaudRate=0x34;
	u8 	Local_u8UCSRC_value=0b10000000;

	//SELECT BAUD RATE
	USART_u8_UBRRL=(u8)Local_u8BaudRate;
	USART_u8_UBRRH=(u8)Local_u8BaudRate>>8;

	// disable for multi processor mode
	CLR_BIT(USART_u8_UCSRA,0);
	// enable the hardware prepheral
	SET_BIT(USART_u8_UCSRB,3);
	SET_BIT	(USART_u8_UCSRB,4);
	// character size (select 8 bit)
	CLR_BIT(USART_u8_UCSRB,2);
	SET_BIT(Local_u8UCSRC_value,2);
	SET_BIT(Local_u8UCSRC_value,1);
	//SEELCT ASYNCH
	CLR_BIT(USART_u8_UCSRC,6);
	// DISABLE PARITY BIT
	CLR_BIT(USART_u8_UCSRC,4);
	CLR_BIT(USART_u8_UCSRC,5);
	// SELECT ONE STOP BIT
	CLR_BIT(USART_u8_UCSRC,3);
	USART_u8_UCSRC=Local_u8UCSRC_value;
}


void USART_voidSendByte(u8 Copy_u8Byte){
while (GET_BIT(USART_u8_UCSRA,5)==0);
USART_u8_UDR=Copy_u8Byte;
}


u8 USART_voidRecieveByte(void){

	while (GET_BIT(USART_u8_UCSRA,7)==0);
return USART_u8_UDR;


}

void USART_voidSendString(u8 *copy_pu8Ptr)
{
	u16 i=0;

	while(copy_pu8Ptr[i] != '\0')
	{
		USART_voidSendByte(copy_pu8Ptr[i]);
		i++;
	}

}


void  USART_voidRecieveString(u8 *copy_pu8Ptr)
{
	u16 i=0;
	copy_pu8Ptr[i]=USART_voidRecieveByte();
	while(copy_pu8Ptr[i] !='#')
	{
		i++;
		copy_pu8Ptr[i]=USART_voidRecieveByte();

	}
	copy_pu8Ptr[i]='\0';

}


u8 compareString(u8 Copy_u8arr1[], u8 Copy_u8arr2[]) {
    u16 i = 0;
    while (Copy_u8arr1[i] != '\0' && Copy_u8arr2[i] != '\0') {
        if (Copy_u8arr1[i] != Copy_u8arr2[i]) {
            return 0; // Strings do not match
        }
        i++;
    }
    return (Copy_u8arr1[i] == '\0' && Copy_u8arr2[i] == '\0') ? 1 : 0;
}

u16 Check_UserName(u8 *receivedString, u8 *stringArray[], u16 arraySize) {
    for (u16 i = 0; i < arraySize; i++) {
        if (compareString(receivedString, stringArray[i])) {
            return i; // Return index of the matching user
        }
    }
    return -1; // Return -1 if no match is found
}

void DisplayCountdown(u16 seconds) {
    while (seconds > 0) {
        CLCD_voidClear();
        CLCD_voidSendString("Blocked for:");
        CLCD_voidGoToXy(1, 0);
        CLCD_voidSendNumber(seconds);
        _delay_ms(1000);
        seconds--;
    }
}
