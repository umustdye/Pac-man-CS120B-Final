
/*	Author: Heidi Dye hdye001
 *  	Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Final Project
 *	Exercise Description: completed working complexity for joystick movement
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: https://drive.google.com/file/d/1OA3mPWtRBKywkLCcTLhKBIKZQxhsJdWC/view?usp=sharing
 */
#include <avr/io.h>
#include <avr/power.h>
#include <../header/timer.h>
#include <../header/usart_player.h>
#include <string.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum MusicStates{STARTUP, WAKAWAKA, FRUIT, GHOST_SIREN_1, GHOST_SIREN_2, SPECIAL_ABILITY, EAT_GHOST, GHOST_AFTER_EATEN, HIGH_SCORE, CUTSCENE_CHASE, DIES, WAKAWAKA_SHORT, WAIT}musicState;
enum JoystickStates{RIGHT, LEFT, UP, DOWN, IDLE}joystickState;
char joystick;
unsigned char send[4];


void MusicSM()
{
	switch(musicState)
	{
		case STARTUP:
			send[0] = 0x22;
			send[1] = 0x01;
			send[2] = 0x01;
			send[3] = 0x24;
			musicState = STARTUP;
			break;

		case WAKAWAKA:
			break;
	       	case FRUIT:
		      	break; 
		case GHOST_SIREN_1:
		     	break;
		case GHOST_SIREN_2:
		       	break;	
		case SPECIAL_ABILITY:
		      	break; 
		case EAT_GHOST:
		     	break; 
		case GHOST_AFTER_EATEN:
		    	break; 
		case HIGH_SCORE: 
		    	break;
		case CUTSCENE_CHASE: 
			break;
		case DIES:
			break;

		case WAKAWAKA_SHORT:
			break;

		case WAIT:
			break;
		default:
			break;
	}
}

void CombineSM()
{
	switch(joystick)
	{
		case 'I':
			PORTB = 0x00;
			break;

		case 'L':
			PORTB = 0x08;
			break;

		case 'R': 
			PORTB = 0x02;
			break;

		case 'U':
			PORTB = 0x01;
			break;

		case 'D':
			PORTB = 0x04;
			break;

		default:
			PORTB = 0x00;
			break;
	}

	for(int i=0; i<4; i++)
	{
		USART_Send(send[i]);
	}


}


void JoystickSM()
{
	switch(joystickState)
	{
		case IDLE:
			joystick = 'I';

			if(((~PINA & 0x08) >> 3) == 0x01)
			{
				joystickState = LEFT;
			}

			else if(((~PINA & 0x02) >> 1) == 0x01)
			{
				joystickState = RIGHT;
			}

			else if(((~PINA & 0x01)) == 0x01)
			{
				joystickState = UP;
			}


			else if(((~PINA & 0x04) >> 2) == 0x01)
			{
				joystickState = DOWN;
			}

			break;

		case RIGHT:
			joystick = 'R';
			if(((~PINA & 0x02) >> 1) == 0x00)
			{
				joystickState = IDLE;
			}

			break;

		case LEFT:
			joystick = 'L';
			if(((~PINA & 0x08) >> 3) == 0x00)
			{
				joystickState = IDLE;
			}

			break;

		case UP:
			joystick = 'U';
			if(((~PINA & 0x01)) == 0x00)
			{
				joystickState = IDLE;
			}

			break;

		case DOWN:
			joystick = 'D';
			if(((~PINA & 0x04) >> 2) == 0x00)
			{
				joystickState = IDLE;
			}

			break;

		default:
			joystickState = IDLE;
			break;
	}
}



int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;
	PORTA = 0xFF;

	DDRB = 0xFF;
	PORTB = 0x00;

	joystickState = IDLE;
	musicState = STARTUP;
	TimerOn();
	TimerSet(500);
	initUSART();
	//clock_prescale_set(clock_div_1);




    /* Insert your solution below */
    while (1) {
	    JoystickSM();
	    MusicSM();
	    CombineSM();


	    while(!TimerFlag){}
	    TimerFlag = 0;

    }
    return 1;
}

