class CellData {
public:
	/**
		Constructs the CellData object with its initial state,
		x coordinate and y coordinate
	*/
	CellData(int initState, int xPos, int yPos);

private:

	//State of the cell
	int state;

	//State after update
	int nextState;

	//x coordinate of the cell
	int x;

	//y coordinate of the cell
	int y;

	//true if the next state has been set, false otherwise
	bool setNext;

public:

	//Postcondition: returns the state field
	int getState();

	//Postcondition: returns the x field
	int getX();

	//Postcondition: returns the y field
	int getY();

public:

	//Postcondition: state field is set to value of newState parameter
	void setState(int newState);

	//Postcondition: nextState field is set to nextState parameter
	void setNextState(int nextState);

	//Postcondition: x field is set to value of x parameter
	void setX(int x);

	//Postcondition: y field is set to value of y parameter
	void setY(int y);

	//Postcondition: x and y fields are set to values of x and y parameters
	void setPos(int x, int y);

	//Postcondition: state field is updated if setNext is true
	void updateState();
};