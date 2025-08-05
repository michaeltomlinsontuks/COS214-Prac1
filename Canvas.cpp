#include "Canvas.h"

Memento* Canvas::captureCurrent() {
    Logger::getInstance()->info("Canvas::captureCurrent called");
    // TODO - implement Canvas::captureCurrent
    throw "Not yet implemented: Canvas::captureCurrent()";
}

void Canvas::undoAction(Memento* prev) {
    Logger::getInstance()->info("Canvas::undoAction called");
    (void)prev;
    throw "Not yet implemented: Canvas::undoAction(Memento*)";
}

Canvas::Canvas() {
    Logger::getInstance()->info("Canvas constructed");
    // No shapes at construction; vector is default-initialized
    width = 225;
    height = 35;
    canvasColour = BLKB; // Default background color
    generateCanvas();
}

Shape* Canvas::addShape(int shapeType, int length, int width, const std::string& colour, int x, int y, const std::string& text) {
    Logger::getInstance()->info("Canvas::addShape called with shapeType = " + std::to_string(shapeType) + ", length = " + std::to_string(length) + ", width = " + std::to_string(width) + ", colour = " + colour + ", x = " + std::to_string(x) + ", y = " + std::to_string(y) + ", text = " + text);
    Shape* newShape = nullptr;
    switch (shapeType) {
        case 1: { // Rectangle
            RectangleFactory rectFactory;
            newShape = rectFactory.createShape(length, width, colour, x, y);
            break;
        }
        case 2: { // Square
            SquareFactory squareFactory;
            newShape = squareFactory.createShape(length, width, colour, x, y);
            break;
        }
        case 3: { // Textbox
            TextboxFactory textboxFactory;
            newShape = textboxFactory.createShape(length, width, colour, x, y, text);
            break;
        }
        default:
            return nullptr;
    }
    if (newShape) {
        shapes.push_back(newShape);
    }
    return newShape;
}

void Canvas::removeShape(int shapeId) {
    Logger::getInstance()->info("Canvas::removeShape called with shapeId = " + std::to_string(shapeId));
    (void)shapeId;
    throw "Canvas::removeShape - Not yet implemented";
}

void Canvas::duplicateShape(int shapeId) {
    Logger::getInstance()->info("Canvas::duplicateShape called with shapeId = " + std::to_string(shapeId));
    (void)shapeId;
    throw "Canvas::duplicateShape - Not yet implemented";
}

vector<Shape*> Canvas::getShapeList() {
    Logger::getInstance()->info("Canvas::getShapeList called");
    return shapes;
}

Shape* Canvas::getShapeInfo(int shapeId) {
    Logger::getInstance()->info("Canvas::getShapeInfo called with shapeId = " + std::to_string(shapeId));
    (void)shapeId;
    throw "Canvas::getShapeInfo - Not yet implemented";
}

void Canvas::drawBorder() {
    // Draw top and bottom border
    std::string borderColor = BHBLK_ON_WHTHB; // White background for border
    for (int col = 0; col < width; ++col) {
        canvas[0][col] = CanvasCell(borderColor, '-');
        canvas[height-1][col] = CanvasCell(borderColor, '-');
    }
    // Draw left and right border
    for (int row = 1; row < height-1; ++row) {
        canvas[row][0] = CanvasCell(borderColor, '|');
        canvas[row][width-1] = CanvasCell(borderColor, '|');
    }
    // Corners
    canvas[0][0] = CanvasCell(borderColor, '+');
    canvas[0][width-1] = CanvasCell(borderColor, '+');
    canvas[height-1][0] = CanvasCell(borderColor, '+');
    canvas[height-1][width-1] = CanvasCell(borderColor, '+');
}

void Canvas::clear() {
    Logger::getInstance()->info("Canvas::clear called");
    canvas.clear();
    canvas.resize(height, std::vector<CanvasCell>(width, CanvasCell(canvasColour, ' ')));
    drawBorder();
}

void Canvas::draw() {
    Logger::getInstance()->info("Canvas::draw called");
    // Clear the canvas to background
    canvas.clear();
    canvas.resize(height, std::vector<CanvasCell>(width, CanvasCell(canvasColour, ' ')));

    drawBorder();

    // Draw each shape onto the canvas
    for (Shape* shape : shapes) {
        auto shapeCells = shape->draw();
        int posX = shape->getPositionX();
        int posY = shape->getPositionY();
        for (size_t i = 0; i < shapeCells.size(); ++i) {
            for (size_t j = 0; j < shapeCells[i].size(); ++j) {
                int canvasRow = posY + i;
                int canvasCol = posX + j;
                if (canvasRow >= 0 && canvasRow < height && canvasCol >= 0 && canvasCol < width) {
                    canvas[canvasRow][canvasCol] = shapeCells[i][j];
                }
            }
        }
    }

    // Print the canvas row by row, updating color only when it changes
    for (int row = 0; row < height; ++row) {
        std::string lastColor = "";
        for (int col = 0; col < width; ++col) {
            const CanvasCell& cell = canvas[row][col];
            if (cell.colorCode != lastColor) {
                std::cout << cell.colorCode;
                lastColor = cell.colorCode;
            }
            std::cout << cell.ch;
        }
        std::cout << CRESET << std::endl;
    }
}

void Canvas::generateCanvas() {
    Logger::getInstance()->info("Canvas::generateCanvas called");
    canvas.clear();
    canvas.resize(height, std::vector<CanvasCell>(width, CanvasCell(canvasColour, ' ')));
    drawBorder();
}


Canvas::~Canvas() {
    Logger::getInstance()->info("Canvas destroyed");
    // Clean up all shapes
    for (Shape* shape : shapes) {
        delete shape;
    }
    shapes.clear();
}
