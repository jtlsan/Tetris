#include "map.h"
#include "base.h"



Map::Map()
{
	// Make borders True
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (i == 0 || i == 21)
				arrange[i][j] = true;
			else if (j == 0 || j == 11)
				arrange[i][j] = true;
			else
				arrange[i][j] = false;
		}
	}
	for (int i = 0; i < 20; i++)
		line_status[i] = false;
}


Map::~Map()
{
	for (int i = 0; i < 22; i++)
		delete[] arrange[i];
}


void Map::DrawBlock(ExtendedBlock& cur_block, int input_arrow)
{
	DeleteBlock(cur_block);
	switch (input_arrow)
	{
		case Arrow::UP:
			try
			{
				cur_block.Rotate();
				IsMovable(cur_block);

			}
			catch (MovementException & expn)
			{
				for (int i = 0; i < 3; i++)
					cur_block.Rotate();
			}
			break;
		case Arrow::LEFT:
			try
			{
				cur_block.Set_xpos(cur_block.Get_xpos() - 1);
				IsMovable(cur_block);
			}
			catch (MovementException & expn)
			{
				cur_block.Set_xpos(cur_block.Get_xpos() + 1);
			}
			break;
		case Arrow::RIGHT:
			try
			{
			cur_block.Set_xpos(cur_block.Get_xpos() + 1);
			IsMovable(cur_block);
			}
			catch (MovementException & expn)
			{
				cur_block.Set_xpos(cur_block.Get_xpos() - 1);
			}
			break;
		// case Arrow::DOWN 필요
		case Arrow::DOWN:
			cur_block.Set_ypos(cur_block.Get_ypos() + 1);
	}

	//cur_block에 있는 4x4배열의 상대적 위치를 arrange 위치로 변환하여 arrange에 적용
	int vertical, horizontal, abs_vertical, abs_horizontal;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cur_block.GetBlockColor());
	for(int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (*(cur_block.Get_space() + (i * 4) + j))
			{
				GetArrangePosition(cur_block, i, j, vertical, horizontal) = true;
				abs_vertical = 5 + vertical;
				abs_horizontal = 10 + horizontal * 2;
				gotoxy(abs_horizontal, abs_vertical);
				std::cout << "■";
			}
		}
}


void Map::DeleteBlock(ExtendedBlock& cur_block)
{
	int vertical, horizontal, abs_vertical, abs_horizontal;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (*(cur_block.Get_space() + (i * 4) + j))
			{
				GetArrangePosition(cur_block, i, j, vertical, horizontal) = false;
				abs_vertical = 5 + vertical;
				abs_horizontal = 10 + horizontal * 2;
				gotoxy(abs_horizontal, abs_vertical);
				printf("  ");
			}
		}
}


bool Map::IsMovable(ExtendedBlock& cur_block)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (*(cur_block.Get_space() + (i * 4) + j))
			{
				if (GetArrangePosition(cur_block, i, j))
					throw MovementException();
			}
		}
	return true;
}


bool& Map::GetArrangePosition(ExtendedBlock& cur_block, int i, int j)
{
	int vertical = cur_block.Get_ypos() + i - cur_block.Get_center_ypos();
	int horizontal = cur_block.Get_xpos() + j - cur_block.Get_center_xpos();
	return arrange[vertical][horizontal];
}


bool& Map::GetArrangePosition(ExtendedBlock& cur_block, int i, int j, int& vertical, int& horizontal)
{
	vertical = cur_block.Get_ypos() + i - cur_block.Get_center_ypos();
	horizontal = cur_block.Get_xpos() + j - cur_block.Get_center_xpos();
	//horizontal = cur_block.Get_xpos() + (j - cur_block.Get_center_xpos()) * 2;
	return arrange[vertical][horizontal];
}



bool Map::IsLineFull()
{
/*
	for (int i = 1; i < 21; i++)
		for (int j = 1; j < 11; j++)
		{
			if (!arrange[i][j])
				break;
			if (j == 10)
				line_status[i-1] = true;
		}
*/
	return true;
}


void Map::DeleteLine()
{
	/*
	for (int i = 0; i < 20; i++)
	{
		if (line_status[i])
			for(int j = 0; j < 10; j++)
				arrange
	}
	*/
}