#include "MapHandler.h"
#include "base.h"
#include "blocks.h"
#include <conio.h>
#include <ctime>
#include <mutex>
#include "exceptions.h"


std::mutex mtx;

MapHandler::MapHandler(Interface& main_interface, int _level)
	: main_interface(main_interface)
{
	map.InitialDraw();
	srand((unsigned int)time(0));
	game_result = true;
	level = _level;
	//before_type = 0;
}


MapHandler::~MapHandler()
{
	//empty;
}


void MapHandler::InitInterface()
{
	main_interface.DrawNextBlockSquare();
}


void MapHandler::GenerateCurBlock()
{
	static bool start = true;
	if (!start)
	{
		cur_block = next_block;
		return;
	}
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
	map.DrawBlock(block);
	start = false;
}


void MapHandler::GenerateNextBlock()
{
	int type = 0;
	while (type == 0 || type == 7)
	{
		type = rand() % 9;
		if (type == before_type)
			type = 0;
		else
			before_type = type;
	}
	ExtendedBlock block(type);
	next_block = block;
	main_interface.DrawNextBlock(next_block);
}


void MapHandler::PlayByInput()
{
	char key;
	
	while(!map.IsLanded(cur_block))
	{
		key = _getch();
		mtx.lock();
		map.DeleteBlock(cur_block);
		map.MoveByArrow(cur_block, key);
		map.DrawBlock(cur_block);
		mtx.unlock();
	}
	if (map.IsLost())
		game_result = false;
}



void MapHandler::PlayByTime()
{
	int time_gap = 1500 / level;
	while (!map.IsLanded(cur_block))
	{
		try
		{
			mtx.lock();
			map.DeleteBlock(cur_block);
			map.PullDownBlock(cur_block);
			map.DrawBlock(cur_block);
			
		}
		catch (MovementException & expn)
		{
			map.DrawBlock(cur_block);
		}
		mtx.unlock();
		Sleep(time_gap);
	}
	if (map.IsLost())
		game_result = false;
}


void MapHandler::DeleteFullLine()
{
	map.CheckLine();
}


void MapHandler::PushBlock()
{
	map.PushBlockList(cur_block);
}


void MapHandler::SwitchNextToCurBlock()
{
	cur_block = next_block;
}