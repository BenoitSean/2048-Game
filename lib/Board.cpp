#include "Block.h"
#include "Board.h"
#include "vector"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"



Board::Board(){// board constructor
    for(int i = 0; i <15; i++){
        free_spots.push_back(1);
        spots[i] = NULL;
    }
    generate_block();
}

void Board::generate_block(){//generates block in random free spot on board
    srand(time(NULL));
    int position_picked = rand() % free_spots.size();
    Block * temp = new Block(2, free_spots[position_picked]);
    spots[temp->position] = temp;
}

int  Board::find_free_spots(){
    int avaliable_spot = 0;
    free_spots.clear();
    for(int i = 0; i<16; i++){
        if(spots[i] == NULL){
            free_spots.push_back(i);
            avaliable_spot = 1;
        }
    }
    if(avaliable_spot == 1){
        return 1;
    }
    return 0;
}
int Board::isEmpty(int pos){
    if(spots[pos] == NULL){
        return 1;
    }
    return 0;
}
int Board::isEqual(int pos, int next_pos){
    if(spots[pos]->value == spots[next_pos]->value){
        return 1;
    }
    return 0;
}