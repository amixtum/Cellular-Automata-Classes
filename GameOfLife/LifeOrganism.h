#include <vector>
#include <cstdlib>
#include <ctime>

#include "CellData.h"
#include "CAUtility.h"

class LifeOrganism {
public:
	/**
		Constructs the organism with a grid of width*height cells
		states are 50% p 0 or 1
	*/
	void create(int width, int height);

private:

	//Width of the organism
	int width;

	//Height of the organsim
	int height;

	//Current time step
	int t;

	//variable to determine if all cells have been updated
	bool allUpdated;

	//Container that holds all the cells
	std::vector<CellData> cells;

public:

	//Postcondition: Cells are updated and time-step is advanced
	void advance();

	//Postcondition: The state of the cell at (x,y) is returned
	int getStateAt(int x, int y);

	//Postcondition: The width of the grid is returned
	int getWidth();
	
	//Postcondition: The height of the grid is returned
	int getHeight();

	//Postcondition: The current time step is returned
	int getCurrentTimeStep();

private:

	//Postcondition: Returns the cell at the specified x and y coordinate
	CellData & getCell(int x, int y);

	//Postcondition: Cell at specified x and y coordinate is updated
	void updateCell(int x, int y);

	//Postcondition: All cells in cells vector are updated
	void updateAll();

	//Postcondition: All Cells are updated to their new states
	void next();
};