#ifndef GHOST_H
#define GHOST_H


#include "character.h"




void initialize_blinky(Character *blinky)
{
    int back_tile_x = 13; //column
	int back_tile_y = 11; //row
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
	unsigned char direct = 'L'; //can be 'U', 'R', 'D', 'L', or 'I'
    unsigned char prev_direct = direct;
	int index = 0; //index for animation frame
	int max_index = 2; //how many frames in animation cycle
	//previous location for graphics
	int prev_boarder_x[4];
    prev_boarder_x[0] = boarder_x[0];
    prev_boarder_x[1] = boarder_x[1];
    prev_boarder_x[2] = boarder_x[2];
    prev_boarder_x[3] = boarder_x[3]; 
	int prev_boarder_y[4];
    prev_boarder_y[0] = boarder_y[0];
    prev_boarder_y[1] = boarder_y[1];
    prev_boarder_y[2] = boarder_y[2];
    prev_boarder_y[3] = boarder_y[3];
	int target_tile_x = 26; //for ghosts
	int target_tile_y = 1; //for ghosts
    initialize_character(blinky, back_tile_x, back_tile_y, boarder_x, boarder_y, direct, index, max_index, prev_boarder_x, prev_boarder_y, prev_direct, target_tile_x, target_tile_y, 'B');
}


void initialize_clyde(Character *clyde)
{
    int back_tile_x = 15; //column
	int back_tile_y = 14; //row
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
	unsigned char direct = 'U'; //can be 'U', 'R', 'D', 'L', or 'I'
    unsigned char prev_direct = direct;
	int index = 0; //index for animation frame
	int max_index = 2; //how many frames in animation cycle
	//previous location for graphics
	int prev_boarder_x[4];
    prev_boarder_x[0] = boarder_x[0];
    prev_boarder_x[1] = boarder_x[1];
    prev_boarder_x[2] = boarder_x[2];
    prev_boarder_x[3] = boarder_x[3]; 
	int prev_boarder_y[4];
    prev_boarder_y[0] = boarder_y[0];
    prev_boarder_y[1] = boarder_y[1];
    prev_boarder_y[2] = boarder_y[2];
    prev_boarder_y[3] = boarder_y[3];
	int target_tile_x = 1; //for ghosts
	int target_tile_y = 29; //for ghosts
    initialize_character(clyde, back_tile_x, back_tile_y, boarder_x, boarder_y, direct, index, max_index, prev_boarder_x, prev_boarder_y, prev_direct, target_tile_x, target_tile_y, 'C');
}


void initialize_inky(Character *inky)
{
    int back_tile_x = 11; //column
	int back_tile_y = 14; //row
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
	unsigned char direct = 'U'; //can be 'U', 'R', 'D', 'L', or 'I'
    unsigned char prev_direct = direct;
	int index = 0; //index for animation frame
	int max_index = 2; //how many frames in animation cycle
	//previous location for graphics
	int prev_boarder_x[4];
    prev_boarder_x[0] = boarder_x[0];
    prev_boarder_x[1] = boarder_x[1];
    prev_boarder_x[2] = boarder_x[2];
    prev_boarder_x[3] = boarder_x[3]; 
	int prev_boarder_y[4];
    prev_boarder_y[0] = boarder_y[0];
    prev_boarder_y[1] = boarder_y[1];
    prev_boarder_y[2] = boarder_y[2];
    prev_boarder_y[3] = boarder_y[3];
	int target_tile_x = 26; //for ghosts
	int target_tile_y = 29; //for ghosts
    initialize_character(inky, back_tile_x, back_tile_y, boarder_x, boarder_y, direct, index, max_index, prev_boarder_x, prev_boarder_y, prev_direct, target_tile_x, target_tile_y, 'I');
}

void initialize_pinky(Character *pinky)
{
    int back_tile_x = 13; //column
	int back_tile_y = 14; //row
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
	unsigned char direct = 'D'; //can be 'U', 'R', 'D', 'L', or 'I'
    unsigned char prev_direct = direct;
	int index = 0; //index for animation frame
	int max_index = 2; //how many frames in animation cycle
	//previous location for graphics
	int prev_boarder_x[4];
    prev_boarder_x[0] = boarder_x[0];
    prev_boarder_x[1] = boarder_x[1];
    prev_boarder_x[2] = boarder_x[2];
    prev_boarder_x[3] = boarder_x[3]; 
	int prev_boarder_y[4];
    prev_boarder_y[0] = boarder_y[0];
    prev_boarder_y[1] = boarder_y[1];
    prev_boarder_y[2] = boarder_y[2];
    prev_boarder_y[3] = boarder_y[3];
	int target_tile_x = 1; //for ghosts
	int target_tile_y = 1; //for ghosts
    initialize_character(pinky, back_tile_x, back_tile_y, boarder_x, boarder_y, direct, index, max_index, prev_boarder_x, prev_boarder_y, prev_direct, target_tile_x, target_tile_y, 'P');
}

