#ifndef BOARD_H
#define BOARD_H

#include "Block.h"
#include <vector>

class Board {
	public:
        Block* spots[16];
        std::vector<int> free_spots;
        int changed;
		Board();
        void generate_block();
        int find_free_spots();
        int isEmpty(int pos);
        int isEqual(int pos, int next_pos);
        
};




#endif // BlOCK_H
