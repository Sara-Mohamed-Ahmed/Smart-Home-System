/*
 * ADC_Program.c
 *
 *  Created on: Aug 3, 2024
 *      Author: walee
 */


/* Include LIB files */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "ADC_Private.h"
/* Include driver files */

#include "ADC_Interface.h"

#include "ADC_config.h"

/* A function to initialize ADC */
void ADC_voidInit (void)
{
	/* Select AVCC with external capacitor at AREF pin */
//	SET_BIT( ADMUX , ADMUX_REFS0);
//	CLR_BIT(ADMUX, ADMUX_REFS1);
	SET_BIT( ADMUX , ADMUX_REFS0);
	SET_BIT(ADMUX, ADMUX_REFS1);

	/* Select left adjust */
	CLR_BIT(ADMUX, ADMUX_ADLAR);
	CLR_BIT(ADCSRA,5);

	/* Select 128 prescaler */
	CLR_BIT(ADCSRA, ADCSRA_ADPS0);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS2);

	/* Enable ADC */
	SET_BIT(ADCSRA, ADCSRA_ADEN);
}

/* A function to get channel reading */
u16 ADC_u8GetChannelReading (u8 Copy_u8Channel)
{
	/* Set the required channel */
	/* Set the required channel */
	ADMUX &= 0b11100000;

	ADMUX |= Copy_u8Channel;

	/* Start conversion */
	SET_BIT(ADCSRA, ADCSRA_ADSC);

	/* Polling until conversion is complete */
	while ((GET_BIT(ADCSRA, ADCSRA_ADIF)) == 0);

	/* Clear the conversion complete flag */
	SET_BIT(ADCSRA, ADCSRA_ADIF);

	/* Return the result */
	return ADC_u16_ADC_REG;
}
