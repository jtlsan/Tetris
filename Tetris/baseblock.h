#ifndef __BASE_BLOCK_H__
#define __BASE_BLOCK_H__
#include "cell.h"

class Block
{
private:
	int xpos;
	int ypos;
	int center_xpos;
	int center_ypos;
protected:
	Cell space[4][4];
public:
	Block();
	virtual void Rotate() = 0;
	int Get_xpos() { return xpos; }
	int Get_ypos() { return ypos; }
	void Set_xpos(int input) { xpos = input; }
	void Set_ypos(int input) { ypos = input; }
	
	int Get_center_xpos() { return center_xpos; }
	int Get_center_ypos() { return center_ypos; }
	Cell* get_cell() { return (Cell*)space; }
	//bool* Get_space() { return (bool*)space; }
	Block& operator=(Block&);
	~Block();
};

#endif