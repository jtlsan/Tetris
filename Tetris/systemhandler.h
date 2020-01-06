#ifndef __MENUHANDLER_H__
#define __MENUHANDLER_H__
#include "base.h"
#include "interface.h"
#include "MapHandler.h"

class SystemHandler
{
private:
	Interface main_interface;
public:
	SystemHandler();
	~SystemHandler();
	void ShowTitle();
	void ShowMenu();
	void StartGame(Interface&, int);

};

#endif