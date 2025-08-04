# Class Diagram (Mermaid)

```mermaid
classDiagram
    class Shape {
        <<abstract>>
        - int length
        - int width
        - string colour
        - int positionX
        - int positionY
        + clone()
    }
    class Rectangle {
        + clone()
    }
    class Square {
        + clone()
    }
    class Textbox {
        - string text
        + clone()
    }
    class ShapeFactory {
        <<abstract>>
        + createShape() Shape*
    }
    class RectangleFactory {
        + createShape() Shape*
        + toString() string
    }
    class SquareFactory {
        + createShape() Shape*
        + toString() string
    }
    class TextboxFactory {
        + createShape() Shape*
        + toString() string
    }
    class Canvas {
        - vector~Shape*~ shapes
        + addShape(Shape*)
        + removeShape(int)
        + duplicateShape(int)
        + getShapeList()
        + getShapeInfo(int)
        + clear()
        + draw()
        + captureCurrent() Memento*
        + undoAction(Memento*)
    }
    class Memento {
        - vector~Shape*~ shapes
        + Memento(vector~Shape*~)
        + getShapes() vector~Shape*~
    }
    class CareTaker {
        - vector~Memento*~ undoStack
        - vector~Memento*~ redoStack
        + save(Memento*)
        + undo() Memento*
        + redo() Memento*
        + clear()
    }
    class Logger {
        - string logFileName
        - ofstream logFile
        + getInstance()
        + log(string, LogLevel)
        + clearLogs()
        + printLogFile()
        + printRaw(string)
    }
    class ExportCanvas {
        <<abstract>>
        - Canvas* canvas
        + export()
        + prepareCanvas()
        + renderElements()
        + saveToFile()
    }
    class PNGExporter {
        + prepareCanvas()
        + renderElements()
        + saveToFile()
    }
    class PDFExporter {
        + prepareCanvas()
        + renderElements()
        + saveToFile()
    }
    class OCI {
        - Logger* logger
        - Canvas* canvas
        - CareTaker* caretaker
        - bool running
        + run()
        + displayBanner()
        + displayMenu(int)
        + shapeSubMenu()
        + addShape()
        + removeShape()
        + duplicateShape()
        + getShapeList()
        + getShapeInfo()
        + canvasSubMenu()
        + clearCanvas()
        + drawCanvas()
        + undo()
        + redo()
        + exportSubMenu()
        + exportPNG()
        + exportPDF()
        + utilitiesSubMenu()
        + help()
        + log()
        + quit()
        + validateNumberInput(int)
    }
    Shape <|-- Rectangle
    Shape <|-- Square
    Shape <|-- Textbox
    ShapeFactory <|-- RectangleFactory
    ShapeFactory <|-- SquareFactory
    ShapeFactory <|-- TextboxFactory
    Canvas o-- Shape
    Canvas --> Memento
    CareTaker o-- Memento
    ExportCanvas <|-- PNGExporter
    ExportCanvas <|-- PDFExporter
    OCI --> Logger
    OCI --> Canvas
    OCI --> CareTaker
```

---

This Mermaid diagram now includes the Factory Method pattern with ShapeFactory and its concrete factories, as well as all other required design patterns and relationships for the Open Canvas Interface (OCI) system.
