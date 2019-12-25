
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
	
	while (mapManager.get_game_result())
	{
		mapManager.GenerateCurBlock();
		std::thread by_time{ [&mapManager]()->void {mapManager.PlayByTime(); return; } };
		std::thread by_input{ [&mapManager]()->void {mapManager.PlayByInput(); return; } };
		by_input.join();
		by_time.join();
		
	}
	
	
	/*
	gotoxy(x, y);
	for (int i = 0; i < 12; i++)
		cout << "бс";
	for (int i = 0; i < 21; i++)
	{
		gotoxy(x, ++y);
		cout << "бс";
		gotoxy(x + 22, y);
		cout << "бс";
	}
	gotoxy(x +2, y);
	
	for (int i = 0; i < 11; i++)
		cout << "бс";
	while (1)
	{
		key = _getch();
		map.DrawBlock(block, key);
	}
	*/
	

}