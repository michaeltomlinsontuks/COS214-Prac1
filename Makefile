CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g --coverage 
LDFLAGS = -lgcov


SRC =	TestingMain.cpp\
	loggerOCI/Logger.cpp \
	canvas/Canvas.cpp \
	shape/Rectangle.cpp \
	factory/RectangleFactory.cpp \
	shape/Square.cpp \
	factory/SquareFactory.cpp \
	shape/Textbox.cpp \
	factory/TextboxFactory.cpp \
	memento/Memento.cpp \
	memento/Caretaker.cpp \
	exporter/PDFExporter.cpp \
	exporter/ExportCanvas.cpp \
	exporter/PNGExporter.cpp

HEADERS = \
	canvas/Canvas.h \
	shape/Rectangle.h \
	factory/RectangleFactory.h \
	shape/Square.h \
	factory/SquareFactory.h \
	shape/Textbox.h \
	factory/TextboxFactory.h \
	loggerOCI/Logger.h \
	memento/Memento.h \
	memento/Caretaker.h \
	shape/Shape.h \
	factory/ShapeFactory.h \
	loggerOCI/ANSI-color-codes.h

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
	rm -f application.log demo PDF.txt PNG.txt coverage.txt


valgrind v: $(BIN)
	valgrind --leak-check=full --track-origins=yes ./$(BIN)

cov: all
	./$(BIN)
	gcovr --root . \
	    --exclude '.*\.h' \
	    --print-summary > coverage.txt


DEMO_SRC = loggerOCI/OCI.cpp \
	DemoMain.cpp \
	loggerOCI/Logger.cpp \
	canvas/Canvas.cpp \
	shape/Rectangle.cpp \
	factory/RectangleFactory.cpp \
	shape/Square.cpp \
	factory/SquareFactory.cpp \
	shape/Textbox.cpp \
	factory/TextboxFactory.cpp \
	memento/Memento.cpp \
	memento/Caretaker.cpp \
	exporter/PDFExporter.cpp \
	exporter/ExportCanvas.cpp \
	exporter/PNGExporter.cpp

DEMO_OBJ := $(DEMO_SRC:.cpp=.o)
DEMO_BIN := demo

demo: $(DEMO_BIN)

$(DEMO_BIN): $(DEMO_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

run-demo:
	./$(DEMO_BIN)

leak: $(DEMO_BIN)
	valgrind --leak-check=full --track-origins=yes ./$(DEMO_BIN)
