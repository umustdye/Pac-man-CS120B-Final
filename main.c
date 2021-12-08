
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
#include <../header/character.h>
#include <../header/pacman.h>
#include <../header/ghost.h>
#include <../header/highscore.h>
#include <string.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum MusicStates_1{STARTUP_1, WAKAWAKA, FRUIT, SPECIAL_ABILITY, EAT_GHOST, HIGH_SCORE, CUTSCENE_CHASE, DIES, WAKAWAKA_SHORT, WAIT_1, RESET_1}musicState_1;
enum MusicStates_2{GHOST_SIREN_1, GHOST_SIREN_2, GHOST_AFTER_EATEN, WAIT_2, RESET_2}musicState_2;
enum GameStates{GAME_START, GAME_PLAY, GAME_LOST, GAME_RESTART, GAME_WAIT, GAME_RESTART_RELEASE, GAME_START_RELEASE}gameState;
enum PacmanStates{PACMAN_DIE, PACMAN_WAIT, PACMAN_START, PACMAN_PLAY, PACMAN_POWERUP}pacmanState;
enum BlinkyStates{BLINKY_WAIT, BLINKY_START, BLINKY_CHASE, BLINKY_SCATTER, BLINKY_SCARED, BLINKY_EYES}blinkyState;
enum ClydeStates{CLYDE_WAIT, CLYDE_START, CLYDE_CHASE, CLYDE_SCATTER, CLYDE_SCARED, CLYDE_EYES}clydeState;
enum InkyStates{INKY_WAIT, INKY_START, INKY_CHASE, INKY_SCATTER, INKY_SCARED, INKY_EYES}inkyState;
enum PinkyStates{PINKY_WAIT, PINKY_START, PINKY_CHASE, PINKY_SCATTER, PINKY_SCARED, PINKY_EYES}pinkyState;
enum JoystickStates{RIGHT, LEFT, UP, DOWN, IDLE}joystickState;
enum GhostStates{CHASE, SCATTER, SCARED}ghostState;
unsigned char joystick;
unsigned char player_1_send[4];
unsigned char player_1_data;
unsigned char player_2_send[4];
unsigned char pacman_send[13];
unsigned char game_send[13];
unsigned char game_send_data;
unsigned char pacman_send_data;
unsigned char blinky_send_data;
unsigned char clyde_send_data;
unsigned char pinky_send_data;
unsigned char inky_send_data;
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
Character pacman;
Character blinky;
Character pinky;
Character inky;
Character clyde;

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
			USART_Send0(player_2_send[i]);
		}
		player_2_data == 0x00;
	}
}




