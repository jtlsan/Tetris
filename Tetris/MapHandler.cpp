#include "MapHandler.h"
#include "base.h"
#include "blocks.h"
#include <conio.h>
#include <ctime>

MapHandler::MapHandler()
{
	map.InitialDraw();
	srand((unsigned int)time(0));
}


MapHandler::~MapHandler()
{
	//empty;
}


void MapHandler::PlayByInput()
{
	char key;
	int type = 0;
	while (type == 0 || type == 7)
		type = rand() % 9;
	ExtendedBlock block(type);
	map.DrawBlock(block);
	while(!map.IsLanded(block))
	{
		key = _getch();
		map.DeleteBlock(block);
		map.MoveByArrow(block, key);
		map.DrawBlock(block);
	}

}