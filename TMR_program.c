/*****************************************************************/
/****************** Name    : Alaa Sayed *************************/
/****************** Date    : 25/8/2022  *************************/
/****************** Version : 1.0V       *************************/
/****************** SWC     : TMR        *************************/
/*****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "TMR_interface.h"
#include "TMR_private.h"
#include "TMR_config.h"

void TMR_voidTimer1Init	(void)
{
	/*Select Mode of ICR top Val, Fast Pwm mode*/

	CLR_BIT(TMR_u8_TMR1_TCCR1A_REG,TCCR1A_WGM10);
	SET_BIT(TMR_u8_TMR1_TCCR1A_REG,TCCR1A_WGM11);
	SET_BIT(TMR_u8_TMR1_TCCR1B_REG,TCCR1B_WGM12);
	SET_BIT(TMR_u8_TMR1_TCCR1B_REG,TCCR1B_WGM13);

	/* Set Time to 20msec */
	TMR_u16_TMR1_ICR1_REG = 20000;

	/*Compare Match Value */
	TMR_u16_TMR1_OCR1A_REG = 750;

	/* Non-INverting Mode For Channel A*/
	SET_BIT(TMR_u8_TMR1_TCCR1A_REG,TCCR1A_COM1A1);
	CLR_BIT(TMR_u8_TMR1_TCCR1A_REG,TCCR1A_COM1A0);

	/* Start Timer By Setting the Prescal ar Value to 8*/
	CLR_BIT(TMR_u8_TMR1_TCCR1B_REG,TCCR1B_CS12);
	SET_BIT(TMR_u8_TMR1_TCCR1B_REG,TCCR1B_CS11);
	CLR_BIT(TMR_u8_TMR1_TCCR1B_REG,TCCR1B_CS10);
}
void TMR_voidTimer1SetCompareMatchValueChannelA	(u16 Copy_u16OCR1AValue)
{
	TMR_u16_TMR1_OCR1A_REG = Copy_u16OCR1AValue;
}

void TMR_voidTime0Init(void)
{
#if TIMER0_MODE == NORMAL_MODE

	/* Select Mode = Normal Mode */
	CLR_BIT(TMR_u8_TMR0_TCCR0_REG,TCCR0_WGM00);
	CLR_BIT(TMR_u8_TMR0_TCCR0_REG,TCCR0_WGM01);

	/* Init Timer register with the preload Value */
	TMR_u8_TMR0_TCNT0_REG = TMR_u8_TMR0_PRELOAD_VALUE;

	/* Enable OVF Interrupt */
	SET_BIT(TMR_u8_TMR_TIMSK_REG,TIMSK_TOIE0);

	/* Select Prescaler Value = 8 */
	TMR_u8_TMR0_TCCR0_REG &= TMR_u8_TMR0_PRESCALAR_MASK;
	TMR_u8_TMR0_TCCR0_REG |= TMR_u8_TMR0_PRESCALAR;

#elif TIMER0_MODE == CTC_MODE
	/* Select Mode = CTC Mode */
	CLR_BIT(TMR_u8_TMR0_TCCR0_REG,TCCR0_WGM00);
	SET_BIT(TMR_u8_TMR0_TCCR0_REG,TCCR0_WGM01);

	/*Set Compear MAtch Value*/
	TMR_u8_TMR0_OCR0_REG = TMR_u8_TMR0_COMPARE_MATCH_VALUE;

	/* Enable CTC Interrupt */
	SET_BIT(TMR_u8_TMR_TIMSK_REG,TIMSK_TOIE0);

	/* Select Prescaler Value = 8 */
	TMR_u8_TMR0_TCCR0_REG &= TMR_u8_TMR0_PRESCALAR_MASK;
	TMR_u8_TMR0_TCCR0_REG |= TMR_u8_TMR0_PRESCALAR;

#elif TIMER0_MODE == FAST_PWM_MODE
	/* FAst Pwm Mode*/
	SET_BIT(TMR_u8_TMR0_TCCR0_REG,6);
	CLR_BIT(TMR_u8_TMR0_TCCR0_REG,3);
	/* Select non inverting mode*/
	SET_BIT(TMR_u8_TMR0_TCCR0_REG,5);
	CLR_BIT(TMR_u8_TMR0_TCCR0_REG,4);

	/*Set the required compare match value*/
	//TMR_u8_TMR0_OCR0_REG = TMR_u8_TMR0_COMPARE_MATCH_VALUE;
	/* Select prescalar Value*/
	TMR_u8_TMR0_TCCR0_REG &= TMR_u8_TMR0_PRESCALAR_MASK;
	TMR_u8_TMR0_TCCR0_REG |= TMR_u8_TMR0_PRESCALAR;

#endif

}
void TMR_voidTMR0SetPreLoad  (u8 Copy_u8Preload)
{
	TMR_u8_TMR0_TCNT0_REG = Copy_u8Preload;
}
void TMR_voidTMR0SetCompareMatcValue  (u8 Copy_u8CR0Value)
{
	TMR_u8_TMR0_OCR0_REG = Copy_u8CR0Value;
}
