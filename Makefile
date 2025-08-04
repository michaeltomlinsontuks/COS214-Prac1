CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

SRC = \
	OCI.cpp \
	Canvas.cpp \
	Rectangle.cpp \
	RectangleFactory.cpp \
	Square.cpp \
	SquareFactory.cpp \
	Textbox.cpp \
	TextboxFactory.cpp \
	Logger.cpp \

HEADERS = \
	OCI.h \
	Canvas.h \
	Rectangle.h \
	RectangleFactory.h \
	Square.h \
	SquareFactory.h \
	Textbox.h \
	TextboxFactory.h \
	Logger.h \
	Memento.h \
	Caretaker.h \
	Shape.h \
	ShapeFactory.h \
	ANSI-color-codes.h

all: main

main: $(SRC) testMain.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) testMain.cpp -o testMain

clean:
	rm -f testMain *.o

