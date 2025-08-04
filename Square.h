#ifndef SQUARE_H
#define SQUARE_H

class Square : Shape {


public:
	Shape* clone();

	Square();

	void ~Square();

	Square(Square& copy);

	vector<vector<char>> draw();
};

#endif
