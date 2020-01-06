#include "SystemHandler.h"
#include <thread>

SystemHandler::SystemHandler()
{
	//empty
}


SystemHandler::~SystemHandler()
{
	//empty
}


void SystemHandler::ShowTitle()
{
	for (int i = 0; i < 15; i++)
	{
		main_interface.DrawTitle();
		Sleep(200);
	}
}


void SystemHandler::ShowMenu()
{
	int select = 1, level = 0;
	while (select != 0)
	{
		select = main_interface.MenuSelect();
		switch (select)
		{
		case Menu::START:
			main_interface.EraseBelowTitle();
			level = main_interface.LevelSelect();
			if (level == 0)
			{
				main_interface.EraseBelowTitle();
				break;
			}
			StartGame(main_interface, level);
			break;
		case Menu::KEY:
			main_interface.EraseBelowTitle();
			main_interface.KeyInfoSelect();
			break;
		}
		main_interface.EraseBelowTitle();
	}
}


void SystemHandler::StartGame(Interface& main_interface, int level)
{
	system("cls");
	MapHandler mapManager(main_interface, level);
	mapManager.InitInterface();
	while (mapManager.get_game_result())
	{
		mapManager.GenerateCurBlock();
		mapManager.GenerateNextBlock();
		std::thread by_time{ [&mapManager]()->void {mapManager.PlayByTime(); return; } };
		std::thread by_input{ [&mapManager]()->void {mapManager.PlayByInput(); return; } };

		by_input.detach();
		by_time.join();
		mapManager.PushBlock();
		mapManager.DeleteFullLine();
	}
}