/*
 * ADC_Interface.h
 *
 *  Created on: Aug 3, 2024
 *      Author: walee
 */

#ifndef MCAL_ADC_DRIVER_ADC_INTERFACE_H_
#define MCAL_ADC_DRIVER_ADC_INTERFACE_H_


#define ADC_u8_CHANNEL_0                  0
#define ADC_u8_CHANNEL_1                  1
#define ADC_u8_CHANNEL_2                  2
#define ADC_u8_CHANNEL_3                  3
#define ADC_u8_CHANNEL_4                  4
#define ADC_u8_CHANNEL_5                  5
#define ADC_u8_CHANNEL_6                  6
#define ADC_u8_CHANNEL_7                  7



/* A function to initialize ADC */
void ADC_voidInit (void);

/* A function to get channel reading */
u16 ADC_u8GetChannelReading (u8 Copy_u8Channel);


#endif /* MCAL_ADC_DRIVER_ADC_INTERFACE_H_ */
