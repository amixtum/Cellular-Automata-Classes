#include "SimpleGrid.h"

void SimpleGrid::create(LifeOrganism &org, int sqrDim) {
	//Initialize fields
	this->iDim.x = org.getWidth();
	this->iDim.y = org.getHeight();

	//Create squares from LifeOrganism object states
	for (int i = 0; i < org.getHeight(); ++i)
	{
		for (int k = 0; k < org.getWidth(); ++k)
		{
			SimpleSquare temp(k, i, sqrDim, (org.getStateAt(k, i) == 0) ? sf::Color::White : sf::Color::Black);
			sqrs.push_back(temp);
		}
	}
}

void SimpleGrid::update(LifeOrganism &org) {
	for (int i = 0; i < iDim.y; ++i)
	{
		for (int k = 0; k < iDim.x; ++k)
		{
			getSquare(k, i).setColor((org.getStateAt(k, i) == 0) ? 
									  sf::Color::White : sf::Color::Black);
		}
	}
}

SimpleSquare & SimpleGrid::getSquare(int x, int y) {
	return sqrs[(x * iDim.x) + y];
}