#include "character.h"
#include "pacman.h"
#include "ghost.h"
#include <stdio.h>

int main() {

    initiate_map();
    draw_map();
    unsigned int score = 0;

    //Test collision function
    Character pacman;
    initialize_pacman(&pacman);
    
    

    int dist = -1;
    unsigned char direct = 'L';
    
    unsigned char if_pellet = pacman_turn(&pacman, direct);

    if(if_pellet == 0x01)
    {
        score += 10;
    }

    else if(if_pellet == 0x02)
    {
        score += 50;
    }
 
    //printf("%d", score);

    unsigned char data[13];
    send_data(&pacman, data);
    for(int i=0; i<13; i++)
    {
        printf("%d ", data[i]);
    }
    printf("%c ", data[2]);


    return 0;
}