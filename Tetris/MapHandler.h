#ifndef __MAP_HANDLER_H__
#define __MAP_HANDLER_H__

#include "map.h"



class MapHandler
{
private:
	Map map;
	bool game_result;
	int before_type;
	ExtendedBlock cur_block;
public:
	MapHandler();
	~MapHandler();
	void GenerateCurBlock();
	void PlayByInput();
	void PlayByTime();
	void DeleteFullLine();
	void PushBlock();
	bool get_game_result() { return game_result; }
};


#endif