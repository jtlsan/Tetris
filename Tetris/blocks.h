#ifndef __BLOCKS_H__
#define __BLOCKS_H__
#include "baseblock.h"

class ExtendedBlock : public Block
{
private:
	int blockType;
public:
	ExtendedBlock(int);
	virtual void Rotate();
	~ExtendedBlock();
};




#endif