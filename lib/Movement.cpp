#include "Block.h"
#include "Board.h"
#include "stdio.h"
#include "stdlib.h"

void move_block_up(Board main_board, int pos){
    main_board.changed = 0;
    int next_pos;
    while(pos > 3){
        next_pos= pos-4;
        if(main_board.isEmpty(next_pos)){
            main_board.changed = 1;
            main_board.spots[next_pos] = main_board.spots[pos];
            main_board.spots[pos] = NULL; 
            pos = next_pos;
        }
        else if(main_board.isEqual(pos, next_pos)){
            combine(main_board.spots[pos], main_board.spots[next_pos]);
            main_board.spots[pos] = NULL;
            break;
        }
        else{
            break;
        }
    }
}
void move_block_right(Board main_board, int pos){
    main_board.changed = 0;
    int next_pos;
    while(pos % 4 != 3){
        next_pos= pos+1;
        if(main_board.isEmpty(next_pos)){
            main_board.changed = 1;
            main_board.spots[next_pos] = main_board.spots[pos];
            main_board.spots[pos] = NULL; 
            pos = next_pos;
        }
        else if(main_board.isEqual(pos, next_pos)){
            combine(main_board.spots[pos], main_board.spots[next_pos]);
            main_board.spots[pos] = NULL;
            break;
        }
        else{
            break;
        }
    }
}
void move_block_down(Board main_board, int pos){
    main_board.changed = 0;
    int next_pos;
    while(pos < 12){
        next_pos= pos+4;
        if(main_board.isEmpty(next_pos)){
            main_board.changed = 1;
            main_board.spots[next_pos] = main_board.spots[pos];
            main_board.spots[pos] = NULL; 
            pos = next_pos;
        }
        else if(main_board.isEqual(pos, next_pos)){
            combine(main_board.spots[pos], main_board.spots[next_pos]);
            main_board.spots[pos] = NULL;
            break;
        }
        else{
            break;
        }
    }
}
void move_block_left(Board main_board, int pos){
    main_board.changed = 0;
    int next_pos;
    while(pos % 4 != 0){
        next_pos= pos - 1;
        if(main_board.isEmpty(next_pos)){
            main_board.changed = 1;
            main_board.spots[next_pos] = main_board.spots[pos];
            main_board.spots[pos] = NULL; 
            pos = next_pos;
        }
        else if(main_board.isEqual(pos, next_pos)){
            combine(main_board.spots[pos], main_board.spots[next_pos]);
            main_board.spots[pos] = NULL;
            break;
        }
        else{
            break;
        }
    }
}
void move_up(Board main_board){
    for(int i = 4; i < 16; i++){
        if(main_board.spots[i] != NULL){
            move_block_up(main_board, i);
        }
    }
}
void move_right(Board main_board){
    for(int i = 2; i >= 0; i++){
        for(int j = 0; j <= 12; j += 4){
            if(main_board.spots[i+j] != NULL){
                move_block_right(main_board, i + j);
            }
        }
    }
}
void move_down(Board main_board){
    for(int i = 11; i >= 0; i--){
        if(main_board.spots[i] != NULL){
            move_block_down(main_board, i);
        }
    }
}
void move_left(Board main_board){
    for(int i = 1; i <= 3; i++){
        for(int j = 0; j <= 12; j += 4){
            if(main_board.spots[i+j] != NULL){
                move_block_left(main_board, i + j);
            }
        }
    }
}
int move(int direction, Board main_board){//0 = up, 1 = right, 2 = down, 3 =left
    if(direction == 0){
        move_up(main_board);
    }
    else if(direction == 1){
        move_right(main_board);
    }
    else if(direction == 2){
        move_down(main_board);
    }
    else if(direction == 3){
        move_right(main_board);
    }
    else{
        return 0;
    }
    return 1;
}

