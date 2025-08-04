//
// Created by Michael Tomlinson on 2025/08/04.
//
// Used to test the canvas drawing functionality

// These are the only libraries allowed
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Canvas {
private:
    int width, height;
    vector<vector<char>> canvas; // 3D array flattened to 2D: [row][col*3 + offset]

    // Color codes mapping
    map<char, string> colorCodes = {
        {'R', "\033[41m"}, // Red background
        {'G', "\033[42m"}, // Green background
        {'B', "\033[44m"}, // Blue background
        {'Y', "\033[43m"}, // Yellow background
        {'M', "\033[45m"}, // Magenta background
        {'C', "\033[46m"}, // Cyan background
        {'W', "\033[47m"}, // White background
        {'c', "\033[40m"}, // Black background (default)
        {'e', "\033[0m"}   // Reset/escape
    };

public:
    Canvas(int w, int h) : width(w), height(h) {
        // Initialize canvas with default background (black with space character)
        canvas.resize(height, vector<char>(width * 3));
        clear();
    }

    void clear() {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int baseIndex = x * 3;
                canvas[y][baseIndex] = 'c';     // Black background
                canvas[y][baseIndex + 1] = ' '; // Space character
                canvas[y][baseIndex + 2] = 'e'; // Reset escape
            }
        }
    }

    void setPixel(int x, int y, char color, char character = ' ') {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            int baseIndex = x * 3;
            canvas[y][baseIndex] = color;
            canvas[y][baseIndex + 1] = character;
            canvas[y][baseIndex + 2] = 'e';
        }
    }

    void drawRectangle(int startX, int startY, int rectWidth, int rectHeight, char color, char fillChar = ' ') {
        for (int y = startY; y < startY + rectHeight && y < height; y++) {
            for (int x = startX; x < startX + rectWidth && x < width; x++) {
                if (x >= 0 && y >= 0) {
                    setPixel(x, y, color, fillChar);
                }
            }
        }
    }

    void drawSquare(int startX, int startY, int size, char color, char fillChar = ' ') {
        drawRectangle(startX, startY, size, size, color, fillChar);
    }

    void drawRectangleOutline(int startX, int startY, int rectWidth, int rectHeight, char color, char borderChar = '#') {
        // Top and bottom borders
        for (int x = startX; x < startX + rectWidth && x < width; x++) {
            if (x >= 0) {
                if (startY >= 0 && startY < height) setPixel(x, startY, color, borderChar);
                if (startY + rectHeight - 1 >= 0 && startY + rectHeight - 1 < height)
                    setPixel(x, startY + rectHeight - 1, color, borderChar);
            }
        }

        // Left and right borders
        for (int y = startY; y < startY + rectHeight && y < height; y++) {
            if (y >= 0) {
                if (startX >= 0 && startX < width) setPixel(startX, y, color, borderChar);
                if (startX + rectWidth - 1 >= 0 && startX + rectWidth - 1 < width)
                    setPixel(startX + rectWidth - 1, y, color, borderChar);
            }
        }
    }

    void drawSquareOutline(int startX, int startY, int size, char color, char borderChar = '#') {
        drawRectangleOutline(startX, startY, size, size, color, borderChar);
    }

    string render() {
        string output = "";

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int baseIndex = x * 3;
                char colorCode = canvas[y][baseIndex];
                char character = canvas[y][baseIndex + 1];
                char escapeCode = canvas[y][baseIndex + 2];

                // Add color code, character, and escape sequence
                output += "[" + string(1, colorCode) + "]";
                output += "[" + string(1, character) + "]";
                output += "[" + string(1, escapeCode) + "]";
            }
            output += "\n";
        }

        return output;
    }

    string renderWithColors() {
        string output = "";

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int baseIndex = x * 3;
                char colorCode = canvas[y][baseIndex];
                char character = canvas[y][baseIndex + 1];

                // Apply actual color codes
                if (colorCodes.find(colorCode) != colorCodes.end()) {
                    output += colorCodes[colorCode];
                }
                output += character;
                output += colorCodes['e']; // Reset after each character
            }
            output += "\n";
        }

        return output;
    }

    void printCanvas() {
        cout << render();
    }

    void printCanvasWithColors() {
        cout << renderWithColors();
    }

    int getWidth() const { return width; }
    int getHeight() const { return height; }
};

int main() {
    // Create a 10x8 canvas
    Canvas canvas(10, 8);

    cout << "Empty Canvas:" << endl;
    canvas.printCanvas();
    cout << endl;

    // Draw a 3x2 blue rectangle at position (1,1)
    canvas.drawRectangle(1, 1, 3, 2, 'B');

    cout << "Canvas with 3x2 Blue Rectangle at (1,1):" << endl;
    canvas.printCanvas();
    cout << endl;

    // Draw a 2x2 red square at position (6,3)
    canvas.drawSquare(6, 3, 2, 'R', '*');

    cout << "Canvas with Blue Rectangle and Red Square:" << endl;
    canvas.printCanvas();
    cout << endl;

    // Draw a green rectangle outline
    canvas.drawRectangleOutline(0, 5, 5, 3, 'G', '=');

    cout << "Canvas with additional Green Rectangle Outline:" << endl;
    canvas.printCanvas();
    cout << endl;

    // Clear and draw the example from your comment
    canvas.clear();
    canvas.drawRectangle(0, 0, 2, 3, 'B');

    cout << "Example 2x3 Blue Rectangle at (0,0) on 5x5 canvas:" << endl;
    Canvas smallCanvas(5, 5);
    smallCanvas.drawRectangle(0, 0, 2, 3, 'B');
    smallCanvas.printCanvas();
    cout << endl;

    // Demonstrate colored output (if terminal supports ANSI colors)
    cout << "Colored output (if your terminal supports ANSI colors):" << endl;
    smallCanvas.printCanvasWithColors();

    return 0;
}

/*
    [c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e]
    [c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e]
    [c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e]
    [c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e]
    [c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e]
    [c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e]
    [c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e]
    [c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e][c][C][e]
*/

// Eg. 2x3 Blue Rectangle - drawn at 0,0 start coords
// [B][ ][e][B][ ][e][B][ ][e]
// [B][ ][e][B][ ][e][B][ ][e]
// The above represents a 2x3 rectangle with blue background colour
// Drawn on a 5x5 canvas
//




// Canvas char double array is generated with an escape for every third character
// The first character is the colour code, the second is the character to be drawn, and the third is the escape code to reset the colour
// So a 100x100 canvas would be represented as a 100x300 char array - not the most efficient but it should be much easier to work with
// Assembling the string is then just a matter of looping through the array and concatenating the strings together with a newline character at the end of each row - Implement draw rectangle, square and canvas functionality