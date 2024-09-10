#ifndef BIT_MATH_H
#define BIT_MATH_H
#include "../lib/STD_Types.h"


#define SET_BIT(var, bit_num) ((var) |= (1U << (bit_num)))
#define CLR_BIT(var, bit_num) ((var) &= ~(1U << (bit_num)))
#define TOGY_BIT(var, bit_num) ((var) ^= (1U << (bit_num)))
#define GET_BIT(var, bit_num) (((var) >> (bit_num)) & 1U)

#endif
