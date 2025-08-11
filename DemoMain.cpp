//
// Created by Michael Tomlinson on 2025/07/30.
//

/*
It might be useful to have two main files: a testing main for FitchFork and a demo main with
a more user-friendly interface (e.g., a terminal menu) for demoing. This is just a suggestion,
not a requirement. You are required to have at least a testing main. If you choose to have a
demo main, upload it to FitchFork as well, but ensure it does not compile and run with make
run.
*/

#include <iostream>
#include "loggerOCI/OCI.h"
using namespace std;

/*
I want to create a Demo that will run functions in the OCI,
to demonstrate all frontend functionality then printout the log,
then it will give a switch case prompt asking if the user wants to continue - if yes the program then starts OCI run
*/

int main()
{
    OCI oci;
    // 1. Welcome and banner
    cout << "\n--- Welcome to the OCI Demo Mode ---\n"
         << endl;
    oci.displayBanner();

    // 2. Show empty canvas
    cout << "\nInitial empty canvas:" << endl;
    oci.drawCanvas();

    // 3. Add a rectangle
    cout << "\nAdding a rectangle..." << endl;
    oci.canvas->addShape(1, 4, 2, "\033[1;41m", 1, 1, ""); // Rectangle, length=4, width=2, red, x=1, y=1
    oci.drawCanvas();

    // 4. Add a square
    cout << "\nAdding a square..." << endl;
    oci.canvas->addShape(2, 3, 3, "\033[1;42m", 5, 2, ""); // Square, side=3, green, x=5, y=2
    oci.drawCanvas();

    // 5. Add a textbox
    cout << "\nAdding a textbox..." << endl;
    oci.canvas->addShape(3, 6, 2, "\033[1;44m", 2, 5, "Hi!"); // Textbox, length=6, width=2, blue, x=2, y=5, text="Hi!"
    oci.drawCanvas();

    // 6. List shapes
    cout << "\nCurrent shapes on canvas:" << endl;
    oci.getShapeList();

    // 7. Duplicate the first shape
    cout << "\nDuplicating the second shape..." << endl;
    oci.canvas->duplicateShape(1);
    oci.drawCanvas();
    oci.getShapeList();
    oci.canvas->captureCurrent();
    cout << "Capturing current"<<endl;

    // 8. Remove the second shape
    cout << "\nRemoving the second shape..." << endl;
    oci.canvas->removeShape(1);
    oci.drawCanvas();

    cout << "\nRemoving the duplicate shape..." << endl;
    oci.canvas->removeShape(2);
    oci.drawCanvas();

    cout << "\nUndoing the last action..." << endl;
    oci.undo();
    oci.drawCanvas();

    // 9. Clear the canvas
    cout << "\nClearing the canvas..." << endl;
    oci.clearCanvas();
    oci.drawCanvas();

    // 10. Export (stub)
    cout << "\nExporting as PNG (stub)..." << endl;
    oci.exportPNG();
    cout << "Exporting as PDF (stub)..." << endl;
    oci.exportPDF();

    // 11. Show log
    cout << "\n--- Demo Log ---" << endl;
    oci.log();

    // 12. Prompt user to continue
    int choice = -1;
    while (choice != 0 && choice != 1)
    {
        cout << "\nWould you like to continue to the interactive menu? (1 = Yes, 0 = No): ";
        cin >> choice;
        if (cin.fail() || (choice != 0 && choice != 1))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter 1 or 0." << endl;
        }
    }
    if (choice == 1)
    {
        oci.run();
    }
    else
    {
        cout << "Exiting demo. Goodbye!" << endl;
    }
    return 0;
}