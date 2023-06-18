/*****************************************************************/
/****************** Name    : Alaa Sayed *************************/
/****************** Date    : 20/8/2022  *************************/
/****************** Version : 1.0V       *************************/
/****************** SWC     : TMR        *************************/
/*****************************************************************/
#ifndef TMR_INTERFACE_H
#define TMR_INTERFACE_H

void TMR_voidTime0Init(void);

void TMR_voidTimer1Init	(void);

void TMR_voidTimer1SetCompareMatchValueChannelA	(u16 Copy_u16OCR1AValue);

void TMR_voidTMR0SetPreLoad  (u8 Copy_u8Preload);

void TMR_voidTMR0SetCompareMatcValue  (u8 Copy_u8CR0Value);


#endif
