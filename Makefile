CXX = g++
CXXFLAGS = -std=c++11 -g

SRC =loggerOCI/OCI.cpp \
	testMain.cpp\
	loggerOCI/Logger.cpp\
	canvas/Canvas.cpp \
	shapes/Rectangle.cpp \
	factories/RectangleFactory.cpp \
	shapes/Square.cpp \
	factories/SquareFactory.cpp \
	shapes/Textbox.cpp \
	factories/TextboxFactory.cpp \
	memento/Memento.cpp \
	TestingFramework/array.cpp\
	shapes/Shape.cpp \
	memento/Caretaker.cpp\
	exporter/PDFExporter.cpp\
	exporter/ExportCanvas.cpp\
	exporter/PNGExporter.cpp

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
