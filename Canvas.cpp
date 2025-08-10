#include "Canvas.h"

Memento *Canvas::captureCurrent()
{
    Logger::getInstance()->info("Canvas::captureCurrent called");
    // Create a new Memento with the current shapes
    return new Memento(shapes);
}

void Canvas::undoAction(Memento *prev)
{
    Logger::getInstance()->info("Canvas::undoAction called");
    if (!prev)
        return;
    // Clear current shapes
    for (Shape *shape : shapes)
    {
        delete shape;
    }
    shapes.clear();
    // Restore shapes from memento (deep copy)
    for (int i = 0; i < prev->shapes->getLength(); ++i)
    {
        Shape *restored = (*prev->shapes)[i]->clone();
        shapes.push_back(restored);
    }
    generateCanvas(); // Redraw canvas with restored shapes
    delete prev;
}

Canvas::Canvas()
{
    Logger::getInstance()->info("Canvas constructed");
    // No shapes at construction; vector is default-initialized
    width = 120;
    height = 20;
    canvasColour = BLKB; // Default background color
    generateCanvas();
}

Shape *Canvas::addShape(int shapeType, int length, int width, const std::string &colour, int x, int y, const std::string &text)
{
    Logger::getInstance()->info("Canvas::addShape called with shapeType = " + std::to_string(shapeType) + ", length = " + std::to_string(length) + ", width = " + std::to_string(width) + ", colour = " + colour + ", x = " + std::to_string(x) + ", y = " + std::to_string(y) + ", text = " + text);
    Shape *newShape = nullptr;
    switch (shapeType)
    {
    case 1:
    { // Rectangle
        RectangleFactory rectFactory;
        newShape = rectFactory.createShape(length, width, colour, x, y);
        break;
    }
    case 2:
    { // Square
        SquareFactory squareFactory;
        newShape = squareFactory.createShape(length, width, colour, x, y);
        break;
    }
    case 3:
    { // Textbox
        TextboxFactory textboxFactory;
        newShape = textboxFactory.createShape(length, width, colour, x, y, text);
        break;
    }
    default:
        return nullptr;
    }
    if (newShape)
    {
        shapes.push_back(newShape);
    }
    return newShape;
}

void Canvas::removeShape(int shapeId)
{
    Logger::getInstance()->info("Canvas::removeShape called with shapeId = " + std::to_string(shapeId));
    // Delete the shape to free memory before removing from vector
    if (shapeId >= 0 && shapeId < static_cast<int>(shapes.size()))
    {
        delete shapes[shapeId];
        shapes.erase(shapes.begin() + shapeId);
    }
}

void Canvas::duplicateShape(int shapeId)
{
    Logger::getInstance()->info("Canvas::duplicateShape called with shapeId = " + std::to_string(shapeId));
    // Clones the shapeId then adds it to the shapes vector
    Shape *shape = shapes[shapeId];
    Shape *newShape = shape->clone();
    shapes.push_back(newShape);
}

vector<Shape *> Canvas::getShapeList()
{
    Logger::getInstance()->info("Canvas::getShapeList called");
    return shapes;
}

Shape *Canvas::getShapeInfo(int shapeId)
{
    Logger::getInstance()->info("Canvas::getShapeInfo called with shapeId = " + std::to_string(shapeId));

    return shapes[shapeId];
}

void Canvas::drawBorder()
{
    // Draw top and bottom border
    std::string borderColor = BHBLK_ON_WHTHB; // White background for border
    for (int col = 0; col < width; ++col)
    {
        canvas[0][col] = CanvasCell(borderColor, '-');
        canvas[height - 1][col] = CanvasCell(borderColor, '-');
    }
    // Draw left and right border
    for (int row = 1; row < height - 1; ++row)
    {
        canvas[row][0] = CanvasCell(borderColor, '|');
        canvas[row][width - 1] = CanvasCell(borderColor, '|');
    }
    // Corners
    canvas[0][0] = CanvasCell(borderColor, '+');
    canvas[0][width - 1] = CanvasCell(borderColor, '+');
    canvas[height - 1][0] = CanvasCell(borderColor, '+');
    canvas[height - 1][width - 1] = CanvasCell(borderColor, '+');
}

