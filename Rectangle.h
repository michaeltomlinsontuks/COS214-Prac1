#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : Shape {


public:
	Shape* clone();

	Rectangle();

	void ~Rectangle();

	Rectangle(Rectangle& copy);

	vector<vector<char>> draw();
};

#endif
