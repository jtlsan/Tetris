#include "interface.h"
#include "base.h"

using std::cout;
using std::endl;

void DrawNextBlockSquare()
{
	gotoxy(50, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "��� Next Block ���";
	for (int i = 0; i < 6; i++)
	{
			gotoxy(50, 6 + i);
			cout << "��";
			gotoxy(68, 6 + i);
			cout << "��";
	}
	gotoxy(50, 12);
	cout << "�����������";
}

void DrawNextBlock(ExtendedBlock next_block)
{
	gotoxy(56, 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), next_block.GetBlockColor());
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Cell tmp_cell = *(next_block.get_cell() + (i * 4) + j);
			if (tmp_cell.Is_active())
				cout << "��";
			else
				cout << "  ";
		}
		gotoxy(56, 8 + i);
	}
}