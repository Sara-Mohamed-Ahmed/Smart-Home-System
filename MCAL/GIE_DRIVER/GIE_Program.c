/*
 * GIE_Program.c
 *
 *  Created on: Aug 4, 2024
 *      Author: walee
 */

#include "../../LIB/BIT_MATH.h"
#include "GIE_Interface.h"

void  GIE_voidEnable(void){
	SET_BIT(SREG,SREG_Ibit);
}
void  GIE_voidDisable(void){
	CLR_BIT(SREG,SREG_Ibit);
}
