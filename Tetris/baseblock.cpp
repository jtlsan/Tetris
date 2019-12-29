#include "base.h"
#include "baseblock.h"

Block::Block()
{
	xpos = 5;
	ypos = 2;
	center_xpos = 1;
	center_ypos = 2;
}


Block& Block::operator=(Block& ref)
{
	xpos = ref.xpos;
	ypos = ref.ypos;
	center_xpos = ref.center_xpos;
	center_ypos = ref.center_ypos;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			space[i][j] = ref.space[i][j];
	return *this;
}


Block::~Block()
{
	//empty
}





