# Class Diagram (Mermaid)

```mermaid
classDiagram
    class Shape {
        <<abstract>>
        - int id
        - int x
        - int y
        - string colour
        + draw()
        + clone()
        + getInfo()
    }
    class Rectangle {
        - int length
        - int width
        + draw()
        + clone()
        + getInfo()
    }
    class Square {
        - int side
        + draw()
        + clone()
        + getInfo()
    }
    class Textbox {
        - int length
        - int width
        - string text
        + draw()
        + clone()
        + getInfo()
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
    Canvas o-- Shape
    Canvas --> Memento
    CareTaker o-- Memento
    OCI --> Logger
    OCI --> Canvas
    OCI --> CareTaker
```

---

This Mermaid diagram represents the class structure and relationships for the Open Canvas Interface (OCI) system, using std::vector for all stack and collection types, in compliance with the allowed libraries.
