#ifndef __INTERFACE_H__
#define __INTERFACE_H__
#include "blocks.h"

class Interface
{
private:
	int before_letter_color[6];
	int current_cursor_pos;
	bool cursor_top;
	bool cursor_bottom;
public:
	Interface();
	void DrawNextBlock(ExtendedBlock);
	void DrawNextBlockSquare();
	void DrawTitle();
	void SetRandomTextColor(int&, int& before_letter_color);
	int MenuSelect();
	void DrawMenu();
	void DrawCursor(int, int);
	void DrawLevel();
	int LevelSelect();
	void EraseBelowTitle();
	void DrawKeyInfo();
	void KeyInfoSelect();
};




#endif