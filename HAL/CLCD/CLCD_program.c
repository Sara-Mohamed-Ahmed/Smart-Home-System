#include "../../lib/STD_Types.h"
#include "../../lib/BIT_MATH.h"
#include <util/delay.h>
#include <stdio.h>
#include "../../MCAL/DIO/DIO_Interface.h"
#include "CLCD_private.h"
#include "CLCD_interface.h"
#include "CLCD_cfg.h"


void CLCD_voidSendCommand(u8 copy_u8Command)
{
	/*configure rs , rw direction (output)*/
	/*configure rs=0 , rw=0 ,ENABLE=HIGH */

	DIO_voidSetPinValue(CLCD_u8CONTROLPORT,CLCD_u8RS,CLCD_u8LOW);

	DIO_voidSetPinValue(CLCD_u8CONTROLPORT,CLCD_u8RW,CLCD_u8LOW);

	DIO_voidSetPinValue(CLCD_u8CONTROLPORT,CLCD_u8ENABLE,CLCD_u8LOW);

	DIO_voidSetPortValue(CLCD_u8DATAPORT,copy_u8Command);

	DIO_voidSetPinValue(CLCD_u8CONTROLPORT,CLCD_u8ENABLE,CLCD_u8HGIH);
	_delay_ms(2);
	DIO_voidSetPinValue(CLCD_u8CONTROLPORT,CLCD_u8ENABLE,CLCD_u8LOW);


}
void CLCD_voidSendData(u8 copy_u8Data)
{
	DIO_voidSetPinValue(CLCD_u8CONTROLPORT,CLCD_u8RS,CLCD_u8HGIH);

	DIO_voidSetPinValue(CLCD_u8CONTROLPORT,CLCD_u8RW,CLCD_u8LOW);

	DIO_voidSetPinValue(CLCD_u8CONTROLPORT,CLCD_u8ENABLE,CLCD_u8LOW);

	DIO_voidSetPortValue(CLCD_u8DATAPORT,copy_u8Data);

	DIO_voidSetPinValue(CLCD_u8CONTROLPORT,CLCD_u8ENABLE,CLCD_u8HGIH);
	_delay_ms(2);
	DIO_voidSetPinValue(CLCD_u8CONTROLPORT,CLCD_u8ENABLE,CLCD_u8LOW);
}
void CLCD_voidInit(void)
{
	_delay_ms(40);
	CLCD_voidSendCommand(0b00111000);
	CLCD_voidSendCommand(0b00001111);
	CLCD_voidSendCommand(1);
	_delay_ms(2);
}

void CLCD_voidInitPins(void)
{
	DIO_voidSetPinDirection(CLCD_u8CONTROLPORT, CLCD_u8RS, DIO_u8_OUTPUT); //lcd rs
	DIO_voidSetPinDirection(CLCD_u8CONTROLPORT, CLCD_u8RW, DIO_u8_OUTPUT);//lcd rw
	DIO_voidSetPinDirection(CLCD_u8CONTROLPORT, CLCD_u8ENABLE, DIO_u8_OUTPUT);//lcd e
	DIO_voidSetPortDirection(CLCD_u8DATAPORT, 0XFF); // lcd data out
}

void CLCD_voidGoToXy(u8 copy_u8YPosition,u8 copy_u8Xposition)
{
	u8 local_u8address;
	if(copy_u8YPosition==0)
	{
		local_u8address=copy_u8Xposition;
	}
	else
	{
		local_u8address=0x40+copy_u8Xposition;
	}
	SET_BIT(local_u8address,7);
	CLCD_voidSendCommand(local_u8address);

}

/*void CLCD_voidSendSpecialChar(u8 copy_u8Location,u8 *copy_pu8Pattern)
{
	u8 Local_u8address=copy_u8Location*8;

	SET_BIT(Local_u8address,6);
	CLCD_voidSendCommand(Local_u8address);

	for(u8 local_u8iteration=0;local_u8iteration<8;local_u8iteration++)
	{
		CLCD_voidSendData(copy_pu8Pattern[local_u8iteration]);
	}
	CLCD_voidGoToXy(0,0);
	CLCD_voidSendData(copy_u8Location);
}*/

void CLCD_voidSendSpecialChar(u8 copy_u8Location, u8 *copy_pu8Pattern, u8 copy_u8YPosition, u8 copy_u8Xposition) {
    u8 Local_u8address = copy_u8Location * 8;

    // Set the CGRAM address for the custom character
    SET_BIT(Local_u8address, 6);  // Assuming bit 6 is used for CGRAM address set
    CLCD_voidSendCommand(Local_u8address);

    // Send the pattern for the custom character to CGRAM
    for (u8 local_u8iteration = 0; local_u8iteration < 8; local_u8iteration++) {
        CLCD_voidSendData(copy_pu8Pattern[local_u8iteration]);
    }

    // Move the cursor to the specified position
    CLCD_voidGoToXy(copy_u8YPosition,copy_u8Xposition);

    // Print the custom character
    CLCD_voidSendData(copy_u8Location);
}
//void CLCD_voidSendString(const u8 *copy_pu8String)
void CLCD_voidSendString(u8 *copy_pu8String){
	u8 local_u8iterationString;

	for (local_u8iterationString=0; copy_pu8String[local_u8iterationString]!='\0';local_u8iterationString++){
		CLCD_voidSendData(copy_pu8String[local_u8iterationString]);
	}

}
void CLCD_voidSendNumber(u32 copy_u32Number) {
    u8 local_u8Buffer[12]; // Buffer to hold the string representation of the number
    u32 local_u32Length;
    u8 local_u8iterationNumber;

    // Convert the number to a string
    local_u32Length = snprintf(local_u8Buffer, sizeof(local_u8Buffer), "%lu", copy_u32Number);

    // Send each character to the LCD
    for (local_u8iterationNumber = 0; local_u8iterationNumber < local_u32Length; local_u8iterationNumber++) {
        CLCD_voidSendData(local_u8Buffer[local_u8iterationNumber]);
    }
}

void CLCD_voidClear(void) {
    // Send the clear display command to the LCD
    CLCD_voidSendCommand(LCD_CLEAR_COMMAND);

    // Wait for the LCD to process the command
    // The HD44780 datasheet specifies a delay of up to 1.64 ms for the clear display command
    // A delay of 2 ms is typically sufficient
    _delay_ms(2);
}

