/*
 * Timers_Privet.h
 *
 *  Created on: Aug 8, 2024
 *      Author: PC-SHOP
 */

#ifndef MCAL_TIMERS_TIMERS_PRIVET_H_
#define MCAL_TIMERS_TIMERS_PRIVET_H_

#define TIM0_TCCR0_REG         *((volatile u8*)0x53)
#define TIM0_TCNT0_REG         *((volatile u8*)0x52)
#define TIM0_TIMSK_REG         *((volatile u8*)0x59)
#define TIM0_OCR0_REG          *((volatile u8*)0x5C)
#define TIM1_TCCR1A_REG        *((volatile u8*)0x4F)
#define TIM1_TCCR1B_REG        *((volatile u8*)0x4E)
#define TIM1_OCR1A_REG         *((volatile u16*)0x4A)
#define TIM1_ICR1_REG          *((volatile u16*)0x46)
#define TIM1_TCNT_REG          *((volatile u16*)0x4C)




enum {
	TCCRO_CS00,
	TCCRO_CS01,
	TCCRO_CS02,
	TCCRO_WGM01,
	TCCRO_COM00,
	TCCRO_COM01,
	TCCRO_WGM00,
	TCCRO_FOC0

};


#define	TIMSK_TOIE0   0
#define	TIMSK_OCIE0   1



#endif /* MCAL_TIMERS_TIMERS_PRIVET_H_ */
