/*
 * GIE_Interface.h
 *
 *  Created on: Aug 4, 2024
 *      Author: walee
 */

#ifndef MCAL_GIE_DRIVER_GIE_INTERFACE_H_
#define MCAL_GIE_DRIVER_GIE_INTERFACE_H_

#define SREG      *((volatile u8 *)0x5F)
#define SREG_Ibit        7

void  GIE_voidEnable(void);
void  GIE_voidDisable(void);

#endif /* MCAL_GIE_DRIVER_GIE_INTERFACE_H_ */
