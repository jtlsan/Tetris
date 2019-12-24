#include "exceptions.h"
#include "base.h"

void MovementException::ShowExceptionReason()
{
	std::cout << "블록을 해당 방향으로 이동할 수 없습니다." << std::endl;
}


