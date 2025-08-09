CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g --coverage 
LDFLAGS = -lgcov

SRC = loggerOCI/OCI.cpp \
      TestingMain.cpp \
      loggerOCI/Logger.cpp \
      canvas/Canvas.cpp \
      shapes/Rectangle.cpp \
      factories/RectangleFactory.cpp \
      shapes/Square.cpp \
      factories/SquareFactory.cpp \
      shapes/Textbox.cpp \
      factories/TextboxFactory.cpp \
      memento/Memento.cpp \
      TestingFramework/array.cpp \
      shapes/Shape.cpp \
      memento/Caretaker.cpp \
      exporter/PDFExporter.cpp \
      exporter/ExportCanvas.cpp \
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

# Default build
all: $(BIN)

# Link object files into binary
$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ 

# Compile each source file with coverage flags
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@  



# Run the binary
run r: $(BIN)
	./$(BIN)

# Clean build artifacts
clean c:
	find . -name '*.o' -delete
	rm -f $(BIN) vgcore.*
	find . -name '*.gcno' -delete
	find . -name '*.gcda' -delete
	find . -name '*.gcov' -delete

# Run with Valgrind
valgrind v: $(BIN)
	valgrind --leak-check=full --track-origins=yes ./$(BIN)

coverage cov: all
	./$(BIN)
	gcovr --root . \
          --exclude '.*\.h' \
          --exclude '.*TestingFramework/.*' \
          --exclude '.*loggerOCI/.*' \
          --print-summary > coverage.txt

# Clean coverage artifacts
