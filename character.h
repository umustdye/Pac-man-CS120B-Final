#ifndef CHARACTER_H
#define CHARACTER_H

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

void initate_map()
{
	for(int i=0; i<31; i++)
	{
		for(int j=0; j<28; j++)
		{
			game_map[i][j] = map_ref[i][j];
		}
	}
}

void update_pellet(unsigned char location_x, unsigned char location_y)
{
	//a pellet has been eaten
	game_map[location_y][location_x] = 'G';
}


typedef struct_character{
	unsigned char back_tile_x; //column
	unsigned char back_tile_y; //row
	//pixel values for the boarder box for drawing and collisions
	unsigned char boarder_x[4]; TL -> TR -> BR -> BL
	unsigned char boarder_y[4]; TL -> TR -> BR ->BL
	unsigned char direct; //can be 'U', 'R', 'D', 'L', or 'I'
	unsigned char index; //index for animation frame
	unsigned char max_index; //how many frames in animation cycle
	//previous location for graphics
	unsigned char prev_boarder_x[4];
	unsigned char prev_boarder_y[4];
	unsigned char target_tile_x; //for ghosts
	unsigned char target_tile_y; //for ghosts


} Character;


//get the upper tile for graphics


//get the upper tile offset for graphics


//check for map collisions had to keep it separate for the ghosts
unsigned char map_collision(int dist, unsigned char direct, Character character)
{
	unsigned char new_location = game_map[character.back_tile_y + dist][character.back_tile_x + dist];
	return new_location;
}




//update boarder box
void update_boarder_box(int dist, unsigned char direct, Character *character)
{
	//set the old currect location as the prev
	for(int i=0; i<4; i++)
	{
		character.prev_boarder_x[i] = character.boarder_x[i];
	}
	
	for(int i=0; i<4; i++)
	{
		character.prev_boarder_y[i] = character.boarder_y[i];
	}

	//set new values as current		
	for(int i=0; i<4; i++)
	{
		character.boarder_x[i] = (unsigned char)((int)(character.boarder_x[i]) + (int)(distance));
	}

	for(int i=0; i<4; i++)
	{
		character.boarder_y[i] = (unsigned char)((int)(character.boarder_y[i]) + (int)(distance));
	}



	//update animation index
	if(character.index < character.max_index){
		character.index++;
	}

	else{
		character.index = 0;
	}


	update_back_tile(direct, character);


	return character;
	
}


void update_back_tile(unsigned char direct, Character *character){
	

}


#endif //CHARACTER_H
