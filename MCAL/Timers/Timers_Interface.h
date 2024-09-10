/*
 * Timers_Interface.h
 *
 *  Created on: Aug 8, 2024
 *      Author: PC-SHOP
 */

#ifndef MCAL_TIMERS_TIMERS_INTERFACE_H_
#define MCAL_TIMERS_TIMERS_INTERFACE_H_
//NORNAL OR OVERFLOW MODE
void TIM0_voidNormalMode(void);
void TIM0_NormalSetCallBack(void(*Copy_u8pf)(void));

//CTC (COMPARE MATCH) MODE
void TIM0_voidCTCMode(void);
void TIM0_CTCSetCallBack(void(*Copy_u8pf)(void));

void TIM0_voidFastPWMInit(void);
void TIM0_voidSetCompareMatch (u8 Copy_u8Value);

void TIM1_voidFastPWM(void);
#endif /* MCAL_TIMERS_TIMERS_INTERFACE_H_ */
