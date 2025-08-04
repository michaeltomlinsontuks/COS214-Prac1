#ifndef SHAPE_H
#define SHAPE_H

class Shape {

private:
	int length;
	int width;
	string colour;
	int position_x;
	int position_y;

public:
	Shape* clone();

	Shape();

	void ~Shape();

	Shape(Shape& copy);

	vector<vector<char>> draw();
};

#endif
