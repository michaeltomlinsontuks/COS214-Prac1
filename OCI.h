//
// Created by Michael Tomlinson on 2025/08/03.
// Open Canvas Interface (OCI) header file
// I decided I'm too busy to make a super CLI, this is just a switch-case number mode CLI

/*
    The plan is to have the standard Singleton stuff
        - getInstance() method
        - private constructor
        - no copy constructor or assignment operator
    Then add a run method that will handle the main loop
        - Main loop is just a switch-case that calls other sub menu loop methods
        - Sub menus call other sub menu loop methods until a command is reached
        - Commands can be a method for getting arguments
        - Commands then call a method from the canvas that does the actual work
    The canvas will be a separate class that handles the actual drawing and rendering

    Methods:
        - run() - main loop
        - displayBanner() - displays the banner
        - displayMenu() - displays the menu
            - shapeSubMenu() - displays the shape sub menu
                - addShape() - gets arguments for adding a shape and then calls the canvas method
                - removeShape() - gets arguments for removing a shape and then calls the canvas method
                - duplicateShape() - gets arguments for duplicating a shape and then calls the canvas method
                - getShapeList() - calls the canvas method to get the shape list
                - getShapeInfo() - gets arguments for getting shape info and then calls the canvas method
            - canvasSubMenu() - displays the canvas sub menu
                - clearCanvas() - calls the canvas method to clear the canvas
                - drawCanvas() - calls the canvas method to draw the canvas
                - undo() - calls the canvas method to undo the last action
                - redo() - calls the canvas method to redo the last action
            - exportSubMenu() - displays the export sub menu
                - exportPNG() - gets arguments for exporting to PNG and then calls the canvas method
                - exportPDF() - gets arguments for exporting to PDF and then calls the canvas method
            - utilitiesSubMenu() - displays the utilities sub menu
                - help() - displays the help message
                - log() - displays the log
                - quit() - exits the application
*/

#ifndef OCI_H
#define OCI_H

#include "Logger.h"
#include "ANSI-color-codes.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>


class OCI {
public:
    OCI();
    ~OCI();
    OCI(const OCI&) = delete;
    OCI& operator=(const OCI&) = delete;

    void run();
    void displayBanner() const;
    void displayMenu(int menuCode) const;

private:
    // Sub menu methods
    void shapeSubMenu();
    void addShape();
    void removeShape();
    void duplicateShape();
    void getShapeList() const;
    void getShapeInfo() const;

    void canvasSubMenu();
    void clearCanvas();
    void drawCanvas() const;
    void undo();
    void redo();

    void exportSubMenu();
    void exportPNG();
    void exportPDF();

    void utilitiesSubMenu();
    void help() const;
    void log() const;
    void quit();
    int validateNumberInput(int max) const;

    Logger* logger;  // Logger instance (singleton)
    bool running;   // Main loop control
};



#endif //OCI_H
