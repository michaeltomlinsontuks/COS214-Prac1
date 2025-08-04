//
// Created by Michael Tomlinson on 2025/08/03.
// Open Canvas Interface (OCI) cpp file
//

#include "OCI.h"

OCI::OCI() : logger(Logger::getInstance()), running(false) {}
OCI::~OCI() {}

void OCI::run() {
    logger->clearLogs(); // Clear the log at the start of the run
    running = true;
    displayBanner();
    while (running) {
        displayMenu(0);
        int choice;
        // Validate numeric user input for choice
        choice = validateNumberInput(4);
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

void OCI::displayBanner() const {
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

void OCI::displayMenu(int menuCode) const {
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
            std::cout << BHGRN << "4. " << BHWHT << "Redo" << CRESET << std::endl;
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

void OCI::addShape() {
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
        case 1: colour = "Red"; break;
        case 2: colour = "Green"; break;
        case 3: colour = "Blue"; break;
        case 4: colour = "Yellow"; break;
        case 5: colour = "Magenta"; break;
        case 6: colour = "Cyan"; break;
        case 7: colour = "White"; break;
        default: colour = "White"; break;
    }

    int x, y;
    std::cout << BHWHT << "Enter position X: " << CRESET;
    std::cin >> x;
    std::cout << BHWHT << "Enter position Y: " << CRESET;
    std::cin >> y;

    int length, width;
    std::string text;
    switch (shapeType) {
        case 1: // Rectangle
            std::cout << BHWHT << "Enter length: " << CRESET;
            std::cin >> length;
            std::cout << BHWHT << "Enter width: " << CRESET;
            std::cin >> width;
            // TODO: Call canvas->addShape(new Rectangle(...))
            break;
        case 2: // Square
            std::cout << BHWHT << "Enter side length: " << CRESET;
            std::cin >> length;
            width = length;
            // TODO: Call canvas->addShape(new Square(...))
            break;
        case 3: // Textbox
            std::cout << BHWHT << "Enter length: " << CRESET;
            std::cin >> length;
            std::cout << BHWHT << "Enter width: " << CRESET;
            std::cin >> width;
            std::cout << BHWHT << "Enter text: " << CRESET;
            std::cin.ignore(); // flush newline
            std::getline(std::cin, text);
            // TODO: Call canvas->addShape(new Textbox(...))
            break;
        default:
            std::cout << BHRED << "Invalid shape type." << CRESET << std::endl;
            return;
    }
    std::cout << BHGRN << "Shape added (not really, just a placeholder)!" << CRESET << std::endl;
    std::cout << BHWHT << "> " << CRESET;
}

void OCI::removeShape() {
    // Show list of shapes first
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
        // TODO: Call canvas->removeShape(shapeId)
        std::cout << BHGRN << "Shape removed (not really, just a placeholder)!" << CRESET << std::endl;
    } else {
        std::cout << BHYEL << "Remove cancelled." << CRESET << std::endl;
    }
    std::cout << BHWHT << "> " << CRESET;
}

void OCI::duplicateShape() {
    // Show list of shapes first
    getShapeList();
    std::cout << BHWHT << "Enter the ID of the shape to duplicate: " << CRESET;
    int shapeId;
    std::cin >> shapeId;
    if (shapeId == 0) {
        std::cout << BHYEL << "Duplicate cancelled (back selected)." << CRESET << std::endl;
        return;
    }
    // TODO: Call canvas->duplicateShape(shapeId)
    std::cout << BHGRN << "Shape duplicated (not really, just a placeholder)!" << CRESET << std::endl;
    std::cout << BHWHT << "> " << CRESET;
}

void OCI::getShapeList() const {}

void OCI::getShapeInfo() const {
    // Show list of shapes first
    getShapeList();
    std::cout << BHWHT << "Enter the ID of the shape to view info: " << CRESET;
    int shapeId;
    std::cin >> shapeId;
    if (shapeId == 0) {
        std::cout << BHYEL << "Info cancelled (back selected)." << CRESET << std::endl;
        return;
    }
    // TODO: Call canvas->getShapeInfo(shapeId)
    std::cout << BHGRN << "Shape info displayed (not really, just a placeholder)!" << CRESET << std::endl;
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
            case 4:
                redo();
                break;
            case 0:
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}

void OCI::clearCanvas() {}

void OCI::drawCanvas() const {
    // TODO: Implement drawCanvas functionality
}

void OCI::undo() {}

void OCI::redo() {}

void OCI::exportSubMenu() {
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

void OCI::exportPNG() {
    // Arguments needed: file path/name, resolution, etc.
}

void OCI::exportPDF() {
    // Arguments needed: file path/name, page size, etc.
}

void OCI::utilitiesSubMenu() {
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

void OCI::help() const {
    std::cout << BHYEL << "\nHelp - Open Canvas Interface (OCI)" << CRESET << std::endl;
    std::cout << BHWHT << "This application allows you to create, edit, and export simple canvas drawings using a menu-driven interface." << CRESET << std::endl;
    std::cout << BHWHT << "\nNavigation:" << CRESET << std::endl;
    std::cout << BHWHT << "- Use the number keys to select menu options." << CRESET << std::endl;
    std::cout << BHWHT << "- Enter '0' to go back or quit from any menu." << CRESET << std::endl;
    std::cout << BHWHT << "\nMenus:" << CRESET << std::endl;
    std::cout << BHWHT << "1. Shape Menu: Add, remove, duplicate, list, or get info about shapes." << CRESET << std::endl;
    std::cout << BHWHT << "2. Canvas Menu: Clear, draw, undo, or redo actions on the canvas." << CRESET << std::endl;
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
    // TODO: Add any cleanup or save logic if needed
}

int OCI::validateNumberInput(int max) const {
    int input;
    std::cin >> input;
    logger->log("User input (number): " + std::to_string(input), Logger::INFO, false); // Log only to file
    if (std::cin.fail() || input < 0 || input > max) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        logger->log("Invalid input: not an integer in range 0-" + std::to_string(max), logger::ERROR, false);
        std::cout << "Error: Please enter a valid number between 0 and " << max << ".\n";
        return -1;
    }
    return input;
}

void OCI::displayBanner() {
	// TODO - implement OCI::displayBanner
	throw "Not yet implemented";
}

void OCI::displayMenu(int menuCode, int menuCode) {
	// TODO - implement OCI::displayMenu
	throw "Not yet implemented";
}

void OCI::getShapeList() {
	// TODO - implement OCI::getShapeList
	throw "Not yet implemented";
}

void OCI::getShapeInfo() {
	// TODO - implement OCI::getShapeInfo
	throw "Not yet implemented";
}

void OCI::drawCanvas() {
	// TODO - implement OCI::drawCanvas
	throw "Not yet implemented";
}

void OCI::help() {
	// TODO - implement OCI::help
	throw "Not yet implemented";
}

void OCI::log() {
	// TODO - implement OCI::log
	throw "Not yet implemented";
}

int OCI::validateNumberInput(int max, int max) {
	// TODO - implement OCI::validateNumberInput
	throw "Not yet implemented";
}
