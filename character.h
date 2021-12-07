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

void update_pellet(unsigned char location_x, unsigned char location_y)
{
	//a pellet has been eaten
	game_map[location_y][location_x] = 'G';
}


typedef struct Character{
	unsigned char back_tile_x; //column
	unsigned char back_tile_y; //row
	//pixel values for the boarder box for drawing and collisions
	unsigned char boarder_x[4]; //TL -> TR -> BR -> BL
	unsigned char boarder_y[4]; //TL -> TR -> BR ->BL
	unsigned char direct; //can be 'U', 'R', 'D', 'L', or 'I'
	unsigned char index; //index for animation frame
	unsigned char max_index; //how many frames in animation cycle
	//previous location for graphics
	unsigned char prev_boarder_x[4];
	unsigned char prev_boarder_y[4];
	unsigned char target_tile_x; //for ghosts
	unsigned char target_tile_y; //for ghosts


} Character;



void prepare_send_data(Character character, unsigned char data[])
{

}


//get the upper tile for graphics
unsigned char tile_graphics_x(Character character)
{
	return character.boarder_x[0]/8;
}

//get the upper tile offset for graphics
unsigned char tile_offset_graphics_x(Character character)
{
	return character.boarder_x[0]%8;
}

//get the upper tile for graphics
unsigned char tile_graphics_y(Character character)
{
	return character.boarder_y[0]/8;
}

//get the upper tile offset for graphics
unsigned char tile_offset_graphics_y(Character character)
{
	return character.boarder_y[0]%8;
}

//get the upper tile for graphics
unsigned char prev_tile_graphics_x(Character character)
{
	return character.prev_boarder_x[0]/8;
}

//get the upper tile offset for graphics
unsigned char prev_tile_offset_graphics_x(Character character)
{
	return character.prev_boarder_x[0]%8;
}

//get the upper tile for graphics
unsigned char prev_tile_graphics_y(Character character)
{
	return character.prev_boarder_y[0]/8;
}

//get the upper tile offset for graphics
unsigned char prev_tile_offset_graphics_y(Character character)
{
	return character.prev_boarder_y[0]%8;
}

//check for map collisions had to keep it separate for the ghosts
unsigned char map_collision(int dist, Character character){
	unsigned char new_location = game_map[(int)(character.back_tile_y + dist)][(int)(character.back_tile_x + dist)];
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

	//set new values as current		
	for(int i=0; i<4; i++)
	{
		character->boarder_x[i] = (unsigned char)((int)(character->boarder_x[i]) + (dist*8));
	}

	for(int i=0; i<4; i++)
	{
		character->boarder_y[i] = (unsigned char)((int)(character->boarder_y[i]) + (dist*8));
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
