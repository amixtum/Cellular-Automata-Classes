#include <SFML/Graphics.hpp>

/*
	Drawable square that is automatically scaled from integer values to the specified dimensions 
*/
class SimpleSquare : public sf::Drawable {
public:

	//Postcondition: Initializes a square at (x*dim,y*dim)
	SimpleSquare(int x, int y, int dim, sf::Color color);

private:

	//Vertices of the square
	sf::VertexArray vertices;

	//Top left corner of the square
	sf::Vector2f positionF;

	//Top left corner as an integer
	sf::Vector2i positionI;

	//Color of the square
	sf::Color color;

public:

	void setColor(sf::Color color);

public:

	//Postcondition: the unscaled x position is returned
	int getXI();

	//Postcondition: the unscaled y position is returned
	int getYI();

	//Postcondition: the scaled x position is returned
	float getXF();

	//Postcondition: the scaled y position is returned
	float getYF();

	//Postcondition: the unscaled position vector is returned
	sf::Vector2i getVI();

	//Postcondition: the scaled position vector is returned
	sf::Vector2f getVF();
	
private:
	//Needed to inherit from sf::Drawable
	//Allows object to be drawn on a screen
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
		target.draw(vertices, states);
	}
};