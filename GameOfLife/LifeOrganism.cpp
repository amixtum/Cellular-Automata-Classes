#include "LifeOrganism.h"

void LifeOrganism::create(int width, int height) {
	//initialize random with time seed
	std::srand(time(NULL));
	
	//set fields
	this->t = 0;
	this->width = width;
	this->height = height;
	this->allUpdated = false;

	//Create cell grid with dimensions width and height
	//50/50 random distribution
	for (int i = 0; i < height; ++i)
	{
		for (int k = 0; k < width; ++k)
		{
			CellData tempCell(((std::rand() % 1000 < 600) ? 0 : 1), i, k);
			this->cells.push_back(tempCell);
		}
	}
}

void LifeOrganism::advance() {
	//Determine the next states for all cells
	updateAll();

	//Update the states
	next();

	//Incrememnt the time-step variable
	t++;
}

int LifeOrganism::getStateAt(int x, int y) {
	return getCell(x, y).getState();
}

int LifeOrganism::getWidth() {
	return this->width;
}
int LifeOrganism::getHeight() {
	return this->height;
}
int LifeOrganism::getCurrentTimeStep() {
	return this->t;
}

void LifeOrganism::next() {
	//only perform operations if all cells have been updated
	if (allUpdated)
	{
		//iterator to iterate through the vector of cells
		std::vector<CellData>::iterator it;

		//officially update the state of all cells
		for (it = cells.begin(); it != cells.end(); ++it)
		{
			it->updateState();
		}

		//don't let this function get called until updateAll() is called again
		allUpdated = false;
	}
}

CellData & LifeOrganism::getCell(int x, int y) {
	return (cells[(x*width)+y]);
}

void LifeOrganism::updateCell(int x, int y) {
	//Pointer to the cell being updated
	CellData *uCell = &getCell(x, y);

	//Pointers to the neighbor cells
	CellData *neighbors[8];

	//Accumulator to hold the number of activated neighbors
	int activated = 0;

	//2D vector to hold neighbor positions
	Vect2i nVect;

	//Get the neighbor cells
	for (int i = 0; i < 8; ++i)
	{
		nVect = CAUtil::getNeighborVect(x, y, i);

		if (nVect.x >= 0 && nVect.x < width && nVect.y >= 0 && nVect.y < height)
			neighbors[i] = &getCell(nVect.x, nVect.y);
		else
			neighbors[i] = NULL;
	}

	//Determine the number of activated neighbors
	for (int i = 0; i < 8; ++i)
	{
		if (neighbors[i] != NULL)
			activated += neighbors[i]->getState();
	}

	//Perform the transition function on the cell
	//See Conway's Game of Life for details on this function
	switch (uCell->getState())
	{
	case 0:
		if (activated == 3)
			uCell->setNextState(1);
		else
			uCell->setNextState(0);
		break;
	case 1:
		if (activated < 2 || activated > 3)
			uCell->setNextState(0);
		else
			uCell->setNextState(1);
		break;
	default:
		break;
	}
}
void LifeOrganism::updateAll() {
	//Call the updateCell function for all cells
	for (int i = 0; i < height; ++i)
	{
		for (int k = 0; k < width; ++k)
		{
			updateCell(k, i);
		}
	}
	//Notify the object that all cells have been updated and are ready to be advanced to the next time step
	allUpdated = true;
}