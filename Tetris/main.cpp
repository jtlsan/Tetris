
#include <windows.h>
#include <conio.h>
#include <iostream>
#include "blocks.h"
#include "base.h"
#include "map.h"
#include "MapHandler.h"
#include <thread>
#include <cstdio>






int main() {
	SetConsoleTitle("Tetris");
	MapHandler mapManager;
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