#include "character.h"
#include <stdio.h>

int main() {

    initiate_map();
    draw_map();

    //Test collision function
    Character test_man;
    int back_tile_x = 11; //column
	int back_tile_y = 1; //row
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
	int index = 0; //index for animation frame
	int max_index = 4; //how many frames in animation cycle
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
    initialize_character(&test_man, back_tile_x, back_tile_y, boarder_x, boarder_y, direct, index, max_index, prev_boarder_x, prev_boarder_y, target_tile_x, target_tile_y);

    int dist = -1;
    unsigned char direction = 'L';
    unsigned char test_collision = map_collision(dist, direct, &test_man);

    if(test_collision == 'W')
    {
        printf("\nCollision");
    }

    else
    {
        //update the postion
        update_position(dist, direction, &test_man);
    }

    return 0;
}