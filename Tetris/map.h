#ifndef __MAP_H__
#define __MAP_H__

#include "blocks.h"
#include <list>
using std::list;
class Map
{
private:
	bool arrange[22][12];
	bool line_status[20];
	list<ExtendedBlock> block_list;

public:
	Map();
	~Map();
	void InitialDraw();
	void DrawBlock(ExtendedBlock& cur_block);
	void DrawCell(Cell&);
	void MoveByArrow(ExtendedBlock&, int);
	void PullDownBlock(ExtendedBlock&);
	//void PullDownCell(Cell&);
	void PullToBottom(ExtendedBlock&);
	void PullCellsToBottom(Cell&, ExtendedBlock& cur_block, int);
	void DeleteBlock(ExtendedBlock& cur_block);
	void DeleteLine(int);
	void EraseCell(Cell&);
	void ArrangeCells(int);
	void PushBlockList(ExtendedBlock&);
	void CheckLine();
	//bool IsCellAlone(Cell&, ExtendedBlock&);
	bool IsLanded(ExtendedBlock&);
	bool IsMovable(ExtendedBlock&);
	bool IsLost();
	bool& GetArrangePosition(ExtendedBlock&, int, int);
	bool& GetArrangePosition(ExtendedBlock&, int, int, int&, int&);
};
#endif
