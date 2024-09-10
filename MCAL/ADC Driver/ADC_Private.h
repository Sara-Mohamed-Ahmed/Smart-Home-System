/*
 * ADC_Interface.h
 *
 *  Created on: Aug 3, 2024
 *      Author: walee
 */

#ifndef MCAL_ADC_DRIVER_ADC_INTERFACE_H_
#define MCAL_ADC_DRIVER_ADC_INTERFACE_H_

/* Register description for ADC */
#define ADMUX               *((volatile u8*) 0x27)    /* ADC Multiplexer Selection Register – ADMUX*/
#define ADMUX_MUX0          0
#define ADMUX_MUX1          1
#define ADMUX_MUX2          2
#define ADMUX_MUX3          3
#define ADMUX_MUX4          4
#define ADMUX_ADLAR         5
#define ADMUX_REFS0         6
#define ADMUX_REFS1         7

#define ADCSRA              *((volatile u8*) 0x26)    /* ADC Control and Status Register A – ADCSRA*/
#define ADCSRA_ADPS0        0
#define ADCSRA_ADPS1        1
#define ADCSRA_ADPS2        2
#define ADCSRA_ADIE         3
#define ADCSRA_ADIF         4
#define ADCSRA_ADATE        5
#define ADCSRA_ADSC         6
#define ADCSRA_ADEN         7

#define ADCH                *((volatile u8*) 0x25)    /* The ADC Data Register – ADCL and ADCH*/

#define ADCL                *((volatile u8*) 0x24)    /* The ADC Data Register – ADCL and ADCH*/
#define ADC_u16_ADC_REG           *((volatile u16 *)0x24)
#define SFIOR               *((volatile u8*) 0x50)    /* Special FunctionIO Register – SFIOR*/
#define SFIOR_ADTS0         5
#define SFIOR_ADTS1         6
#define SFIOR_ADTS2         7

#endif /* MCAL_ADC_DRIVER_ADC_INTERFACE_H_ */
