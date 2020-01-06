
#include <windows.h>
#include <conio.h>
#include <iostream>
#include "blocks.h"
#include "base.h"
#include "systemhandler.h"

int main() {
	SetConsoleTitle("Tetris");
	system("mode con lines=32 cols=90");
	SystemHandler system_manager;
	system_manager.ShowTitle();
	system_manager.ShowMenu();
	gotoxy(0, 29);
	
	//StartGame(main_interface);
	
	

}