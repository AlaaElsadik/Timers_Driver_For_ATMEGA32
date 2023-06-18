/*
 * GIE_prog.c
 *
 *  Created on: Aug 20, 2022
 *      Author: Alaa Sayed
 */


#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "GI_interface.h"


#define GI_u8_SREG 				(*(volatile u8*)0x5F)
#define GI_u8_SREG_I 			7

void GI_voidEnable (void)
{
	SET_BIT(GI_u8_SREG,GI_u8_SREG_I);
}
void GI_voidDisable (void)
{
	CLR_BIT(GI_u8_SREG,GI_u8_SREG_I);
}



