/****************************************Copyright (c)****************************************************
**
**                                 http://www.powermcu.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               main.c
** Descriptions:            The GLCD application function
**
**--------------------------------------------------------------------------------------------------------
** Created by:              AVRman
** Created date:            2010-11-7
** Version:                 v1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             Paolo Bernardi
** Modified date:           03/01/2020
** Version:                 v2.0
** Descriptions:            basic program for LCD and Touch Panel teaching
**
*********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "LPC17xx.h"
#include "GLCD/GLCD.h"
#include "TouchPanel/TouchPanel.h"
#include "timer/timer.h"
#include "Game.h"
#include "joystick/joystick.h"
#include "button_EXINT/button.h"
#include "RIT/RIT.h"

struct Board board;
struct Player player1;
struct Player player2;

#define SIMULATOR 1

#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif

int main(void)
{

    SystemInit(); /* System Initialization (i.e., PLL)  */

    LCD_Initialization();

    init_RIT(0xBEBC20);
    enable_RIT();

    joystick_init();
    BUTTON_init();

   // TP_Init();
   //  TouchPanel_Calibrate();

    LCD_Clear(White);
    GUI_Text(0, 280, (uint8_t *)" Premere INT0 per incominciare ", Blue, White);


    LPC_SC->PCON |= 0x1; /* power-down	mode										*/
    LPC_SC->PCON &= ~(0x2);

    while (1)
    {
        __ASM("wfi");
    }
}

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