void TransmitGraphics()
{
	if(game_send_data == 0x01)
	{
		//transmit player 1 data
		for(int i=0; i<13; i++)
		{
			USART_Send1(game_send[i]);
		}
		game_send_data == 0x00;
	}

	//give some time between the next transmit
	for(int i=0; i<50; i++)
	{
		//just here for spacing
	}
	if(pacman_send_data == 0x01)
	{
		//transmit player 1 data
		for(int i=0; i<13; i++)
		{
			USART_Send1(pacman_send[i]);
		}
		pacman_send_data == 0x00;
	}

	//give some time between the next transmit
	for(int i=0; i<50; i++)
	{
		//just here for spacing
	}
	if(blinky_send_data == 0x01)
	{
		//transmit player 1 data
		for(int i=0; i<13; i++)
		{
			USART_Send1(blinky_send[i]);
		}
		blinky_send_data == 0x00;
	}

		//give some time between the next transmit
	for(int i=0; i<50; i++)
	{
		//just here for spacing
	}
	if(clyde_send_data == 0x01)
	{
		//transmit player 1 data
		for(int i=0; i<13; i++)
		{
			USART_Send1(clyde_send[i]);
		}
		clyde_send_data == 0x00;
	}

	//give some time between the next transmit
	for(int i=0; i<50; i++)
	{
		//just here for spacing
	}
	if(inky_send_data == 0x01)
	{
		//transmit player 1 data
		for(int i=0; i<13; i++)
		{
			USART_Send1(inky_send[i]);
		}
		inky_send_data == 0x00;
	}

	//give some time between the next transmit
	for(int i=0; i<50; i++)
	{
		//just here for spacing
	}
	if(pinky_send_data == 0x01)
	{
		//transmit player 1 data
		for(int i=0; i<13; i++)
		{
			USART_Send1(pinky_send[i]);
		}
		pinky_send_data == 0x00;
	}

		//give some time between the next transmit
	for(int i=0; i<50; i++)
	{
		//just here for spacing
	}
	if(ate_pellet != 0)
	{
		//transmit player 1 data
		USART_Send1(0x22);
		USART_Send1(0x05);
		USART_Send1((unsigned char)(pacman.back_tile_x));
		USART_Send1((unsigned char)(pacman.back_tile_y));
		USART_Send1(0x24)

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
			else if(blinkyState == BLINKY_EYES || clydeState == CLYDE_EYES || pinkyState == PINKY_EYES || inkyState == INKY_EYES)
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






//{PACMAN_WAIT, PACMAN_START, PACMAN_PLAY, PACMAN_POWERUP}pacmanState;
void PacmanSM()
{
	switch (pacmanState)
	{
	case PACMAN_WAIT:
	 	if(game_start == 0x01)
		 {
			 pacmanState = PACMAN_START;
		 }
		 pacman_send_data = 0x00;
		break;
	
	case PACMAN_START:
		if(reset == 0x01)
		{
			pacmanState = PACMAN_WAIT;
		}
		else if(game_start == 0x00)
		{
			pacmanState = PACMAN_PLAY;
			//initialize pacman
			initialize_pacman(&pacman);
		}
		break;

	case PACMAN_PLAY:
		if(reset == 0x01)
		{
			pacmanState = PACMAN_WAIT;
		}
		if(pacman_send_data == 0x00)
		{
			//play his turn and update the score
			unsigned int newScore = pacman_turn(&pacman, joystick);
			if(newScore == 10)
			{
				ate_pellet = 0x01;
			}
			if else(newScore == 50)
			{
				ate_pellet = 0x02;
				//pacmanState = PACMAN_POWERUP;
			}

			else
			{
				ate_pellet = 0x00;
			}
			score += newScore;
			//update graphics
			send_data_pacman(&pacman, pacman_send);
			pacman_send_data = 0x01;
		}
		break;

	case PACMAN_POWERUP:
		break;

	case PACMAN_DIE:
		if(pacman_died == 0x01)
		{
			pacman_died(&pacman, pacman_send);
			pacman_died = 0x00;

		}
		break;
	default:
		break;
	}
}

//BlinkyStates{BLINKY_WAIT, BLINKY_START, BLINKY_CHASE, BLINKY_SCATTER, BLINKY_SCARED, BLINKY_EYES}blinkyState
void BlinkySM()
{
	switch(blinkyState)
	{
		case BLINKY_WAIT:
			if(game_start == 0x01)
			{
				blinkyState = BLINKY_START;
			}
			blinky_send_data = 0x00;
			break;

		case BLINKY_START:
			initialize_blinky(&blinky);
			if(reset == 0x01)
			{
				blinkyState = BLINKY_WAIT;
			}

			if(ghostState == CHASE)
			{
				blinkyState = BLINKY_CHASE;
			}

			else if(ghostState == SCATTER)
			{
			 	blinky.target_tile_x = 26;
				blinky.target_tile_y = 1;
				blinkyState = BLINKY_SCATTER;
			}

			else if(ghostState == SCARED)
			{
				blinkyState = BLINKY_SCARED;
			}

			break;

		case BLINKY_CHASE:
			if(reset == 0x01)
			{
				blinkyState = BLINKY_WAIT;
			}


			if(ghostState == SCATTER)
			{
			 	blinky.target_tile_x = 26;
				blinky.target_tile_y = 1;
				blinkyState = BLINKY_SCATTER;
			}

			else if(ghostState == SCARED)
			{
				blinkyState = BLINKY_SCARED;
			}


			if(blinky_send_data == 0x00)
			{
				ghost_regular(&blinky);
				ghost_chase(&blinky, &pacman);
				ghost_turn(&blinky);
				if(pacman_died == 0x00)
				{
					pacman_died = caught_pacman(&blinky, &pacman);
				}
				
				send_data_ghost(&blinky, blinky_send, 0x30);
				blinky_send_data = 0x01;				
			}



			break;

		case BLINKY_SCATTER:
			if(reset == 0x01)
			{
				blinkyState = BLINKY_WAIT;
			}

			if(ghostState == CHASE)
			{
				blinkyState = BLINKY_CHASE;
			}

			else if(ghostState == SCARED)
			{
				blinkyState = BLINKY_SCARED;
			}

			if(blinky_send_data == 0x00)
			{
				ghost_turn(&blinky);
				ghost_regular(&blinky);
				if(pacman_died == 0x00)
				{
					pacman_died = caught_pacman(&blinky, &pacman);
				}
				
				send_data_ghost(&blinky, blinky_send, 0x30);
				blinky_send_data = 0x01;

			}


			break;

		case BLINKY_SCARED:
			if(reset == 0x01)
			{
				blinkyState = BLINKY_WAIT;
			}

			if(ghostState == CHASE)
			{
				blinkyState = BLINKY_CHASE;
			}

			else if(ghostState == SCATTER)
			{
			 	blinky.target_tile_x = 26;
				blinky.target_tile_y = 1;
				blinkyState = BLINKY_SCATTER;
			}
			if(blinky_send_data == 0x00)
			{
				ghost_scared(&blinky)
				ghost_turn(&blinky);
				//ghost dies here
				/*if(pacman_died == 0x00)
				{
					pacman_died = caught_pacman(&blinky, &pacman);
				}*/
				
				send_data_ghost(&blinky, blinky_send, 0x70);
				blinky_send_data = 0x01;
			}

			break;
		
		case BLINKY_EYES:
			break;

		default:
			break;
	}
}





//BlinkyStates{BLINKY_WAIT, BLINKY_START, BLINKY_CHASE, BLINKY_SCATTER, BLINKY_SCARED, BLINKY_EYES}blinkyState
void ClydeSM()
{
	switch(clydeState)
	{
		case CLYDE_WAIT:
			if(game_start == 0x01)
			{
				clydeState = CLYDE_START;
			}
			clyde_send_data = 0x00;
			break;

		case CLYDE_START:
			initialize_clyde(&clyde);
			if(reset == 0x01)
			{
				clydeState = CLYDE_WAIT;
			}

			if(ghostState == CHASE)
			{
				clydeState = CLYDE_CHASE;
			}

			else if(ghostState == SCATTER)
			{
			 	clyde.target_tile_x = 1;
				clyde.target_tile_y = 29;
				clydeState = CLYDE_SCATTER;
			}

			else if(ghostState == SCARED)
			{
				clydeState = CLYDE_SCARED;
			}

			break;

		case CLYDE_CHASE:
			if(reset == 0x01)
			{
				clydeState = CLYDE_WAIT;
			}


			if(ghostState == SCATTER)
			{
			 	clyde.target_tile_x = 1;
				clyde.target_tile_y = 29;
				clydeState = CLYDE_SCATTER;
			}

			else if(ghostState == SCARED)
			{
				clydeState = CLYDE_SCARED;
			}


			if(clyde_send_data == 0x00)
			{
				ghost_regular(&clyde);
				ghost_chase(&clyde, &pacman);
				ghost_turn(&clyde);
				if(pacman_died == 0x00)
				{
					pacman_died = caught_pacman(&clyde, &pacman);
				}
				
				send_data_ghost(&clyde, clyde_send, 0x40);
				clyde_send_data = 0x01;				
			}



			break;

		case CLYDE_SCATTER:
			if(reset == 0x01)
			{
				clydeState = CLYDE_WAIT;
			}

			if(ghostState == CHASE)
			{
				clydeState = CLYDE_CHASE;
			}

			else if(ghostState == SCARED)
			{
				clydeState = CLYDE_SCARED;
			}

			if(clyde_send_data == 0x00)
			{
				ghost_regular(&clyde);
				ghost_turn(&clyde);
				if(pacman_died == 0x00)
				{
					pacman_died = caught_pacman(&clyde, &pacman);
				}
				
				send_data_ghost(&clyde, clyde_send, 0x40);
				clyde_send_data = 0x01;

			}


			break;

		case CLYDE_SCARED:
			if(reset == 0x01)
			{
				clydeState = CLYDE_WAIT;
			}

			if(ghostState == CHASE)
			{
				clydeState = CLYDE_CHASE;
			}

			else if(ghostState == SCATTER)
			{
			 	clyde.target_tile_x = 1;
				clyde.target_tile_y = 29;
				clydeState = CLYDE_SCATTER;
			}
			if(clyde_send_data == 0x00)
			{
				ghost_scared(&clyde);
				ghost_turn(&clyde);
				//ghost dies here
				/*if(pacman_died == 0x00)
				{
					pacman_died = caught_pacman(&blinky, &pacman);
				}*/
				
				send_data_ghost(&clyde, clyde_send, 0x70);
				clyde_send_data = 0x01;
			}

			break;
		
		case CLYDE_EYES:
			break;

		default:
			break;
	}
}

//BlinkyStates{BLINKY_WAIT, BLINKY_START, BLINKY_CHASE, BLINKY_SCATTER, BLINKY_SCARED, BLINKY_EYES}blinkyState
void InkySM()
{
	switch(inkyState)
	{
		case INKY_WAIT:
			if(game_start == 0x01)
			{
				inkyState = INKY_START;
			}
			inky_send_data = 0x00;
			break;

		case INKY_START:
			initialize_inky(&inky);
			if(reset == 0x01)
			{
				inkyState = INKY_WAIT;
			}

			if(ghostState == CHASE)
			{
				inkyState = INKY_CHASE;
			}

			else if(ghostState == SCATTER)
			{
			 	inky.target_tile_x = 26;
				inky.target_tile_y = 29;
				inkyState = INKY_SCATTER;
			}

			else if(ghostState == SCARED)
			{
				inkyState = INKY_SCARED;
			}

			break;

		case INKY_CHASE:
			if(reset == 0x01)
			{
				inkyState = INKY_WAIT;
			}


			if(ghostState == SCATTER)
			{
			 	inky.target_tile_x = 26;
				inky.target_tile_y = 29;
				inkyState = INKY_SCATTER;
			}

			else if(ghostState == SCARED)
			{
				inkyState = INKY_SCARED;
			}


			if(inky_send_data == 0x00)
			{
				ghost_regular(&inky);
				ghost_chase(&inky, &pacman);
				ghost_turn(&inky);
				if(pacman_died == 0x00)
				{
					pacman_died = caught_pacman(&inky, &pacman);
				}
				
				send_data_ghost(&inky, inky_send, 0x50);
				inky_send_data = 0x01;				
			}



			break;

		case INKY_SCATTER:
			if(reset == 0x01)
			{
				inkyState = INKY_WAIT;
			}

			if(ghostState == CHASE)
			{
				inkyState = INKY_CHASE;
			}

			else if(ghostState == SCARED)
			{
				inkyState = INKY_SCARED;
			}

			if(inky_send_data == 0x00)
			{
				ghost_regular(&inky);
				ghost_turn(&inky);
				if(pacman_died == 0x00)
				{
					pacman_died = caught_pacman(&inky, &pacman);
				}
				
				send_data_ghost(&inky, inky_send, 0x50);
				inky_send_data = 0x01;

			}


			break;

		case INKY_SCARED:
			if(reset == 0x01)
			{
				inkyState = INKY_WAIT;
			}

			if(ghostState == CHASE)
			{
				inkyState = INKY_CHASE;
			}

			else if(ghostState == SCATTER)
			{
			 	inky.target_tile_x = 26;
				inky.target_tile_y = 29;
				inkyState = INKY_SCATTER;
			}
			if(inky_send_data == 0x00)
			{
				ghost_scared(&inky);
				ghost_turn(&inky);
				//ghost dies here
				/*if(pacman_died == 0x00)
				{
					pacman_died = caught_pacman(&blinky, &pacman);
				}*/
				
				send_data_ghost(&inky, inky_send, 0x70);
				inky_send_data = 0x01;
			}

			break;
		
		case INKY_EYES:
			break;

		default:
			break;
	}
}



//BlinkyStates{BLINKY_WAIT, BLINKY_START, BLINKY_CHASE, BLINKY_SCATTER, BLINKY_SCARED, BLINKY_EYES}blinkyState
void PinkySM()
{
	switch(pinkyState)
	{
		case PINKY_WAIT:
			if(game_start == 0x01)
			{
				pinkyState = PINKY_START;
			}
			pinky_send_data = 0x00;
			break;

		case PINKY_START:
			initialize_pinky(&pinky);
			if(reset == 0x01)
			{
				pinkyState = PINKY_WAIT;
			}

			if(ghostState == CHASE)
			{
				pinkyState = PINKY_CHASE;
			}

			else if(ghostState == SCATTER)
			{
			 	pinky.target_tile_x = 1;
				pinky.target_tile_y = 1;
				pinkyState = PINKY_SCATTER;
			}

			else if(ghostState == SCARED)
			{
				pinkyState = PINKY_SCARED;
			}

			break;

		case PINKY_CHASE:
			if(reset == 0x01)
			{
				pinkyState = PINKY_WAIT;
			}


			if(ghostState == SCATTER)
			{
			 	pinky.target_tile_x = 1;
				pinky.target_tile_y = 1;
				pinkyState = PINKY_SCATTER;
			}

			else if(ghostState == SCARED)
			{
				pinkyState = PINKY_SCARED;
			}


			if(pinky_send_data == 0x00)
			{
				ghost_regular(&pinky);
				ghost_chase(&pinky, &pacman);
				ghost_turn(&pinky);
				if(pacman_died == 0x00)
				{
					pacman_died = caught_pacman(&pinky, &pacman);
				}
				
				send_data_ghost(&pinky, pinky_send, 0x60);
				pinky_send_data = 0x01;				
			}



			break;

		case PINKY_SCATTER:
			if(reset == 0x01)
			{
				pinkyState = PINKY_WAIT;
			}

			if(ghostState == CHASE)
			{
				pinkyState = PINKY_CHASE;
			}

			else if(ghostState == SCARED)
			{
				pinkyState = PINKY_SCARED;
			}

			if(pinky_send_data == 0x00)
			{
				ghost_regular(&pinky);
				ghost_turn(&pinky);
				if(pacman_died == 0x00)
				{
					pacman_died = caught_pacman(&pinky, &pacman);
				}
				
				send_data_ghost(&pinky, pinky_send, 0x60);
				pinky_send_data = 0x01;

			}


			break;

		case PINKY_SCARED:
			if(reset == 0x01)
			{
				pinkyState = PINKY_WAIT;
			}

			if(ghostState == CHASE)
			{
				pinkyState = PINKY_CHASE;
			}

			else if(ghostState == SCATTER)
			{
			 	pinky.target_tile_x = 1;
				pinky.target_tile_y = 1;
				pinkyState = PINKY_SCATTER;
			}
			if(pinky_send_data == 0x00)
			{
				ghost_scared(&pinky);
				ghost_turn(&pinky);
				//ghost dies here
				/*if(pacman_died == 0x00)
				{
					pacman_died = caught_pacman(&blinky, &pacman);
				}*/
				
				send_data_ghost(&pinky, pinky_send, 0x70);
				pinky_send_data = 0x01;
			}

			break;
		
		case PINKY_EYES:
			break;

		default:
			break;
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
			gameState = GAME_PLAY;
			//init game
			game_send[0] = 0x22;

			game_send[1] = 0x03;
			for (int i = 0; i < 12; i++)
			{
				game_send[i] = 0x00;
			}
			game_send[12] = 0x24;
			game_start = 0x00;
			game_send_data = 0x01;
			game_count = 0x00;
			ghostState = SCATTER;
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
			highscore = get_highscore();
			if(pacman_died)
			{
				pacman_lives--;
			}

			if(pacman_lives <= 0)
			{
				gameState = GAME_LOST;
			}

			game_count++;
			if(game_count == 70 )
			{
				//change from scatter to chase
				ghostState = CHASE;
			}

			if(game_count == 270)
			{
				//set count back to zero and back to scatter mode
				ghostState = SCATTER;
				game_count = 0;
			}
			
			TransmitGraphics()
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
		game_send_data 0x00;
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
			//draw map
			game_send[0] = 0x22;

			game_send[1] = 0x02;
			for (int i = 0; i < 12; i++)
			{
				game_send[i] = 0x00;
			}
			game_send[12] = 0x24;
			game_send_data = 0x01;
			//initialize the map
			initiate_map();
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
	pacmanState = PACMAN_WAIT;
	blinkyState = BLINKY_WAIT;
	clydeState = CLYDE_WAIT;
	inkyState = INKY_WAIT;
	pinkyState = PINKY_STATE;
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

