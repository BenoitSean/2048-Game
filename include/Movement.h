#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "Block.h"
#include "Board.h"
#include "stdio.h"
#include "stdlib.h"

void move_block_up(Board main_board, int pos);
void move_block_right(Board main_board, int pos);
void move_block_down(Board main_board, int pos);
void move_block_left(Board main_board, int pos);
void move_up(Board main_board);
void move_right(Board main_board);
void move_down(Board main_board);
void move_left(Board main_board);
int move(int direction, Board main_board);



#endif //MOVEMENT_H