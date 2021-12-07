#include "character.h"
#include <stdio.h>

int main() {

    initiate_map();
    //draw_map();

    //Test collision function
    Character test_man;
    test_man.back_tile_x = 11;
    test_man.back_tile_y = 1;
    unsigned char test_collision = map_collision(2, &test_man);

    if(test_collision == 'W')
    {
        printf("\nCollision");
    }

    return 0;
}