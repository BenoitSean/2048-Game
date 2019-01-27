#ifndef GAME_H
#define GAME_H

#include "Block.h"
#include "Board.h"
#include "Movement.h"
#include <iostream>


int user_input();
void graphics(Board main_Board);
void find_values();
int start();
int turn(Board main_Board);


#endif // GAME_H