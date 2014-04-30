#include "SimpleSquare.h"

SimpleSquare::SimpleSquare(int x, int y, int dim, sf::Color color) {
	//Set field values
	this->color = color;
	this->positionI = sf::Vector2i(x, y);
	this->positionF = sf::Vector2f(x*dim, y*dim);

	//Initialize the vertex array
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(4);

	vertices[0].position = sf::Vector2f(positionF.x,positionF.y);
	vertices[1].position = sf::Vector2f(positionF.x + dim, positionF.y);
	vertices[2].position = sf::Vector2f(positionF.x + dim, positionF.y + dim);
	vertices[3].position = sf::Vector2f(positionF.x,positionF.y + dim);

	vertices[0].color = color;
	vertices[1].color = color;
	vertices[2].color = color;
	vertices[3].color = color;
}

void SimpleSquare::setColor(sf::Color color) {

	this->color = color;

	vertices[0].color = color;
	vertices[1].color = color;
	vertices[2].color = color;
	vertices[3].color = color;
}

int SimpleSquare::getXI() {
	return positionI.x;
}
int SimpleSquare::getYI() {
	return positionI.y;
}
sf::Vector2i SimpleSquare::getVI() {
	return positionI;
}

float SimpleSquare::getXF() {
	return positionF.x;
}
float SimpleSquare::getYF() {
	return positionF.y;
}
sf::Vector2f SimpleSquare::getVF() {
	return positionF;
}