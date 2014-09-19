#include "SimpleSquare.h"
#include "LifeOrganism.h"

class SimpleGrid : public sf::Drawable {
public:
	//Postcondition: The grid is intialized wtih width*height squares of dimension sqrDim
	void create(LifeOrganism &org, int sqrDim);
private:

	//Container to hold the squares
	std::vector<SimpleSquare> sqrs;

	//Dimensions of the grid
	sf::Vector2i iDim;

public:

	//Postcondition: Updates the square colors to reflect the life organism states
	void update(LifeOrganism &org);

private:

	//Postcondition: square at index (x,y) is returned
	SimpleSquare & getSquare(int x, int y);

private:

	//Postcondition: Draw the SimpleSquare objects
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
		std::vector<SimpleSquare>::iterator it;
		for (int i = 0; i < iDim.x*iDim.y; ++i)
		{
			target.draw(sqrs[i], states);
		}
	}
};