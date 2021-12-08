
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
#include <../header/usart_graphics.h>
#include <string.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum MusicStates_1{STARTUP_1, WAKAWAKA, FRUIT, SPECIAL_ABILITY, EAT_GHOST, HIGH_SCORE, CUTSCENE_CHASE, DIES, WAKAWAKA_SHORT, WAIT_1, RESET_1}musicState_1;
enum MusicStates_2{GHOST_SIREN_1, GHOST_SIREN_2, GHOST_AFTER_EATEN, WAIT_2, RESET_2}musicState_2;
enum GameStates{GAME_START, GAME_PLAY, GAME_LOST, GAME_RESTART, GAME_WAIT, GAME_RESTART_RELEASE, GAME_START_RELEASE}gameState;
enum PacmanStates{PACMAN_WAIT, PACMAN_START, PACMAN_PLAY, PACMAN_POWERUP}pacmanState;
enum BlinkyStates{BLINKY_WAIT, BLINKY_START, BLINKY_CHASE, BLINKY_SCATTER, BLINKY_SCARED, BLINKY_EYES}blinkyState;
enum JoystickStates{RIGHT, LEFT, UP, DOWN, IDLE}joystickState;
char joystick;
unsigned char player_1_send[4];
unsigned char player_1_data;
unsigned char player_2_send[4];
unsigned char pacman_send[13];
unsigned char game_send[13];
unsigned char blinky_send[13];
unsigned char clyde_send[13];
unsigned char inky_send[13];
unsigned char pinky_send[13];
unsigned char player_2_data;
unsigned char ate_pellet;
unsigned char reset;
unsigned char game_count;
unsigned int score;
unsigned int highscore;
unsigned char game_start;
unsigned char pacman_died;
unsigned char pacman_lives;

void TransmitPlayer()
{
	if(player_1_data == 0x01)
	{
		//transmit player 1 data
		for(int i=0; i<4; i++)
		{
			USART_Send0(player_1_send[i]);
		}
		player_1_data == 0x00;
	}

	//give some time between the next transmit
	for(int i=0; i<50; i++)
	{
		//just here for spacing
	}

	if(player_2_data == 0x01)
	{
		//transmit player 2 data
		for(int i=0; i<4; i++)
		{
			USART_Send(player_2_send[i]);
		}
		player_2_data == 0x00;
	}
}

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
			//player_1_data == 0x00;


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
			player_1_data = 0x00;
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
			//player_2_data == 0x00;


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
			player_2_data = 0x00;
			break;
		default:
			break;
	}

	//transmit the music
	TransmitPlayer();
}

/*void CombineSM()
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


}*/


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


void GameSM()
{
	switch (gameState)
	{
	case GAME_START:
		if(~PINB ==0x02)
		{
			gameState = GAME_RESTART_RELEASE;
		}
		game_count++;

		if(game_count > 20)
		{
			gameState = GAME_START;
			game_start = 0x00;
		}
		break;

	case GAME_PLAY:
		if(~PINB ==0x02)
		{
			gameState = GAME_RESTART_RELEASE;
		}

		else
		{
			check_highscore(score);
			if(pacman_died)
			{
				pacman_lives--;
			}

			if(pacman_lives <= 0)
			{
				gameState = GAME_LOST;
			}
			
		}
		break;

	case GAME_LOST:
		if(~PINB ==0x02)
		{
			gameState = GAME_RESTART_RELEASE;
		}
		pacman_died = 0x01;
		gameState = GAME_WAIT;
		break;


	case GAME_WAIT:
		reset = 0x00;
		pacman_died = 0x00;
		game_start = 0x00;
		player_1_data = 0x00;
		player_2_data = 0x00;
		ate_pellet = 0x00;
		game_count = 0x00;
		score = 0;
		highscore = get_highscore();
		pacman_lives = 3;
		if(~PINB == 0x01)
		{
			gameState = GAME_START_RELEASE;
		}

		else if(~PINB ==0x02)
		{
			gameState = GAME_RESTART_RELEASE;
		}
		break;
	
	case GAME_RESTART:
		restart = 0x01;
		gameState = GAME_WAIT;
		break;

	case GAME_RESTART_RELEASE:
		if(~PINB == 0x00)
		{
			gameState = GAME_RESTART;
		}
		break;

	case GAME_START_RELEASE:
		if(~PINB == 0x00)
		{
			gameState = GAME_START;
			pacman_lives = 3;
			game_start = 0x01;
			game_count = 0x00;
			score = 0;
			ate_pellet = 0x00;
		}
		break;
	
	default:
		break;
	}
}




int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;
	PORTA = 0xFF;

	DDRB = 0x00;
	PORTB = 0xFF;

	//DDRB = 0xFF;
	//PORTB = 0x00;

	joystickState = IDLE;
	musicState_1 = WAIT_1;
	musicState_2 = WAIT_2;
	gameState = GAME_WAIT;
	TimerOn();
	TimerSet(100);
	initUSART0();
	initUSART1();
	//clock_prescale_set(clock_div_1);




    /* Insert your solution below */
    while (1) {
	    JoystickSM();
	    MusicSM();


	    while(!TimerFlag){}
	    TimerFlag = 0;

    }
    return 1;
}

