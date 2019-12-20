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
		}
	}
}