void Canvas::clear()
{
    Logger::getInstance()->info("Canvas::clear called");
    canvas.clear();
    canvas.resize(height, std::vector<CanvasCell>(width, CanvasCell(canvasColour, ' ')));
    drawBorder();
    // Delete all shapes to free memory before clearing the vector
    for (Shape *shape : shapes)
    {
        delete shape;
    }
    shapes.clear();
}

void Canvas::draw()
{
    Logger::getInstance()->info("Canvas::draw called");
    // Clear the canvas to background
    canvas.clear();
    canvas.resize(height, std::vector<CanvasCell>(width, CanvasCell(canvasColour, ' ')));

    drawBorder();

    // Draw each shape onto the canvas
    for (Shape *shape : shapes)
    {
        auto shapeCells = shape->draw();
        int posX = shape->getPositionX();
        int posY = shape->getPositionY();
        for (size_t i = 0; i < shapeCells.size(); ++i)
        {
            for (size_t j = 0; j < shapeCells[i].size(); ++j)
            {
                int canvasRow = posY + i;
                int canvasCol = posX + j;
                if (canvasRow >= 0 && canvasRow < height && canvasCol >= 0 && canvasCol < width)
                {
                    canvas[canvasRow][canvasCol] = shapeCells[i][j];
                }
            }
        }
    }

    // Print the canvas row by row, updating color only when it changes
    for (int row = 0; row < height; ++row)
    {
        std::string lastColor = "";
        for (int col = 0; col < width; ++col)
        {
            const CanvasCell &cell = canvas[row][col];
            if (cell.colorCode != lastColor)
            {
                std::cout << cell.colorCode;
                lastColor = cell.colorCode;
            }
            std::cout << cell.ch;
        }
        std::cout << CRESET << std::endl;
    }
}

string Canvas::exportCanvas()
{
    Logger::getInstance()->info("Canvas::draw called");
    // Clear the canvas to background
    canvas.clear();
    canvas.resize(height, std::vector<CanvasCell>(width, CanvasCell(canvasColour, ' ')));

    drawBorder();

    // Draw each shape onto the canvas
    for (Shape *shape : shapes)
    {
        auto shapeCells = shape->draw();
        int posX = shape->getPositionX();
        int posY = shape->getPositionY();
        for (size_t i = 0; i < shapeCells.size(); ++i)
        {
            for (size_t j = 0; j < shapeCells[i].size(); ++j)
            {
                int canvasRow = posY + i;
                int canvasCol = posX + j;
                if (canvasRow >= 0 && canvasRow < height && canvasCol >= 0 && canvasCol < width)
                {
                    canvas[canvasRow][canvasCol] = shapeCells[i][j];
                }
            }
        }
    }

    // Print the canvas row by row, updating color only when it changes
    string output = "";

    for (int row = 0; row < height; ++row)
    {
        std::string lastColor = "";
        for (int col = 0; col < width; ++col)
        {
            const CanvasCell &cell = canvas[row][col];
            if (cell.colorCode != lastColor)
            {
                output += cell.colorCode;
                output += cell.colorCode;
            }
            output += cell.ch;
        }
        output += CRESET;
        output += '\n';
    }
    return output;
}

void Canvas::generateCanvas()
{
    Logger::getInstance()->info("Canvas::generateCanvas called");
    canvas.clear();
    canvas.resize(height, std::vector<CanvasCell>(width, CanvasCell(canvasColour, ' ')));
    drawBorder();
}

Canvas::~Canvas()
{
    Logger::getInstance()->info("Canvas destroyed");
    // Clean up all shapes
    for (Shape *shape : shapes)
    {
        delete shape;
    }
    shapes.clear();
}
