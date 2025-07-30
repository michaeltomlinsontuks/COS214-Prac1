# Makefile for COS214-Prac1

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Source files
SRCS = TestingMain.cpp \
       Canvas.h \
       Shape.h \
       ShapeFactory.h \
       RectangleFactory.h \
       SquareFactory.h \
       TextboxFactory.h \
       Rectangle.h \
       Square.h \
       Textbox.h

# Object files (none, as all code is in headers and main)
OBJS =

# Output executable
TARGET = test_canvas

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) TestingMain.cpp -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
