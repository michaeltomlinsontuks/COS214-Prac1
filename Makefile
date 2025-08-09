CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -fprofile-arcs -ftest-coverage
LDFLAGS = -lgcov

SRC = loggerOCI/OCI.cpp \
      testMain.cpp \
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
	rm *.gz

# Run with Valgrind
valgrind v: $(BIN)
	valgrind --leak-check=full --track-origins=yes ./$(BIN)

# Generate coverage reports with gcov
coverage cov: $(BIN)
	./$(BIN)
	@echo "Generating coverage.txt..."
	@gcov -f -m -r -j $(SRC) > coverage.txt

# Clean coverage artifacts
clean-coverage c-cov:
	find . -name '*.gcno' -delete
	find . -name '*.gcda' -delete
	find . -name '*.gcov' -delete
	rm *.gz
