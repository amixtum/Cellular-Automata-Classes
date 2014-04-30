#include "CellData.h"

CellData::CellData(int initState, int xPos, int yPos) {
	this->state = initState;
	this->x = xPos;
	this->y = yPos;
	this->setNext = false;
}

int CellData::getState() {
	return this->state;
}
int CellData::getX() {
	return this->x;
}
int CellData::getY() {
	return this->y;
}

void CellData::setState(int newState) {
	this->state = newState;
}
void CellData::setNextState(int nextState) {
	this->nextState = nextState;
	setNext = true;
}
void CellData::setPos(int x, int y) {
	this->x = x;
	this->y = y;
}
void CellData::setX(int x) {
	this->x = x;
}
void CellData::setY(int y) {
	this->y = y;
}
void CellData::updateState() {
	if (setNext)
	{
		setNext = false;
		state = nextState;
	}
}
