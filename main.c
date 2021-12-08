
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

enum MusicStates_1{STARTUP_1, WAKAWAKA, FRUIT, SPECIAL_ABILITY, EAT_GHOST, HIGH_SCORE, CUTSCENE_CHASE, DIES, WAKAWAKA_SHORT, WAIT_1, RESET_1}musicState_1;
enum MusicStates_2{GHOST_SIREN_1, GHOST_SIREN_2, GHOST_AFTER_EATEN, WAIT_2, RESET_2}musicState_2;
enum JoystickStates{RIGHT, LEFT, UP, DOWN, IDLE}joystickState;
char joystick;
unsigned char player_1_send[4];
unsigned char player_1_data;
unsigned char player_2_send[4];
unsigned char player_2_data;
unsigned char ate_pellet;
unsigned char reset;
unsigned char game_start;
unsigned char pacman_died;


void MusicSM()
{
	switch(musicState_1)
	{
		case STARTUP_1:
			if(player_1_data == 0x00)
			{
				player_1_send[0] = 0x22;
				player_1_send[1] = 0x01;
				player_1_send[2] = 0x01;
				player_1_send[3] = 0x24;	
			}

			player_1_data = 0x01;
			if(reset)
			{
				musicState_1 = RESET_1;
			}
			else
			{
				musicState_1 = WAIT_1;
			}
			
			break;

		case WAKAWAKA:
			if(player_1_data == 0x00)
			{
				player_1_send[0] = 0x22;
				player_1_send[1] = 0x01;
				player_1_send[2] = 0x02;
				player_1_send[3] = 0x24;	
			}

			player_1_data = 0x01;
			if(reset)
			{
				musicState_1 = RESET_1;
			}
			else
			{
				musicState_1 = WAIT_1;
			}
			break;
		case FRUIT:
			if(player_1_data == 0x00)
			{
				player_1_send[0] = 0x22;
				player_1_send[1] = 0x01;
				player_1_send[2] = 0x03;
				player_1_send[3] = 0x24;	
			}

			player_1_data = 0x01;
			if(reset)
			{
				musicState_1 = RESET_1;
			}
			else
			{
				musicState_1 = WAIT_1;
			}
			break;	
		case SPECIAL_ABILITY:
			if(player_1_data == 0x00)
			{
				player_1_send[0] = 0x22;
				player_1_send[1] = 0x01;
				player_1_send[2] = 0x06;
				player_1_send[3] = 0x24;	
			}

			player_1_data = 0x01;
			if(reset)
			{
				musicState_1 = RESET_1;
			}
			else
			{
				musicState_1 = WAIT_1;
			}
			break; 
		case EAT_GHOST:
			if(player_1_data == 0x00)
			{
				player_1_send[0] = 0x22;
				player_1_send[1] = 0x01;
				player_1_send[2] = 0x07;
				player_1_send[3] = 0x24;	
			}

			player_1_data = 0x01;
			if(reset)
			{
				musicState_1 = RESET_1;
			}
			else
			{
				musicState_1 = WAIT_1;
			}
			break; 
		case HIGH_SCORE:
			if(player_1_data == 0x00)
			{
				player_1_send[0] = 0x22;
				player_1_send[1] = 0x01;
				player_1_send[2] = 0x09;
				player_1_send[3] = 0x24;	
			}

			player_1_data = 0x01;
			if(reset)
			{
				musicState_1 = RESET_1;
			}
			else
			{
				musicState_1 = WAIT_1;
			}
			break;
		case CUTSCENE_CHASE: 
			if(player_1_data == 0x00)
			{
				player_1_send[0] = 0x22;
				player_1_send[1] = 0x01;
				player_1_send[2] = 0x0A;
				player_1_send[3] = 0x24;	
			}

			player_1_data = 0x01;
			if(reset)
			{
				musicState_1 = RESET_1;
			}
			else
			{
				musicState_1 = WAIT_1;
			}
			break;
		case DIES:
			if(player_1_data == 0x00)
			{
				player_1_send[0] = 0x22;
				player_1_send[1] = 0x01;
				player_1_send[2] = 0x0B;
				player_1_send[3] = 0x24;	
			}

			player_1_data = 0x01;
			if(reset)
			{
				musicState_1 = RESET_1;
			}
			else
			{
				musicState_1 = WAIT_1;
			}
			break;

		case WAKAWAKA_SHORT:
			if(player_1_data == 0x00)
			{
				player_1_send[0] = 0x22;
				player_1_send[1] = 0x01;
				player_1_send[2] = 0x0C;
				player_1_send[3] = 0x24;	
			}

			player_1_data = 0x01;
			if(reset)
			{
				musicState_1 = RESET_1;
			}
			else
			{
				musicState_1 = WAIT_1;
			}
			break;

		case WAIT_1:
			player_1_data == 0x00;


			//go to the other appropriate states
			if(reset == 0x01)
			{
				musicState_1 = RESET_1;
			}

			else if(game_start == 0x01)
			{
				musicState_1 = STARTUP_1;
			}

			else if(ate_pellet == 0x01)
			{
				musicState_1 = WAKAWAKA_SHORT;
			}

			else if(pacman_died == 0x01)
			{
				musicState_1 = DIES;
			}
			break;

		case RESET_1:
			player_1_send[0] = 0x22;
			player_1_send[1] = 0x01;
			player_1_send[2] = 0x23;
			player_1_send[3] = 0x24;

			musicState_1 = WAIT_1;
			break;
		default:
			break;
	}






	switch(musicState_2)
	{

		case GHOST_SIREN_1:
			if(player_2_data == 0x00)
			{
				player_2_send[0] = 0x22;
				player_2_send[1] = 0x01;
				player_2_send[2] = 0x04;
				player_2_send[3] = 0x24;	
			}

			player_2_data = 0x01;
			if(reset)
			{
				musicState_2 = RESET_2;
			}
			else
			{
				musicState_2 = WAIT_2;
			}
			break;
		case GHOST_SIREN_2:
			if(player_2_data == 0x00)
			{
				player_2_send[0] = 0x22;
				player_2_send[1] = 0x01;
				player_2_send[2] = 0x05;
				player_2_send[3] = 0x24;	
			}

			player_2_data = 0x01;
			if(reset)
			{
				musicState_2 = RESET_2;
			}
			else
			{
				musicState_2 = WAIT_2;
			}
			break;	
		case GHOST_AFTER_EATEN:
			if(player_2_data == 0x00)
			{
				player_2_send[0] = 0x22;
				player_2_send[1] = 0x01;
				player_2_send[2] = 0x08;
				player_2_send[3] = 0x24;	
			}

			player_2_data = 0x01;
			if(reset)
			{
				musicState_2 = RESET_2;
			}
			else
			{
				musicState_2 = WAIT_2;
			}
			break; 

		case WAIT_2:
			player_2_data == 0x00;


			//go to the other appropriate states
			if(reset == 0x01)
			{
				musicState_2 = RESET_2;
			}

			else if(ghostState == CHASE || ghostState == SCATTER)
			{
				musicState_2 = GHOST_SIREN_1;
			}

			else if(ghostState == SCARED)
			{
				musicState_2 = GHOST_SIREN_2;
			}

			//eye mode
			else if(ghostState == EYES)
			{
				musicState_2 = GHOST_AFTER_EATEN;
			}
			break;

		case RESET_2:
			player_2_send[0] = 0x22;
			player_2_send[1] = 0x02;
			player_2_send[2] = 0x23;
			player_2_send[3] = 0x24;

			musicState_2 = WAIT_2;
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
	TimerSet(100);
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

