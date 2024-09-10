#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H
#include "../../lib/STD_Types.h"
#define LCD_CLEAR_COMMAND 0x01
void CLCD_voidSendCommand(u8 copy_u8Command);
void CLCD_voidSendData(u8 copy_u8Data);
void CLCD_voidInit(void);
void CLCD_voidGoToXy(u8 copy_u8YPosition,u8 copy_u8Xposition);
//void CLCD_voidSendSpecialChar(u8 copy_u8Location,u8 *copy_pu8Pattern);
void CLCD_voidSendString( u8 *copy_pu8String);
void CLCD_voidSendNumber(u32 copy_u32Number);
void CLCD_voidSendSpecialChar(u8 copy_u8Location, u8 *copy_pu8Pattern, u8 copy_u8YPosition, u8 copy_u8Xposition);
void CLCD_voidClear(void);
void CLCD_voidInitPins(void);
#endif
