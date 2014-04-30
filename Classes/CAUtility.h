#include <iostream>

struct Vect2i {
	int x;
	int y;
};

class CAUtil {
public:
	//Postcondition: returns vector of the neighbor in a moore neighborhood
	//at specified index
	//Index 0 is top left, and goes clockwise until 7
	static Vect2i getNeighborVect(int x, int y, int index);
};