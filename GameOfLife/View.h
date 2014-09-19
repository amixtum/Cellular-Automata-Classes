#include "SimpleGrid.h"

const float DT = 1.f / 60.f;

class View {
public:

	//initializes the View object
	//constructs the grid and organism
	//creates a render window according to the square dimensions
	//and the grid dimensions
	View(int sqrDim, int gridWidth, int gridHeight);

private:

	//Window used to render images
	sf::RenderWindow window;

	//Grid to display organism data
	SimpleGrid grid;

	//Organism that processes Life Game data
	LifeOrganism org;

public:

	//Postcondition: The application is started
	void run();

private:

	//Postcondition: process sfml events e.g. input
	void processEvents();

	//Postcondition: update logic
	void update();

	//Postcondition: render objects to the render window
	void render();
};