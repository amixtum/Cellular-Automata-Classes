#include "View.h"

View::View(int sqrDim, int gridWidth, int gridHeight) {
	//Calculate the window dimensions
	int width = gridWidth*sqrDim;
	int height = gridHeight*sqrDim;

	//Create the window
	window.create(sf::VideoMode(width, height), "The Game of Life");

	//Create the organism
	org.create(gridWidth, gridHeight);

	//Create the grid
	grid.create(org, sqrDim);
}

void View::run()
{
	sf::Clock timer;
	float tAcc = 0;
	while (window.isOpen())
	{
		tAcc += timer.restart().asSeconds();

		processEvents();

		if (tAcc >= 0.1f)
		{
			update();
			tAcc = 0;
		}

		render();
	}
}

void View::processEvents()
{
	sf::Event sf_event;
	while (window.pollEvent(sf_event))
	{
		//Close the window if the user clicks the close button
		if (sf_event.type == sf::Event::Closed)
			window.close();
	}
}
void View::update()
{
	//Advance the life game by one time step
	org.advance();

	//Update the grid to the current LifeOrganism state
	grid.update(org);
}
void View::render()
{
	//Clear WIndow
	window.clear();

	//draw the grid to the back buffer
	window.draw(grid);

	//Swap buffers
	window.display();
}