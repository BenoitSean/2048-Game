#ifndef BLOCK_H
#define BLOCK_H


class Block {
	public:
		int value;
		int position;
		int combined;
		/*
		0  1  2  3 
		4  5  6  7
		8  9  10 11
		12 13 14 15 */
		Block(int val, int pos);
};
void combine(Block* moved_block, Block* stationary_block);


#endif // BlOCK_H