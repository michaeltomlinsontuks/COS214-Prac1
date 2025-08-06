CXX = g++
CXXFLAGS = -std=c++11 -g

SRC = \
	OCI.cpp \
	testMain.cpp\
	Logger.cpp\
	Canvas.cpp \
	Rectangle.cpp \
	RectangleFactory.cpp \
	Square.cpp \
	SquareFactory.cpp \
	Textbox.cpp \
	TextboxFactory.cpp 


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

OBJ := $(SRC:.cpp=.o)
BIN := app

all: $(BIN)

$(BIN):	$(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o:	%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run r:	$(BIN)
	./$(BIN)

clean c:
	rm -f $(OBJ) $(BIN) vgcore.*
 
valgrind v:	$(BIN)
	valgrind --leak-check=full --track-origins=yes ./$(BIN)