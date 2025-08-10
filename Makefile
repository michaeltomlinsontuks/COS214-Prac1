CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g --coverage 
LDFLAGS = -lgcov


SRC =	TestingMain.cpp\
	OCI.cpp\
	Logger.cpp \
	Canvas.cpp \
	Rectangle.cpp \
	RectangleFactory.cpp \
	Square.cpp \
	SquareFactory.cpp \
	Textbox.cpp \
	TextboxFactory.cpp \
	Memento.cpp \
	array.cpp \
	Shape.cpp \
	Caretaker.cpp \
	PDFExporter.cpp \
	ExportCanvas.cpp \
	PNGExporter.cpp

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


$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ 


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@  


run r: $(BIN)
	./$(BIN)

clean c:
	find . -name '*.o' -delete
	rm -f $(BIN) vgcore.*
	find . -name '*.gcno' -delete
	find . -name '*.gcda' -delete
	find . -name '*.gcov' -delete
	rm -f application.log demo PDF.txt PNG.txt


valgrind v: $(BIN)
	valgrind --leak-check=full --track-origins=yes ./$(BIN)

cov: all
	./$(BIN)
	gcovr --root . \
	    --exclude '.*\.h' \
	    --print-summary > coverage.txt


DEMO_SRC = OCI.cpp \
	DemoMain.cpp \
	Logger.cpp \
	Canvas.cpp \
	Rectangle.cpp \
	RectangleFactory.cpp \
	Square.cpp \
	SquareFactory.cpp \
	Textbox.cpp \
	TextboxFactory.cpp \
	Memento.cpp \
	array.cpp \
	Shape.cpp \
	Caretaker.cpp \
	PDFExporter.cpp \
	ExportCanvas.cpp \
	PNGExporter.cpp

DEMO_OBJ := $(DEMO_SRC:.cpp=.o)
DEMO_BIN := demo

demo: $(DEMO_BIN)

$(DEMO_BIN): $(DEMO_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

run-demo:
	./$(DEMO_BIN)

leak: $(DEMO_BIN)
	valgrind --leak-check=full --track-origins=yes ./$(DEMO_BIN)
