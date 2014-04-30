#include "CAUtility.h"

Vect2i CAUtil::getNeighborVect(int x, int y, int index) {
	Vect2i nV;
	nV.x = x;
	nV.y = y;
	switch (index)
	{
	case 0:
		nV.x = x - 1;
		nV.y = y - 1;
		break;
	case 1:
		nV.x = x;
		nV.y = y - 1;
		break;
	case 2:
		nV.x = x + 1;
		nV.y = y - 1;
		break;
	case 3:
		nV.x = x + 1;
		nV.y = y;
		break;
	case 4:
		nV.x = x + 1;
		nV.y = y + 1;
		break;
	case 5:
		nV.x = x;
		nV.y = y + 1;
		break;
	case 6:
		nV.x = x - 1;
		nV.y = y + 1;
		break;
	case 7:
		nV.x = x - 1;
		nV.y = y;
		break;
	default:
		std::cout << "Invalid index - returning cell position\n";
		break;
	}
	return nV;
}