#ifndef __MAP_H__
#define __MAP_H__

#include "blocks.h"
#include <list>

class Map
{
private:
	bool arrange[22][12];
	bool line_status[20];
	std::list<ExtendedBlock> block_list;

public:
	Map();
	~Map();
	void DrawBlock(ExtendedBlock& cur_block, int);
	void DeleteBlock(ExtendedBlock& cur_block);
	void DeleteLine();
	bool IsLineFull();
	bool IsMovable(ExtendedBlock&);
	bool& GetArrangePosition(ExtendedBlock&, int, int);
	bool& GetArrangePosition(ExtendedBlock&, int, int, int&, int&);
};
#endif
