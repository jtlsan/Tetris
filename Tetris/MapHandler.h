#ifndef __MAP_HANDLER_H__
#define __MAP_HANDLER_H__

#include "map.h"

class MapHandler
{
private:
	Map map;
public:
	MapHandler();
	~MapHandler();
	void PlayByInput();
};
#endif