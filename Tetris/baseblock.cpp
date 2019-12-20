#include "base.h"
#include "baseblock.h"

Block::Block()
{
	xpos = 10;
	ypos = 2;
	center_xpos = 1;
	center_ypos = 2;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			space[i][j] = false;
}


void Block::InitSpace()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			space[i][j] = false;
}



Block::~Block()
{
	for(int i = 0; i < 4; i++)
		delete[] space[i];
}


