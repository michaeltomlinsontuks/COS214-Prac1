CXX := g++
CXXFLAGS := -g -std=c++11

SRC := TestingMain.cpp  #<cpp files to run> do not put testing.cpp here
OBJ := $(SRC:.cpp=.o)
BIN := canvasApp

# Demo target
# List all .cpp files needed for the demo build
DEMO_SRC := DemoMain.cpp \
    loggerOCI/OCI.cpp loggerOCI/Logger.cpp \
    canvas/Canvas.cpp \
    shapes/Rectangle.cpp shapes/Square.cpp shapes/Textbox.cpp shapes/Shape.cpp \
    factories/RectangleFactory.cpp factories/SquareFactory.cpp factories/TextboxFactory.cpp \
    exporter/ExportCanvas.cpp exporter/PDFExporter.cpp exporter/PNGExporter.cpp \
    memento/Caretaker.cpp memento/Memento.cpp
DEMO_OBJ := $(DEMO_SRC:.cpp=.o)
DEMO_BIN := demoApp

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run r: $(BIN)
	./$(BIN)

clean c:
	rm -f $(OBJ) $(BIN) $(DEMO_OBJ) $(DEMO_BIN) vgcore.*

valgrind v: $(BIN)
	valgrind --leak-check=full --track-origins=yes ./$(BIN)

demo: $(DEMO_BIN)
	./demoApp

$(DEMO_BIN): $(DEMO_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Leaks target (macOS only, runs demoApp and checks for leaks)
leaks: $(DEMO_BIN)
	leaks --atExit -- ./$(DEMO_BIN)