void ghost_turn(Character *ghost)
{

    //try to move counter clock-wise 

    int shortest_distance = 1000;
    int dist;
    unsigned char direct;
    //start at up and work towards
    if(((map_collision(-1, 'U', ghost) != 'W') || (map_collision(-1, 'U', ghost) != 'T')) && (ghost->direct != 'D') )
    {
        int temp_x = ghost->back_tile_x;
        int temp_y = ghost->back_tile_y - 1;
        int dist_x = ghost->target_tile_x - temp_x;
        if(dist_x < 0)
        {
            dist_x *= -1;
        }

        int dist_y = ghost->target_tile_y - temp_y;
        if(dist_y < 0)
        {
            dist_y *= -1;
        }
        int temp_shortest = (dist_x * dist_x) + (dist_y * dist_y);

        if(temp_shortest < shortest_distance)
        {
            shortest_distance = temp_shortest;
            dist = -1;
            direct = 'U';
        }

    }

    else if(((map_collision(1, 'R', ghost) != 'W') || (map_collision(1, 'R', ghost) != 'T')) && (ghost->direct != 'L') )
    {
        int temp_x = ghost->back_tile_x + 1;
        int temp_y = ghost->back_tile_y;
        int dist_x = ghost->target_tile_x - temp_x;
        if(dist_x < 0)
        {
            dist_x *= -1;
        }

        int dist_y = ghost->target_tile_y - temp_y;
        if(dist_y < 0)
        {
            dist_y *= -1;
        }
        int temp_shortest = (dist_x * dist_x) + (dist_y * dist_y);

        if(temp_shortest < shortest_distance)
        {
            shortest_distance = temp_shortest;
            dist = 1;
            direct = 'R';
        }
    } 

    else if(((map_collision(1, 'D', ghost) != 'W') || (map_collision(1, 'D', ghost) != 'T')) && (ghost->direct != 'U') )
    {
        int temp_x = ghost->back_tile_x;
        int temp_y = ghost->back_tile_y + 1;
        int dist_x = ghost->target_tile_x - temp_x;
        if(dist_x < 0)
        {
            dist_x *= -1;
        }

        int dist_y = ghost->target_tile_y - temp_y;
        if(dist_y < 0)
        {
            dist_y *= -1;
        }
        int temp_shortest = (dist_x * dist_x) + (dist_y * dist_y);

        if(temp_shortest < shortest_distance)
        {
            shortest_distance = temp_shortest;
            dist = 1;
            direct = 'D';
        }
    } 

    else if(((map_collision(-1, 'L', ghost) != 'W') || (map_collision(-1, 'L', ghost) != 'T')) && (ghost->direct != 'R'))
    {
        int temp_x = ghost->back_tile_x - 1;
        int temp_y = ghost->back_tile_y;
        int dist_x = ghost->target_tile_x - temp_x;
        if(dist_x < 0)
        {
            dist_x *= -1;
        }

        int dist_y = ghost->target_tile_y - temp_y;
        if(dist_y < 0)
        {
            dist_y *= -1;
        }
        int temp_shortest = (dist_x * dist_x) + (dist_y * dist_y);

        if(temp_shortest < shortest_distance)
        {
            shortest_distance = temp_shortest;
            dist = -1;
            direct = 'L';
        }
    } 


        //move to the new location
        update_position(dist, direct, ghost);


}

//change target tile to pacman
void ghost_chase(Character *ghost, Character *pacman)
{
    //target tile is pacman
    if(ghost->name == 'B' || ghost->name  == 'C')
    {
        ghost->target_tile_x = pacman->back_tile_x;
        ghost->target_tile_y = pacman->back_tile_y;
    }

    //target tile is four tiles in front of pacman
    else if(ghost->name == 'P')
    {
        ghost->target_tile_x = pacman->back_tile_x + 4;
        ghost->target_tile_y = pacman->back_tile_y + 4;
    }

    //target tile is four tiles in front of pacman
    else if(ghost->name == 'I')
    {
        ghost->target_tile_x = pacman->back_tile_x + 2;
        ghost->target_tile_y = pacman->back_tile_y + 2;
    }
}

void ghost_scared(Character *ghost)
{
    ghost->max_index = 4;
    ghost->index = 0;
}

//call this when they first enter scared mode or chase mode
void ghost_turn_flip(Character *ghost)
{
    //flip direction 180

    int dist;
    unsigned char direct;
    //start at up and work towards
    if(ghost->direct == 'U')
    {
        dist = 1;
        direct = 'D';
        if(((map_collision(dist, direct, ghost) != 'W') || (map_collision(dist, direct, ghost) != 'T')))
        {
            //move to the new location
            update_position(dist, direct, ghost);
        }

    }

    else if(ghost->direct == 'R')
    {
        dist = -1;
        direct = 'L';
        if(((map_collision(dist, direct, ghost) != 'W') || (map_collision(dist, direct, ghost) != 'T')))
        {
            //move to the new location
            update_position(dist, direct, ghost);
        }
    } 

    else if(ghost->direct == 'D')
    {
        dist = -1;
        direct = 'U';
        if(((map_collision(dist, direct, ghost) != 'W') || (map_collision(dist, direct, ghost) != 'T')))
        {
            //move to the new location
            update_position(dist, direct, ghost);
        }
    } 

    else if(ghost->direct == 'L')
    {
        dist = 1;
        direct = 'R';
        if(((map_collision(dist, direct, ghost) != 'W') || (map_collision(dist, direct, ghost) != 'T')))
        {
            //move to the new location
            update_position(dist, direct, ghost);
        }
    } 

        

}




unsigned char caught_pacman(Character *ghost, Character *pacman)
{
    if((ghost->back_tile_x == pacman->back_tile_x) && (ghost->back_tile_y == pacman->back_tile_y))
    {
        return 0x01; 
    }
        

    else
    {
        return 0x00;
    }
}

#endif //GHOST_H