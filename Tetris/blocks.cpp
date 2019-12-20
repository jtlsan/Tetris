#include "blocks.h"
#include "base.h"

ExtendedBlock::ExtendedBlock(int type) : Block(), blockType(type)
{
	// empty
}



// 모든 블록에 대해 4x4 범위 내에서 우측으로 90도 돌린다.
void ExtendedBlock::Rotate()
{
	int gap, record_n = 0;
	int x_record[4], y_record[4];	//space의 배열에서 새로 true가 될 위치를 기록해둔다.
	if ((blockType != blockinfo::O_BLOCK))	//OBlock은 회전이 불가능하므로
	{

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				if (space[i][j])
				{
					space[i][j] = false;
					if (j == Get_center_xpos())
					{
						gap = Get_center_ypos() - i;
						x_record[record_n] = j + gap;

						y_record[record_n++] = i + gap;
					}
					else if (i == Get_center_ypos())
					{
						gap = Get_center_xpos() - j;
						x_record[record_n] = j + gap;
						if (i - gap >= 4)					// I 블록에 대한 예외
							y_record[record_n++] = i + gap;
						else
							y_record[record_n++] = i - gap;
					}
					else if (j < Get_center_xpos())
					{
						if (i > Get_center_ypos())
						{
							gap = (Get_center_ypos() - i) * 2;
							x_record[record_n] = j;
							y_record[record_n++] = i + gap;
						}
						else
						{
							gap = (Get_center_xpos() - j) * 2;
							x_record[record_n] = j + gap;
							y_record[record_n++] = i;
						}
					}
					else
					{
						if (i < Get_center_ypos())
						{
							gap = (Get_center_ypos() - i) * 2;
							x_record[record_n] = j;
							y_record[record_n++] = i + gap;
						}
						else
						{
							gap = (Get_center_xpos() - j) * 2;
							x_record[record_n] = j + gap;
							y_record[record_n++] = i;
						}
					}
				}
			}
		for (int i = 0; i < 4; i++)
			space[y_record[i]][x_record[i]] = true;
	}
}






ExtendedBlock::~ExtendedBlock()
{
	ExtendedBlock::~ExtendedBlock();
}