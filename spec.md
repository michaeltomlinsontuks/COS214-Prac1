# COS214 Practical 1 Specification

## Overview and Background

Design tools have become a go-to medium for sharing ideas. Students use them for projects and presentations. Businesses and influencers rely on them for creating content. And many people use them for personal projects such as invitations and event flyers. However, most of today's design tools restrict access through paid subscriptions.

This practical introduces OpenCanvas: a free-to-use design platform that gives all users full access to every feature. As a startup, the application will begin with the basics including shapes and text, with more features added as the user base grows.

To ensure the platform is both flexible and scalable from the start, you will design the system using the following design patterns: Factory Method, Template Method, Memento, and Prototype.

## Factory Method

Different shape elements can be added to the canvas. These include Rectangles, Squares and Textboxes.

### Classes and Attributes

**1. Canvas**
- Holds all of the shape elements added to the canvas to be displayed.
- **Attributes:**
    - `shapes: Shape*`

**2. ShapeFactory (Abstract Base Class)**
- **Methods:**
    - `createShape() : Shape*` - Abstract method to be implemented by concrete factories.

**3. RectangleFactory, SquareFactory, TextboxFactory (Concrete Factory Classes)**
- **Methods:**
    - `createShape() : Shape*` - Concrete implementation that instantiates and returns an object of the respective shape type (Rectangle, Square, Textbox) to be implemented by concrete factories.
    - `toString() : string` - String representation of the shape type

**4. Shape (Abstract Product Class)**
- **Attributes:**
    - `length : int`
    - `width : int`
    - `colour : string`
    - `positionX : int`
    - `positionY : int`
- These are attributes to hold the general characteristics of a shape.

**5. Rectangle, Square, Textbox (Concrete Product Classes)**
- Inherit from Shape
- Only Textbox has an additional attribute `text`. This is the text that a textbox can contain.

### Implementation Details

**Factories:**
- Each factory class should have methods to instantiate its corresponding shape type. For instance, RectangleFactory's createShape() would create and return an instance of Rectangle.

**Shape Types:**
- Implement the concrete shape classes with their specific characteristics. For example, a Textbox must have text, and a Square will have the same length and width.

## Prototype

It is common practice to copy and paste shapes when duplicates are required. This is especially useful when diagrams compromise multiple of the same shape with the same attributes.

### Classes and Attributes

**1. Shape (Abstract Product Class)**
- **Attributes:**
    - `length : int`
    - `width : int`
    - `colour : string`
    - `positionX : int`
    - `positionY : int`
- **Methods:**
    - `clone() : Shape*` - Abstract method for cloning shape objects.

**2. Rectangle, Square, Textbox (Concrete Product Classes)**
- Each class inherits all attributes from the Shape class.
- Each class implements the `+clone() : Shape*` method, enabling the creation of new shape instances with identical attributes.

### Implementation Details

**Clone Method Implementation:**
- Each concrete shape class must implement the clone() method. This method should create a new instance of the respective class and copy all attribute values from this object to the new object, ensuring a deep copy if needed.

## Template Method

Users may either want to export their design as a PNG or a PDF depending on the content they have created. OpenCanvas caters to this functionality free of charge. To create these different file types, the same process is followed, but the final step differs when the saveToFile function is called.

### Classes and Attributes

**1. ExportCanvas (Abstract Class):**
- **Attributes:**
    - `canvas : Canvas*`
- **Methods:**
    - `export() : void` - A template method for exporting the canvas to a specific file format, that outlines the sequence of events. This calls abstract methods prepareCanvas(), renderElements(), and saveToFile()
    - `prepareCanvas() : void`, `renderElements() : void`, `saveToFile() : void` - This method will be implemented differently by each concrete class.

**2. PNGExporter, PDFExporter (Concrete Classes)**
- Each class inherits from ExportCanvas
- Implements the abstract method in ExportCanvas

### Implementation Details

- Each concrete exporter class (PNGExporter, PDFExporter) needs to provide their own implementation for prepareCanvas(), renderElements(), and saveToFile().
- The export() function should contain a sequence of calls to the following functions in this order:
    1. prepareCanvas()
    2. renderElements()
    3. saveToFile()

## Memento

Instead of deleting a shape, it is a simple shortcut to just undo the last action created. This also ensures that the last item created is deleted and not some unintended item.

### Classes and Attributes

**1. Canvas**
- **Attributes:**
    - `shapes: Shape*`
- **Methods:**
    - `captureCurrent() : Memento*` - Creates a memento containing a snapshot of its current state.
    - `undoAction(prev: Memento*) : void` - Restores its state from the memento object.

**2. Memento**
- **Attributes:**
    - `shapes: Shape*`
- **Methods:**
    - `Memento(elements: Shape*)` - Initializes the memento with the state of the shapes on the canvas.

**3. CareTaker**
- **Responsibility:**
    - Manages saving and restoring of Memento objects. This class can hold a stack, list, or another collection of mementos allowing the platform to revert to any previous state.

### Implementation Details

**Define Memento and Caretaker Classes:**
- **Memento Class:**
    - Implement the constructor to take the current state of the Canvas and store it. Ensure that all the attributes from Shapes are accurately copied to preserve the state.
- **CareTaker Class:**
    - Manage a collection of Memento objects. Implement methods to add new mementos to the collection and retrieve them based on the platform's needs (the undo functionality).

**Implement Methods in Canvas Class:**
- **captureCurrent():**
    - This method should create a new Memento object initialized with the current state of the Canvas object.
- **undoAction(prev : Memento*):**
    - This method should take a Memento object and use it to restore the state of the Canvas object.