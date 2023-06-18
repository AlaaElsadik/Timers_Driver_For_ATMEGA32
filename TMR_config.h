/*****************************************************************/
/****************** Name    : Alaa Sayed *************************/
/****************** Date    : 20/8/2022  *************************/
/****************** Version : 1.0V       *************************/
/****************** SWC     : TMR        *************************/
/*****************************************************************/
#ifndef TMR_CONFIG_H
#define TMR_CONFIG_H

#define TMR_u8_TMR0_PRELOAD_VALUE             192
#define TMR_u8_TMR0_COMPARE_MATCH_VALUE		  250
#define TMR_u16_TMRO_OVERFLOW_COUNTER         1000

/* Choose Timer Operation Mode*/
/* Options: 1- NORMAL_MODE
 * 			2- CTC_MODE
 * 			3- FAST_PWM_MODE
 * 			4- PWM_PHASE_CORRECT
 */


#define TIMER0_MODE			FAST_PWM_MODE

/* Choose Division Factor*/
/* Options: 1-DIVIDE_BY_1
			2-DIVIDE_BY_8
			3-DIVIDE_BY_64
			4-DIVIDE_BY_256
			5-DIVIDE_BY_1024
*/

#define TMR_u8_TMR0_PRESCALAR					DIVIDE_BY_8

#endif
