#ifndef PACMAN_H
#define PACMAN_H

#include "character.h"


void send_data_pacman(Character *pacman, unsigned char *sendData)
{
    prepare_send_data(pacman, sendData);
    sendData[1] = (unsigned char)(0x04);
}


void initialize_pacman(Character *pacman)
{
    int back_tile_x = 13; //column
	int back_tile_y = 23; //row
	//pixel values for the boarder box for drawing and collisions
	int boarder_x[4]; //TL -> TR -> BR -> BL
    boarder_x[0] = back_tile_x * 8;
    boarder_x[1] = boarder_x[0] + 16;
    boarder_x[2] = boarder_x[1];
    boarder_x[3] = boarder_x[0]; 
	int boarder_y[4]; //TL -> TR -> BR ->BL
    boarder_y[0] = back_tile_y * 8 - 4;
    boarder_y[1] = boarder_y[0];
    boarder_y[2] = boarder_y[0] - 16;
    boarder_y[3] = boarder_y[2];
	unsigned char direct = 'R'; //can be 'U', 'R', 'D', 'L', or 'I'
    unsigned char prev_direct = 'R';
	int index = 0; //index for animation frame
	int max_index = 3; //how many frames in animation cycle
	//previous location for graphics
	int prev_boarder_x[4];
    prev_boarder_x[0] = back_tile_x * 8;
    prev_boarder_x[1] = prev_boarder_x[0] + 16;
    prev_boarder_x[2] = prev_boarder_x[1];
    prev_boarder_x[3] = prev_boarder_x[0]; 
	int prev_boarder_y[4];
    prev_boarder_y[0] = back_tile_y * 8 - 4;
    prev_boarder_y[1] = prev_boarder_y[0];
    prev_boarder_y[2] = prev_boarder_y[0] - 16;
    prev_boarder_y[3] = prev_boarder_y[2];
	int target_tile_x = 0; //for ghosts
	int target_tile_y = 0; //for ghosts
    initialize_character(pacman, back_tile_x, back_tile_y, boarder_x, boarder_y, direct, index, max_index, prev_boarder_x, prev_boarder_y, prev_direct, target_tile_x, target_tile_y, 'M');
}

//return score if earned
//if added points is 50, then it is a super pellet
unsigned char pacman_turn(Character *pacman, unsigned char direct)
{
    //try to move and check for collisions
    if(direct == 'I')
    {

    }

    else{
        int dist = 0;
        switch(direct)
        {
            case 'U':
                dist = -1;
                break;
            case 'R':
                dist = 1;
                break;
            case 'D':
                dist = 1;
                break;
            case 'L':
                dist = -1;
                break;

            default:
                dist = 0;
                break;
            
        }

        //check map for collision
        unsigned char location = map_collision(dist, direct, pacman);
        if(location != 'W')
        {
            //move to the new location
            update_position(dist, direct, pacman);
            //add points if any
            if(location ==  'P')
            {
                return 0x01;
                update_pellet(pacman->back_tile_x, pacman->back_tile_y);
            }

            else if(location == 'S')
            {
                return 0x02;
            }

            else
            {
                return 0x00;
            }

        }

    }
}

void pacman_died(Character *pacman, unsigned char *sendData)
{

    pacman->max_index = 12;
    pacman->index = 0;
    prepare_send_data(pacman, sendData);
    sendData[1] = (unsigned char)(0x0C);
}

void pacman_vibing(Character *pacman)
{
    pacman->max_index = 3;
    pacman->index = 0;
}

#endif //PACMAN_H