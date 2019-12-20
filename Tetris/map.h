#ifndef __MAP_H__
#define __MAP_H__

#include "blocks.h"

class Map
{
private:
	bool arrange[22][10];
public:
	Map();
	~Map();
	void Draw(ExtendedBlock& cur_block);
	void DeleteBlock(ExtendedBlock& cur_block);
	void DeleteLine();
};
#endif
