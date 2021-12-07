#ifndef CHARACTER_H
#define CHARACTER_H

#include <stdio.h>

//each element represents a 8px by 8px tile
//'W' -> wall, take up half a tile 4px
//'M' -> monster pen
//'P' -> pellet
//'S' -> super pellet
//'G' -> allowable path
//'T' -> tunnel
unsigned char map_ref[31][28] = {
  {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'},
  {'W', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'W', 'W', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'W'},
  {'W', 'P', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'P', 'W'},
  {'W', 'P', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'P', 'W'},
  {'W', 'S', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'S', 'W'},
  {'W', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'W'},
  {'W', 'P', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'P', 'W'},
  {'W', 'P', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'P', 'W'},
  {'W', 'P', 'P', 'P', 'P', 'P', 'P', 'W', 'W', 'P', 'P', 'P', 'P', 'W', 'W', 'P', 'P', 'P', 'P', 'W', 'W', 'P', 'P', 'P', 'P', 'P', 'P', 'W'},
  {'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'G', 'W', 'W', 'G', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W'},
  {'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'G', 'W', 'W', 'G', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W'},
  {'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W'},
  {'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'G', 'W', 'W', 'W', 'D', 'D', 'W', 'W', 'W', 'G', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W'},
  {'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'G', 'W', 'M', 'M', 'M', 'M', 'M', 'M', 'W', 'G', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W'},
  {'T', 'T', 'T', 'T', 'T', 'T', 'P', 'G', 'G', 'G', 'W', 'M', 'M', 'M', 'M', 'M', 'M', 'W', 'G', 'G', 'G', 'P', 'T', 'T', 'T', 'T', 'T', 'T'},
  {'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'G', 'W', 'M', 'M', 'M', 'M', 'M', 'M', 'W', 'G', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W'},
  {'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'G', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'G', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W'},
  {'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W'},
  {'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'G', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'G', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W'},
  {'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'G', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'G', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W'},
  {'W', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'W', 'W', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'W'},
  {'W', 'P', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'P', 'W'},
  {'W', 'P', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'P', 'W'},
  {'W', 'S', 'P', 'P', 'W', 'W', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'W', 'W', 'P', 'P', 'S', 'W'},
  {'W', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'W'},
  {'W', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'W'},
  {'W', 'P', 'P', 'P', 'P', 'P', 'P', 'W', 'W', 'P', 'P', 'P', 'P', 'W', 'W', 'P', 'P', 'P', 'P', 'W', 'W', 'P', 'P', 'P', 'P', 'P', 'P', 'W'},
  {'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W'},
  {'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W', 'W', 'P', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'P', 'W'},
  {'W', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'W'},
  {'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'}

};

unsigned char game_map[31][28];

void initiate_map()
{
	for(int i=0; i<31; i++)
	{
		for(int j=0; j<28; j++)
		{
			game_map[i][j] = map_ref[i][j];
		}
	}
}

//for testing purposes
void draw_map()
{
	for(int i=0; i<31; i++)
	{
		for(int j=0; j<28; j++)
		{
			printf("%c", game_map[i][j]);
		}
		printf("\n");
	}
}

void update_pellet(int location_x, int location_y)
{
	//a pellet has been eaten
	game_map[location_y][location_x] = 'G';
}


typedef struct Character{
	int back_tile_x; //column
	int back_tile_y; //row
	//pixel values for the boarder box for drawing and collisions
	int boarder_x[4]; //TL -> TR -> BR -> BL
	int boarder_y[4]; //TL -> TR -> BR ->BL
	unsigned char direct; //can be 'U', 'R', 'D', 'L', or 'I'
	int index; //index for animation frame
	int max_index; //how many frames in animation cycle
	//previous location for graphics
	int prev_boarder_x[4];
	int prev_boarder_y[4];
	unsigned char prev_direct;
	int target_tile_x; //for ghosts
	int target_tile_y; //for ghosts


} Character;

void initialize_character(Character *character, 	
	int back_tile_x, int back_tile_y, int boarder_x[4], int boarder_y[4], unsigned char direct,
	int index, int max_index, int prev_boarder_x[4], int prev_boarder_y[4], unsigned char prev_direct,
	int target_tile_x, int target_tile_y)
{
	character->back_tile_x = back_tile_x;
	character->back_tile_y = back_tile_y;
	for(int i=0; i<4; i++)
	{
		character->boarder_x[i] = boarder_x[i];
		character->boarder_y[i] = boarder_y[i];
		character->prev_boarder_x[i] = prev_boarder_x[i];
		character->prev_boarder_y[i] = prev_boarder_y[i];
	}

	character->direct = direct;
	character->prev_direct = prev_direct;
	character->index = index;
	character->max_index = max_index;
	character->target_tile_x = target_tile_x;
	character->target_tile_y = target_tile_y;
}

void prepare_send_data(Character character, unsigned char data[])
{

}


//get the upper tile for graphics
unsigned char tile_graphics_x(Character character)
{
	return (unsigned char)(character.boarder_x[0]/8);
}

//get the upper tile offset for graphics
unsigned char tile_offset_graphics_x(Character character)
{
	return (unsigned char)(character.boarder_x[0]%8);
}

//get the upper tile for graphics
unsigned char tile_graphics_y(Character character)
{
	return (unsigned char)(character.boarder_y[0]/8);
}

//get the upper tile offset for graphics
unsigned char tile_offset_graphics_y(Character character)
{
	return (unsigned char)(character.boarder_y[0]%8);
}

//get the upper tile for graphics
unsigned char prev_tile_graphics_x(Character character)
{
	return (unsigned char)(character.prev_boarder_x[0]/8);
}

//get the upper tile offset for graphics
unsigned char prev_tile_offset_graphics_x(Character character)
{
	return (unsigned char)(character.prev_boarder_x[0]%8);
}

//get the upper tile for graphics
unsigned char prev_tile_graphics_y(Character character)
{
	return (unsigned char)(character.prev_boarder_y[0]/8);
}

//get the upper tile offset for graphics
unsigned char prev_tile_offset_graphics_y(Character character)
{
	return (unsigned char)(character.prev_boarder_y[0]%8);
}

//check for map collisions had to keep it separate for the ghosts
unsigned char map_collision(int dist, unsigned char direct, Character *character){
	unsigned char new_location;
	switch (direct)
	{
	case 'U':
		new_location = game_map[character->back_tile_y + dist][character->back_tile_x];
		break;

	case 'R':
		new_location = game_map[character->back_tile_y][character->back_tile_x + dist];
		break;

	case 'D':
		new_location = game_map[character->back_tile_y + dist][character->back_tile_x];
		break;
	
	case 'L':
		new_location = game_map[character->back_tile_y][character->back_tile_x + dist];
		break;
	default:
		new_location = game_map[character->back_tile_y][character->back_tile_x];
		break;
	}
	
	printf("%c", new_location);
	return new_location;
}


void update_back_tile(int dist, unsigned char direct, Character *character){

	switch(direct)
	{
		case 'U':
				character->back_tile_y = character->back_tile_y + dist;
			break;

		case 'R':
				character->back_tile_x = character->back_tile_x + dist;
			break;

		case 'D':
				character->back_tile_y = character->back_tile_y + dist;
			break;

		case 'L':
				character->back_tile_x = character->back_tile_x + dist;
			break;

		default:
			break;
	}

}


void rotate_character(Character *character)
{
		//check and see if pacman flipped directions
	if(character->prev_direct != character->direct)
	{
		switch(character->prev_direct)
		{
			case 'U':
				switch (character->direct)
				{
					case 'R':
						//cw
						character->boarder_x[0] = character->boarder_x[0] + 16;
						character->boarder_y[0] = character->boarder_y[0];
						character->boarder_x[1] = character->boarder_x[1];
						character->boarder_y[1] = character->boarder_y[1] + 16;
						character->boarder_x[2] = character->boarder_x[2] - 16;
						character->boarder_y[2] = character->boarder_y[2];
						character->boarder_x[3] = character->boarder_x[3];
						character->boarder_y[3] = character->boarder_y[3] - 16;
						break;
					case 'D':
						character->boarder_x[0] = character->boarder_x[0] + 16;
						character->boarder_y[0] = character->boarder_y[0] + 16;
						character->boarder_x[1] = character->boarder_x[1] - 16;
						character->boarder_y[1] = character->boarder_y[1] + 16;
						character->boarder_x[2] = character->boarder_x[2] - 16;
						character->boarder_y[2] = character->boarder_y[2] - 16;
						character->boarder_x[3] = character->boarder_x[3] + 16;
						character->boarder_y[3] = character->boarder_y[3] - 16;
						break;	
					case 'L':
						//ccw
						character->boarder_x[0] = character->boarder_x[0];
						character->boarder_y[0] = character->boarder_y[0] + 16;
						character->boarder_x[1] = character->boarder_x[1] - 16;
						character->boarder_y[1] = character->boarder_y[1];
						character->boarder_x[2] = character->boarder_x[2];
						character->boarder_y[2] = character->boarder_y[2] - 16;
						character->boarder_x[3] = character->boarder_x[3] + 16;
						character->boarder_y[3] = character->boarder_y[3];
						break;

					default:
						break;
				}
				break;
			case 'R':
							switch (character->direct)
				{
					case 'D':
						//cw
						character->boarder_x[0] = character->boarder_x[0] + 16;
						character->boarder_y[0] = character->boarder_y[0];
						character->boarder_x[1] = character->boarder_x[1];
						character->boarder_y[1] = character->boarder_y[1] + 16;
						character->boarder_x[2] = character->boarder_x[2] - 16;
						character->boarder_y[2] = character->boarder_y[2];
						character->boarder_x[3] = character->boarder_x[3];
						character->boarder_y[3] = character->boarder_y[3] - 16;
						break;
					case 'L':
						//ccw
						character->boarder_x[0] = character->boarder_x[0] + 16;
						character->boarder_y[0] = character->boarder_y[0] + 16;
						character->boarder_x[1] = character->boarder_x[1] - 16;
						character->boarder_y[1] = character->boarder_y[1] + 16;
						character->boarder_x[2] = character->boarder_x[2] - 16;
						character->boarder_y[2] = character->boarder_y[2] - 16;
						character->boarder_x[3] = character->boarder_x[3] + 16;
						character->boarder_y[3] = character->boarder_y[3] - 16;
						break;
					case 'U':
						character->boarder_x[0] = character->boarder_x[0];
						character->boarder_y[0] = character->boarder_y[0] + 16;
						character->boarder_x[1] = character->boarder_x[1] - 16;
						character->boarder_y[1] = character->boarder_y[1];
						character->boarder_x[2] = character->boarder_x[2];
						character->boarder_y[2] = character->boarder_y[2] - 16;
						character->boarder_x[3] = character->boarder_x[3] + 16;
						character->boarder_y[3] = character->boarder_y[3];
						break;
					default:
						break;
				}
				break;
			case 'D':
				switch (character->direct)
				{
					case 'L':
						//cw
						character->boarder_x[0] = character->boarder_x[0] + 16;
						character->boarder_y[0] = character->boarder_y[0];
						character->boarder_x[1] = character->boarder_x[1];
						character->boarder_y[1] = character->boarder_y[1] + 16;
						character->boarder_x[2] = character->boarder_x[2] - 16;
						character->boarder_y[2] = character->boarder_y[2];
						character->boarder_x[3] = character->boarder_x[3];
						character->boarder_y[3] = character->boarder_y[3] - 16;
						break;
					case 'U':
						//ccw
						character->boarder_x[0] = character->boarder_x[0] + 16;
						character->boarder_y[0] = character->boarder_y[0] + 16;
						character->boarder_x[1] = character->boarder_x[1] - 16;
						character->boarder_y[1] = character->boarder_y[1] + 16;
						character->boarder_x[2] = character->boarder_x[2] - 16;
						character->boarder_y[2] = character->boarder_y[2] - 16;
						character->boarder_x[3] = character->boarder_x[3] + 16;
						character->boarder_y[3] = character->boarder_y[3] - 16;
						break;
					case 'R':
						character->boarder_x[0] = character->boarder_x[0];
						character->boarder_y[0] = character->boarder_y[0] + 16;
						character->boarder_x[1] = character->boarder_x[1] - 16;
						character->boarder_y[1] = character->boarder_y[1];
						character->boarder_x[2] = character->boarder_x[2];
						character->boarder_y[2] = character->boarder_y[2] - 16;
						character->boarder_x[3] = character->boarder_x[3] + 16;
						character->boarder_y[3] = character->boarder_y[3];
						break;
					default:
						break;
				}
				break;
			case 'L':
				switch (character->direct)
				{
					case 'U':
						//cw
						character->boarder_x[0] = character->boarder_x[0] + 16;
						character->boarder_y[0] = character->boarder_y[0];
						character->boarder_x[1] = character->boarder_x[1];
						character->boarder_y[1] = character->boarder_y[1] + 16;
						character->boarder_x[2] = character->boarder_x[2] - 16;
						character->boarder_y[2] = character->boarder_y[2];
						character->boarder_x[3] = character->boarder_x[3];
						character->boarder_y[3] = character->boarder_y[3] - 16;
						break;
					case 'R':
						//ccw
						character->boarder_x[0] = character->boarder_x[0] + 16;
						character->boarder_y[0] = character->boarder_y[0] + 16;
						character->boarder_x[1] = character->boarder_x[1] - 16;
						character->boarder_y[1] = character->boarder_y[1] + 16;
						character->boarder_x[2] = character->boarder_x[2] - 16;
						character->boarder_y[2] = character->boarder_y[2] - 16;
						character->boarder_x[3] = character->boarder_x[3] + 16;
						character->boarder_y[3] = character->boarder_y[3] - 16;
						break;
					case 'D':
						character->boarder_x[0] = character->boarder_x[0];
						character->boarder_y[0] = character->boarder_y[0] + 16;
						character->boarder_x[1] = character->boarder_x[1] - 16;
						character->boarder_y[1] = character->boarder_y[1];
						character->boarder_x[2] = character->boarder_x[2];
						character->boarder_y[2] = character->boarder_y[2] - 16;
						character->boarder_x[3] = character->boarder_x[3] + 16;
						character->boarder_y[3] = character->boarder_y[3];
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
	}
}


//update position
void update_box(int dist, unsigned char direct, Character *character)
{
	//set the old currect location as the prev
	for(int i=0; i<4; i++)
	{
		character->prev_boarder_x[i] = character->boarder_x[i];
	}
	
	for(int i=0; i<4; i++)
	{
		character->prev_boarder_y[i] = character->boarder_y[i];
	}
	
	//rotate character if needed
	rotate_character(character);
	//set new values as current	
	switch (direct)
	{
	case 'U':
		for(int i=0; i<4; i++)
		{
			character->boarder_y[i] = ((character->boarder_y[i]) + (dist*8));
		}
		break;

	case 'R':
		for(int i=0; i<4; i++)
		{
			character->boarder_x[i] = ((character->boarder_x[i]) + (dist*8));
		}

		break;

	case 'D':
		for(int i=0; i<4; i++)
		{
			character->boarder_y[i] = ((character->boarder_y[i]) + (dist*8));
		}
		break;

	case 'L':
		for(int i=0; i<4; i++)
		{
			character->boarder_x[i] = ((character->boarder_x[i]) + (dist*8));
		}

		break;
	
	default:
		break;
	}	



	//update animation index
	if(character->index < character->max_index){
		character->index++;
	}

	else{
		character->index = 0;
	}


	update_back_tile(dist, direct, character);
	
}




//update position if no collision or update direction if idle
void update_position(int dist, unsigned char direct, Character *character)
{
	character->prev_direct = character->direct;
	character->direct = direct;
	if(direct == 'I')
	{
		
	}

	else
	{
		update_box(dist, direct, character);
	}
}


#endif //CHARACTER_H
