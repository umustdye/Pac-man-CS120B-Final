#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <avr/io.h>
#include <avr/eeprom>

void check_highscore(unsigned int score)
{
        //get the highscore
        unsigned int highscore = get_highscore();

        //compare highscore
        if(score > highscore)
        {
                //save score as highscore
                write_highscore();
        }
}


unsigned int get_highscore()
{
        //retrieve highscore, it's a str :(
        //char highscore_str[10] = eeprom_read_word(46);
        unsigned int highscore = eeprom_read_word((unsigned int)46)
        //return highscore as an int
        //return (unsigned int)(highscore_str);
        //return stoi(highscore_str);
        return highscore;
}

void write_highscore(unsigned int score)
{
        //convert int to string

        //write string to memory
        eeprom_write_word(46, (unsigned int)score);
}



#endif //HIGHSCORE_H

