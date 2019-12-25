#include "MapHandler.h"
#include "base.h"
#include "blocks.h"
#include <conio.h>
#include <ctime>
#include "exceptions.h"

MapHandler::MapHandler()
{
	map.InitialDraw();
	srand((unsigned int)time(0));
	game_result = true;
	//before_type = 0;
}


MapHandler::~MapHandler()
{
	//empty;
}


void MapHandler::GenerateCurBlock()
{
	int type = 0;
	srand((unsigned int)time(0));
	while (type == 0 || type == 7)
	{
		type = rand() % 9;
		if (type == before_type)
			type = 0;
		else
			before_type = type;
	}
	ExtendedBlock block(type);
	cur_block = block;
}


void MapHandler::PlayByInput()
{
	char key;
	
	while(!map.IsLanded(cur_block))
	{
		key = _getch();
		map.DeleteBlock(cur_block);
		map.MoveByArrow(cur_block, key);
		map.DrawBlock(cur_block);
	}
	if (map.IsLost())
		game_result = false;
}



void MapHandler::PlayByTime()
{
	map.DrawBlock(cur_block);
	while (!map.IsLanded(cur_block))
	{
		Sleep(1000);
		try
		{
			map.DeleteBlock(cur_block);
			map.PullDownBlock(cur_block);
		}
		catch (MovementException & expn){}
	}
	if (map.IsLost())
		game_result = false;
}
