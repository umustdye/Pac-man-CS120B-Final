#ifndef CHARACTER_H
#define CHARACTER_H


//'W' -> entire tile is wall
//'M' -> monster pen
//'P' -> pellet
//'S' -> super pellet
//'0' -> allowable path
//'H' -> offset, wall is half in path 4px
unsigned char map[31][28] = {
  {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
  {'0', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', '0'},
  {'0', 'P', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', 'P', '0', '0', 'P', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', 'P', '0'},
  {'0', 'P', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', 'P', '0', '0', 'P', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', 'P', '0'},
  {'0', 'S', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', 'P', '0', '0', 'P', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', 'S', '0'},
  {'0', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', '0'},
  {'0', 'P', '0', '0', '0', '0', 'P', '0', '0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0', '0', 'P', '0', '0', '0', '0', 'P', '0'},
  {'0', 'P', '0', '0', '0', '0', 'P', '0', '0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0', '0', 'P', '0', '0', '0', '0', 'P', '0'},
  {'0', 'P', 'P', 'P', 'P', 'P', 'P', '0', '0', 'P', 'P', 'P', 'P', '0', '0', 'P', 'P', 'P', 'P', '0', '0', 'P', 'P', 'P', 'P', 'P', 'P', '0'},
  {'0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0'},
  {'0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0'},
  {'0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0'},
  {'0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0'},
  {'0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0'},
  {'0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0'},
  {'0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0'},
  {'0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0'},
  {'0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0'},
  {'0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0'},
  {'0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', '0'},
  {'0', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', '0', '0', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', '0'},
  {'0', 'P', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', 'P', '0', '0', 'P', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', 'P', '0'},
  {'0', 'P', '0', '0', '0', '0', 'P', '0', '0', '0', '0', '0', 'P', '0', '0', 'P', '0', '0', '0', '0', '0', 'P', '0', '0', '0', '0', 'P', '0'},
  {'0', 'S', 'P', 'P', '0', '0', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', '0', '0', 'P', 'P', 'S', '0'},
  {'0', '0', '0', 'P', '0', '0', 'P', '0', '0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0', '0', 'P', '0', '0', 'P', '0', '0', '0'},
  {'0', '0', '0', 'P', '0', '0', 'P', '0', '0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0', '0', 'P', '0', '0', 'P', '0', '0', '0'},
  {'0', 'P', 'P', 'P', 'P', 'P', 'P', '0', '0', 'P', 'P', 'P', 'P', '0', '0', 'P', 'P', 'P', 'P', '0', '0', 'P', 'P', 'P', 'P', 'P', 'P', '0'},
  {'0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0', '0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0'},
  {'0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0', '0', 'P', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'P', '0'},
  {'0', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', '0'},
  {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}

};



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
unsigned char map_collision(char dist, unsigned char direct, Character character)
{
	
}




//update boarder box
void update_boarder_box(char dist, unsigned char direct, Character *character)
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
		character.boarder_x[i] = (int)(character.boarder_x[i]) + (int)(distance);
	}

	for(int i=0; i<4; i++)
	{
		character.boarder_y[i] = (int)(character.boarder_y[i]) + (int)(distance);
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
