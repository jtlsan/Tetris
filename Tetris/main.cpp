#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include "blocks.h"
#include "base.h"
#include "map.h"
#include "MapHandler.h"
using namespace std;
#define Xmax 79
#define Ymax 24

void move_arrow_key(char key, int* x, int* y, int x_b, int y_b) {
	switch (key) {
	case 72:
		*y = *y - 1;
		if (*y < 1) *y = 1;
		break;
	case 75:
		*x = *x - 1;
		if (*x < 1) *x = 1;
		break;
	case 77:
		(*x)++;
		if (*x > x_b) *x = x_b;
		break;
	case 80:
		(*y)++;
		if (*y > y_b) *y = y_b;
		break;
	default:
		return;
	}

}


/*
void gotoxy(int x, int y) {
	COORD Pos = { x-1 ,y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
*/


int main() {
	char key;
	int x = 10, y = 5, i = 1;
	SetConsoleTitle("Tetris");
	MapHandler mapHandler;
	while(1)
		mapHandler.PlayByInput();
	
	
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