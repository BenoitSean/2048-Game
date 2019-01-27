#include "Block.h"

Block::Block(int val, int pos){
    value = val;
    position = pos;
    combined = 0;
}

void combine(Block* moved_block, Block* stationary_block){
    stationary_block->value *= 2;
    stationary_block->combined = 1;
    delete moved_block;  
}
