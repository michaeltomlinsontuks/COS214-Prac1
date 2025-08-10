//
// Created by Michael Tomlinson on 2025/08/03.
// Open Canvas Interface (OCI) cpp file
//

#include "OCI.h"

OCI::OCI() : logger(Logger::getInstance()), running(false) {
    canvas = new Canvas();
    current = canvas->captureCurrent();
    caretaker = new Caretaker();
    caretaker->addMemento(current);
}
OCI::~OCI() {
    delete canvas;
}

void OCI::run() {
    logger->clearLogs(); // Clear the log at the start of the run
    running = true;
    displayBanner();
    while (running) {
        displayMenu(0);
        const int choice = validateNumberInput(4);
        switch (choice) {
            case 1:
                shapeSubMenu();
                break;
            case 2:
                canvasSubMenu();
                break;
            case 3:
                exportSubMenu();
                break;
            case 4:
                utilitiesSubMenu();
                break;
            case 0:
                quit();
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}

void OCI::displayBanner() {
    std::string rawText = "Open Canvas Interface (OCI)";
    size_t textLength = rawText.length();
    size_t padding = 3; // spaces left and right of text
    size_t bannerWidth = textLength + padding * 2;
    std::string topBorder = BHBLU;
    topBorder += "╔";
    for (size_t i = 0; i < bannerWidth; ++i) topBorder += "═";
    topBorder += "╗";
    topBorder += CRESET;
    std::string bottomBorder = BHBLU;
    bottomBorder += "╚";
    for (size_t i = 0; i < bannerWidth; ++i) bottomBorder += "═";
    bottomBorder += "╝";
    bottomBorder += CRESET;
    // Center the text
    std::string middleLine = BHBLU;
    middleLine += "║";
    middleLine += CRESET;
    for (size_t i = 0; i < padding; ++i) middleLine += " ";
    middleLine += BHWHT;
    middleLine += rawText;
    middleLine += CRESET;
    for (size_t i = 0; i < padding; ++i) middleLine += " ";
    middleLine += BHBLU;
    middleLine += "║";
    middleLine += CRESET;
    std::cout << topBorder << std::endl;
    std::cout << middleLine << std::endl;
    std::cout << bottomBorder << std::endl;
}

void OCI::displayMenu(int menuCode) {
    switch (menuCode) {
        case 0:
            std::cout << BHYEL << "\nMain Menu:" << CRESET << std::endl;
            std::cout << BHGRN << "1. " << BHWHT << "Shape Menu" << CRESET << std::endl;
            std::cout << BHGRN << "2. " << BHWHT << "Canvas Menu" << CRESET << std::endl;
            std::cout << BHGRN << "3. " << BHWHT << "Export Menu" << CRESET << std::endl;
            std::cout << BHGRN << "4. " << BHWHT << "Utilities Menu" << CRESET << std::endl;
            std::cout << BHRED << "0. Quit" << CRESET << std::endl;
            std::cout << std::endl;
            std::cout << BHWHT << "> " << CRESET;
            break;
        case 1:
            std::cout << BHYEL << "\nShape Menu:" << CRESET << std::endl;
            std::cout << BHGRN << "1. " << BHWHT << "Add Shape" << CRESET << std::endl;
            std::cout << BHGRN << "2. " << BHWHT << "Remove Shape" << CRESET << std::endl;
            std::cout << BHGRN << "3. " << BHWHT << "Duplicate Shape" << CRESET << std::endl;
            std::cout << BHGRN << "4. " << BHWHT << "List Shapes" << CRESET << std::endl;
            std::cout << BHGRN << "5. " << BHWHT << "Shape Info" << CRESET << std::endl;
            std::cout << BHRED << "0. Back" << CRESET << std::endl;
            std::cout << std::endl;
            std::cout << BHWHT << "> " << CRESET;
            break;
        case 2:
            std::cout << BHYEL << "\nCanvas Menu:" << CRESET << std::endl;
            std::cout << BHGRN << "1. " << BHWHT << "Clear Canvas" << CRESET << std::endl;
            std::cout << BHGRN << "2. " << BHWHT << "Draw Canvas" << CRESET << std::endl;
            std::cout << BHGRN << "3. " << BHWHT << "Undo" << CRESET << std::endl;
            std::cout << BHRED << "0. Back" << CRESET << std::endl;
            std::cout << std::endl;
            std::cout << BHWHT << "> " << CRESET;
            break;
        case 3:
            std::cout << BHYEL << "\nExport Menu:" << CRESET << std::endl;
            std::cout << BHGRN << "1. " << BHWHT << "Export as PNG" << CRESET << std::endl;
            std::cout << BHGRN << "2. " << BHWHT << "Export as PDF" << CRESET << std::endl;
            std::cout << BHRED << "0. Back" << CRESET << std::endl;
            std::cout << std::endl;
            std::cout << BHWHT << "> " << CRESET;
            break;
        case 4:
            std::cout << BHYEL << "\nUtilities Menu:" << CRESET << std::endl;
            std::cout << BHGRN << "1. " << BHWHT << "Help" << CRESET << std::endl;
            std::cout << BHGRN << "2. " << BHWHT << "Log" << CRESET << std::endl;
            std::cout << BHRED << "0. Back" << CRESET << std::endl;
            std::cout << std::endl;
            std::cout << BHWHT << "> " << CRESET;
            break;
        default:
            std::cout << BHRED << "\nUnknown menu." << CRESET << std::endl;
            std::cout << std::endl;
            std::cout << BHWHT << "> " << CRESET;
            break;
    }
}

void OCI::shapeSubMenu() {
    while (true) {
        displayMenu(1);
        int choice = validateNumberInput(5);
        if (choice == -1) continue;
        switch (choice) {
            case 1:
                addShape();
                break;
            case 2:
                removeShape();
                break;
            case 3:
                duplicateShape();
                break;
            case 4:
                getShapeList();
                break;
            case 5:
                getShapeInfo();
                break;
            case 0:
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}

void OCI::addShape(){
    std::cout << BHYEL << "\nAdd Shape" << CRESET << std::endl;
    std::cout << BHWHT << "Select shape type:" << CRESET << std::endl;
    std::cout << BHGRN << "1. Rectangle\n2. Square\n3. Textbox" << CRESET << std::endl;
    int shapeType = validateNumberInput(3);
    if (shapeType == -1) return;

    std::cout << BHWHT << "Select colour:" << CRESET << std::endl;
    std::cout << BHGRN << "1. Red\n2. Green\n3. Blue\n4. Yellow\n5. Magenta\n6. Cyan\n7. White" << CRESET << std::endl;
    int colourChoice = validateNumberInput(7);
    if (colourChoice == -1) return;
    std::string colour;
    switch (colourChoice) {
        case 1: colour = REDHB; break;
        case 2: colour = GRNHB; break;
        case 3: colour = BLUHB; break;
        case 4: colour = YELHB; break;
        case 5: colour = MAGHB; break;
        case 6: colour = CYNHB; break;
        case 7: colour = WHTHB; break;
        default: colour = WHTHB; break;
    }

    int x, y;
    do {
        std::cout << BHWHT << "Enter position X (>=0): " << CRESET;
        std::cin >> x;
        if (x < 0) std::cout << BHRED << "X must be greater than or equal to 0." << CRESET << std::endl;
    } while (x < 0);
    do {
        std::cout << BHWHT << "Enter position Y (>=0): " << CRESET;
        std::cin >> y;
        if (y < 0) std::cout << BHRED << "Y must be greater than or equal to 0." << CRESET << std::endl;
    } while (y < 0);

    int length = 0, width = 0;
    std::string text;
    switch (shapeType) {
        case 1: // Rectangle
            do {
                std::cout << BHWHT << "Enter length (>0): " << CRESET;
                std::cin >> length;
                if (length <= 0) std::cout << BHRED << "Length must be greater than 0." << CRESET << std::endl;
            } while (length <= 0);
            do {
                std::cout << BHWHT << "Enter width (>0): " << CRESET;
                std::cin >> width;
                if (width <= 0) std::cout << BHRED << "Width must be greater than 0." << CRESET << std::endl;
            } while (width <= 0);
            break;
        case 2: // Square
            do {
                std::cout << BHWHT << "Enter side length (>0): " << CRESET;
                std::cin >> length;
                if (length <= 0) std::cout << BHRED << "Side length must be greater than 0." << CRESET << std::endl;
            } while (length <= 0);
            width = length;
            break;
        case 3: // Textbox
            do {
                std::cout << BHWHT << "Enter length (>0): " << CRESET;
                std::cin >> length;
                if (length <= 0) std::cout << BHRED << "Length must be greater than 0." << CRESET << std::endl;
            } while (length <= 0);
            do {
                std::cout << BHWHT << "Enter width (>0): " << CRESET;
                std::cin >> width;
                if (width <= 0) std::cout << BHRED << "Width must be greater than 0." << CRESET << std::endl;
            } while (width <= 0);
            do {
                std::cout << BHWHT << "Enter text: " << CRESET;
                std::cin.ignore();
                std::getline(std::cin, text);
                if ((int)text.length() > width) {
                    std::cout << BHRED << "Text is too long for the textbox width. Please enter text with " << width << " or fewer characters." << CRESET << std::endl;
                }
            } while ((int)text.length() > width);
            break;
        default:
            std::cout << BHRED << "Invalid shape type." << CRESET << std::endl;
            return;
    }
    Shape* newShape = canvas->addShape(shapeType, length, width, colour, x, y, text);
    if (newShape) {
        std::cout << BHGRN << "Shape added!" << CRESET << std::endl;
    } else {
        std::cout << BHRED << "Failed to add shape." << CRESET << std::endl;
    }
    std::cout << BHWHT << "> " << CRESET;
    current = canvas->captureCurrent();
    caretaker->addMemento(current);
}

void OCI::removeShape(){
    getShapeList();
    std::cout << BHWHT << "Enter the ID of the shape to remove: " << CRESET;
    int shapeId;
    std::cin >> shapeId;
    if (shapeId == 0) {
        std::cout << BHYEL << "Remove cancelled (back selected)." << CRESET << std::endl;
        return;
    }
    std::cout << BHYEL << "Are you sure you want to remove shape " << shapeId << "? (y/n): " << CRESET;
    char confirm;
    std::cin >> confirm;
    if (confirm == 'y' || confirm == 'Y') {
        canvas->removeShape(shapeId);
        std::cout << BHGRN << "Shape removed!" << CRESET << std::endl;
    } else {
        std::cout << BHYEL << "Remove cancelled." << CRESET << std::endl;
    }
    std::cout << BHWHT << "> " << CRESET;
    current = canvas->captureCurrent();
    caretaker->addMemento(current);
}

void OCI::duplicateShape(){
    getShapeList();
    std::cout << BHWHT << "Enter the ID of the shape to duplicate: " << CRESET;
    int shapeId;
    std::cin >> shapeId;
    if (shapeId == 0) {
        std::cout << BHYEL << "Duplicate cancelled (back selected)." << CRESET << std::endl;
        return;
    }
    canvas->duplicateShape(shapeId);
    std::cout << BHGRN << "Shape duplicated!" << CRESET << std::endl;
    std::cout << BHWHT << "> " << CRESET;
    current = canvas->captureCurrent();
    caretaker->addMemento(current);
}

void OCI::getShapeList() const {
    std::vector<Shape*> shapes = canvas->getShapeList();
    if (shapes.empty()) {
        std::cout << BHYEL << "No shapes on the canvas." << CRESET << std::endl;
        return;
    }
    std::cout << BHGRN << "\nShape List:" << CRESET << std::endl;
    int id = 1;
    for (Shape* shape : shapes) {
        // For now, just print the pointer and typeid. You can extend this with a getInfo() method on Shape.
        std::cout << BHWHT << "[" << id << "] " << typeid(*shape).name() << " at " << shape << CRESET << std::endl;
        id++;
    }
}

void OCI::getShapeInfo() const {
    getShapeList();
    std::cout << BHWHT << "Enter the ID of the shape to view info: " << CRESET;
    int shapeId;
    std::cin >> shapeId;
    if (shapeId == 0) {
        std::cout << BHYEL << "Info cancelled (back selected)." << CRESET << std::endl;
        return;
    }
    Shape* info = canvas->getShapeInfo(shapeId);
    if (info) {
        std::cout << BHGRN << "Shape info displayed! (override this to print details)" << CRESET << std::endl;
    } else {
        std::cout << BHRED << "Invalid shape ID." << CRESET << std::endl;
    }
    std::cout << BHWHT << "> " << CRESET;
}

void OCI::canvasSubMenu() {
    while (true) {
        displayMenu(2);
        int choice = validateNumberInput(4);
        if (choice == -1) continue;
        switch (choice) {
            case 1:
                clearCanvas();
                break;
            case 2:
                drawCanvas();
                break;
            case 3:
                undo();
                break;
            case 0:
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}

void OCI::clearCanvas() const{
    canvas->clear();
    std::cout << BHGRN << "Canvas cleared!" << CRESET << std::endl;
}

void OCI::drawCanvas() const {
    canvas->draw();
    std::cout << BHGRN << "Canvas drawn!" << CRESET << std::endl;
}

void OCI::exportSubMenu() const{
    while (true) {
        displayMenu(3);
        int choice = validateNumberInput(2);
        if (choice == -1) continue;
        switch (choice) {
            case 1:
                exportPNG();
                break;
            case 2:
                exportPDF();
                break;
            case 0:
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}

void OCI::exportPNG() const{
    PNGExporter* pngExporter = new PNGExporter(canvas);
    pngExporter->exportToFile();
    delete pngExporter;
}

void OCI::exportPDF() const{
    PDFExporter* pdfExporter = new PDFExporter(canvas);
    pdfExporter->exportToFile();
    delete pdfExporter;
}

void OCI::utilitiesSubMenu() const{
    while (true) {
        displayMenu(4);
        int choice = validateNumberInput(2);
        if (choice == -1) continue;
        switch (choice) {
            case 1:
                help();
                break;
            case 2:
                log();
                break;
            case 0:
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}

void OCI::help() {
    std::cout << BHYEL << "\nHelp - Open Canvas Interface (OCI)" << CRESET << std::endl;
    std::cout << BHWHT << "This application allows you to create, edit, and export simple canvas drawings using a menu-driven interface." << CRESET << std::endl;
    std::cout << BHWHT << "\nNavigation:" << CRESET << std::endl;
    std::cout << BHWHT << "- Use the number keys to select menu options." << CRESET << std::endl;
    std::cout << BHWHT << "- Enter '0' to go back or quit from any menu." << CRESET << std::endl;
    std::cout << BHWHT << "\nMenus:" << CRESET << std::endl;
    std::cout << BHWHT << "1. Shape Menu: Add, remove, duplicate, list, or get info about shapes." << CRESET << std::endl;
    std::cout << BHWHT << "2. Canvas Menu: Clear, draw or undo actions on the canvas." << CRESET << std::endl;
    std::cout << BHWHT << "3. Export Menu: Export your canvas as PNG or PDF." << CRESET << std::endl;
    std::cout << BHWHT << "4. Utilities Menu: Access help or view the log." << CRESET << std::endl;
    std::cout << BHWHT << "\nTips:" << CRESET << std::endl;
    std::cout << BHWHT << "- Input is validated; if you enter an invalid option, you'll be prompted again." << CRESET << std::endl;
    std::cout << BHWHT << "- For shape operations, follow the prompts to enter required details (type, color, position, etc.)." << CRESET << std::endl;
    std::cout << BHWHT << "- Use the log to review recent actions." << CRESET << std::endl;
    std::cout << std::endl;
}

void OCI::log() const {
    logger->printLogFile();
}

void OCI::quit() {
    running = false;
    std::cout << BHYEL << "Exiting Open Canvas Interface. Goodbye!" << CRESET << std::endl;
}

int OCI::validateNumberInput(const int max) const {
    int input;
    std::cin >> input;
    logger->info("User input (number): " + std::to_string(input));
    if (std::cin.fail() || input < 0 || input > max) {
        logger->error("Invalid input: not an integer in range 0-" + std::to_string(max));
        std::cout << "Error: Please enter a valid number between 0 and " << max << ".\n";
        return -1;
    }
    return input;
}

void OCI::undo() {
    canvas->undoAction(caretaker->getMemento());
}