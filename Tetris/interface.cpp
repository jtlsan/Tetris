#include "interface.h"
#include "base.h"
#include <conio.h>


using std::cout;
using std::endl;

Interface::Interface()
{
	cursor_top = false;
	cursor_bottom = false;
}
void Interface::DrawNextBlockSquare()
{
	gotoxy(50, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "■■ Next Block ■■";
	for (int i = 0; i < 6; i++)
	{
			gotoxy(50, 6 + i);
			cout << "■";
			gotoxy(68, 6 + i);
			cout << "■";
	}
	gotoxy(50, 12);
	cout << "■■■■■■■■■■";
}

void Interface::DrawNextBlock(ExtendedBlock next_block)
{
	gotoxy(56, 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), next_block.GetBlockColor());
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Cell tmp_cell = *(next_block.get_cell() + (i * 4) + j);
			if (tmp_cell.Is_active())
				cout << "■";
			else
				cout << "  ";
		}
		gotoxy(56, 8 + i);
	}
}





void Interface::SetRandomTextColor(int& before_color, int& before_letter_color)
{
	int color = 0;
	while (color == 0 || color == 7 || color == before_color || color == before_letter_color)
	{
		color = rand() % 9;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	before_color = color;
	before_letter_color = color;
}

void Interface::DrawTitle()
{
	int num = 1;
	srand((unsigned int)time(0));
	int color = 0;
	//static int before_letter_color[6];
	
	// Draw T
	SetRandomTextColor(color, before_letter_color[0]);
	gotoxy(12, 1);
	cout << "■■■■■";
	for (int i = 0; i < 6; i++)
	{
		gotoxy(16, 2 + i);
		cout << "■";
	}
	
	// Draw E
	SetRandomTextColor(color, before_letter_color[1]);
	gotoxy(24, 1);
	for (int i = 0; i < 7; i++)
	{
		if (i == 0 || i == 3 || i == 6)
			cout << "■■■■";
		else
			cout << "■";
		gotoxy(24, 2 + i);
	}

	//Draw T
	SetRandomTextColor(color, before_letter_color[2]);
	gotoxy(34, 1);
	cout << "■■■■■";
	for (int i = 0; i < 6; i++)
	{
		gotoxy(38, 2 + i);
		cout << "■";
	}
	
	// Draw R
	SetRandomTextColor(color, before_letter_color[3]);
	gotoxy(46, num++);
	cout << "■■■■";
	gotoxy(46, num++);
	cout << "■    ■";
	gotoxy(46, num++);
	cout << "■    ■";
	gotoxy(46, num++);
	cout << "■■■■";
	gotoxy(46, num++);
	cout << "■■    ";
	gotoxy(46, num++);
	cout << "■  ■  ";
	gotoxy(46, num++);
	cout << "■    ■";
	num = 1;

	//Draw I
	SetRandomTextColor(color, before_letter_color[4]);
	gotoxy(56, num++);
	cout << "■■■■■";
	for (int i = 0; i < 5; i++)
	{
		gotoxy(60, num++);
		cout << "■";
	}
	gotoxy(56, num);
	cout << "■■■■■";
	num = 1;

	//Draw S
	SetRandomTextColor(color, before_letter_color[5]);
	for (int i = 0; i < 7; i++)
	{
		gotoxy(68, num++);
		if (i % 3 == 0)
		{
			cout << "■■■■■";
		}
		else
		{
			if (i < 3)
				cout << "■";
			else
			{
				gotoxy(76, num - 1);
				cout << "■";
			}
		}
	}
}


int Interface::MenuSelect()
{
	char input = 0;
	DrawMenu();
	DrawCursor(input, 3);
	while (Arrow::SPACEBAR != (input = _getch()))
	{
		DrawCursor(input, 3);
		if (current_cursor_pos == 16)
			cursor_top = true;
		else if (current_cursor_pos == 22)
			cursor_bottom = true;
	}
	cursor_top = false;
	cursor_bottom = false;
	switch (current_cursor_pos)
	{
		case 16:
			return Menu::START;
		case 19:
			return Menu::KEY;
		case 22:
			return Menu::END;
	}
}


void Interface::DrawMenu()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(40, 16);
	cout << "Game Start";
	gotoxy(41, 19);
	cout << "Key Info";
	gotoxy(43, 22);
	cout << "Exit";
}


void Interface::DrawCursor(int input, int gap)
{
	gotoxy(37, current_cursor_pos);
	cout << "  ";
	gotoxy(51, current_cursor_pos);
	cout << "  ";
	switch (input)
	{
		case Arrow::UP:
			if (cursor_top)
				break;
			if (cursor_bottom)
				cursor_bottom = false;
			current_cursor_pos -= gap;
			break;
		case Arrow::DOWN:
			if (cursor_bottom)
				break;
			if (cursor_top)
				cursor_top = false;
			current_cursor_pos += gap;
			break;
		// 제일 처음 cursor를 그리는 경우
		case 0:						
			cursor_bottom = false;
			cursor_top = false;
			current_cursor_pos = 19;
			break;
	}
	// 바뀐 current_cursor_pos 수치에 맞게 cursor를 그린다.
	gotoxy(37, current_cursor_pos);
	cout << "▷";
	gotoxy(51, current_cursor_pos);
	cout << "◁";
	gotoxy(0, 0);
}


void Interface::DrawLevel()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(43, 29);
	cout << "Back";
	for (int i = 1; i < 10; i++)
	{
		gotoxy(41, 9 + (2 * i));
		cout << "level " << i;
	}
}


int Interface::LevelSelect()
{
	char input = 0;
	DrawLevel();
	DrawCursor(input, 2);
	while (Arrow::SPACEBAR != (input = _getch()))
	{
		DrawCursor(input, 2);
		if (current_cursor_pos == 11)
			cursor_top = true;
		else if (current_cursor_pos == 29)
			cursor_bottom = true;
	}
	cursor_top = false;
	cursor_bottom = false;
	switch (current_cursor_pos)
	{
	case 11:
		return 1;
	case 13:
		return 2;
	case 15:
		return 3;
	case 17:
		return 4;
	case 19:
		return 5;
	case 21:
		return 6;
	case 23:
		return 7;
	case 25:
		return 8;
	case 27:
		return 9;
	case 29:
		return 0;
	}
}


void Interface::EraseBelowTitle()
{
	for (int i = 0; i < 22; i++)
	{
		gotoxy(0, 9 + i);
		for (int j = 0; j < 90; j++)
		{
			cout << " ";
		}
		cout << endl;
	}
}


void Interface::DrawKeyInfo()
{
	int center_x = 45, center_y = 19;
	// Key info for Arrow
	gotoxy(center_x - 9, center_y - 5);
	cout << "Left ← ↓ → Right";
	gotoxy(center_x - 2, center_y - 4);
	cout << "Down";
	gotoxy(center_x - 1, center_y - 6);
	cout << "↑";
	gotoxy(center_x - 3, center_y - 7);
	cout << "Rotate";

	// Key info for spacebar
	gotoxy(center_x - 15, center_y);
	cout << "Space bar   :   Pull to bottom";
	gotoxy(center_x - 5, center_y + 5);
	cout << "▷ Back ◁";
	gotoxy(0, 0);
}


void Interface::KeyInfoSelect()
{
	char input = 0;
	DrawKeyInfo();
	while (Arrow::SPACEBAR != (input = _getch()))
	{
		// empty
	}
	
}