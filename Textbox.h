#ifndef TEXTBOX_H
#define TEXTBOX_H

class Textbox : Shape {

public:
	string text;

	Shape* clone();

	Textbox();

	void ~Textbox();

	Textbox(Textbox& copy);

	vector<vector<char>> draw();
};

#endif
