//
// Created by Michael Tomlinson on 2025/08/01.
//
#include <iostream>
#include "ANSI-color-codes.h"

int main() {
    // Regular colors
    std::cout << BLK << "Hello World (Black)" << CRESET << std::endl;
    std::cout << RED << "Hello World (Red)" << CRESET << std::endl;
    std::cout << GRN << "Hello World (Green)" << CRESET << std::endl;
    std::cout << YEL << "Hello World (Yellow)" << CRESET << std::endl;
    std::cout << BLU << "Hello World (Blue)" << CRESET << std::endl;
    std::cout << MAG << "Hello World (Magenta)" << CRESET << std::endl;
    std::cout << CYN << "Hello World (Cyan)" << CRESET << std::endl;
    std::cout << WHT << "Hello World (White)" << CRESET << std::endl;

    // Bold colors
    std::cout << BBLK << "Hello World (Bold Black)" << CRESET << std::endl;
    std::cout << BRED << "Hello World (Bold Red)" << CRESET << std::endl;
    std::cout << BGRN << "Hello World (Bold Green)" << CRESET << std::endl;
    std::cout << BYEL << "Hello World (Bold Yellow)" << CRESET << std::endl;
    std::cout << BBLU << "Hello World (Bold Blue)" << CRESET << std::endl;
    std::cout << BMAG << "Hello World (Bold Magenta)" << CRESET << std::endl;
    std::cout << BCYN << "Hello World (Bold Cyan)" << CRESET << std::endl;
    std::cout << BWHT << "Hello World (Bold White)" << CRESET << std::endl;

    // Underline colors
    std::cout << UBLK << "Hello World (Underline Black)" << CRESET << std::endl;
    std::cout << URED << "Hello World (Underline Red)" << CRESET << std::endl;
    std::cout << UGRN << "Hello World (Underline Green)" << CRESET << std::endl;
    std::cout << UYEL << "Hello World (Underline Yellow)" << CRESET << std::endl;
    std::cout << UBLU << "Hello World (Underline Blue)" << CRESET << std::endl;
    std::cout << UMAG << "Hello World (Underline Magenta)" << CRESET << std::endl;
    std::cout << UCYN << "Hello World (Underline Cyan)" << CRESET << std::endl;
    std::cout << UWHT << "Hello World (Underline White)" << CRESET << std::endl;

    // Regular background
    std::cout << BLKB << "Hello World (Black Background)" << CRESET << std::endl;
    std::cout << REDB << "Hello World (Red Background)" << CRESET << std::endl;
    std::cout << GRNB << "Hello World (Green Background)" << CRESET << std::endl;
    std::cout << YELB << "Hello World (Yellow Background)" << CRESET << std::endl;
    std::cout << BLUB << "Hello World (Blue Background)" << CRESET << std::endl;
    std::cout << MAGB << "Hello World (Magenta Background)" << CRESET << std::endl;
    std::cout << CYNB << "Hello World (Cyan Background)" << CRESET << std::endl;
    std::cout << WHTB << "Hello World (White Background)" << CRESET << std::endl;

    // High intensity background
    std::cout << BLKHB << "Hello World (High Intensity Black Background)" << CRESET << std::endl;
    std::cout << REDHB << "Hello World (High Intensity Red Background)" << CRESET << std::endl;
    std::cout << GRNHB << "Hello World (High Intensity Green Background)" << CRESET << std::endl;
    std::cout << YELHB << "Hello World (High Intensity Yellow Background)" << CRESET << std::endl;
    std::cout << BLUHB << "Hello World (High Intensity Blue Background)" << CRESET << std::endl;
    std::cout << MAGHB << "Hello World (High Intensity Magenta Background)" << CRESET << std::endl;
    std::cout << CYNHB << "Hello World (High Intensity Cyan Background)" << CRESET << std::endl;
    std::cout << WHTHB << "Hello World (High Intensity White Background)" << CRESET << std::endl;

    // High intensity text
    std::cout << HBLK << "Hello World (High Intensity Black)" << CRESET << std::endl;
    std::cout << HRED << "Hello World (High Intensity Red)" << CRESET << std::endl;
    std::cout << HGRN << "Hello World (High Intensity Green)" << CRESET << std::endl;
    std::cout << HYEL << "Hello World (High Intensity Yellow)" << CRESET << std::endl;
    std::cout << HBLU << "Hello World (High Intensity Blue)" << CRESET << std::endl;
    std::cout << HMAG << "Hello World (High Intensity Magenta)" << CRESET << std::endl;
    std::cout << HCYN << "Hello World (High Intensity Cyan)" << CRESET << std::endl;
    std::cout << HWHT << "Hello World (High Intensity White)" << CRESET << std::endl;

    // Bold high intensity text
    std::cout << BHBLK << "Hello World (Bold High Intensity Black)" << CRESET << std::endl;
    std::cout << BHRED << "Hello World (Bold High Intensity Red)" << CRESET << std::endl;
    std::cout << BHGRN << "Hello World (Bold High Intensity Green)" << CRESET << std::endl;
    std::cout << BHYEL << "Hello World (Bold High Intensity Yellow)" << CRESET << std::endl;
    std::cout << BHBLU << "Hello World (Bold High Intensity Blue)" << CRESET << std::endl;
    std::cout << BHMAG << "Hello World (Bold High Intensity Magenta)" << CRESET << std::endl;
    std::cout << BHCYN << "Hello World (Bold High Intensity Cyan)" << CRESET << std::endl;
    std::cout << BHWHT << "Hello World (Bold High Intensity White)" << CRESET << std::endl;

    // Intense Black on Intense Backgrounds
    std::cout << BHBLK_ON_REDHB << "Intense Black on Intense Red Background" << CRESET << std::endl;
    std::cout << BHBLK_ON_GRNHB << "Intense Black on Intense Green Background" << CRESET << std::endl;
    std::cout << BHBLK_ON_YELHB << "Intense Black on Intense Yellow Background" << CRESET << std::endl;
    std::cout << BHBLK_ON_BLUHB << "Intense Black on Intense Blue Background" << CRESET << std::endl;
    std::cout << BHBLK_ON_MAGHB << "Intense Black on Intense Magenta Background" << CRESET << std::endl;
    std::cout << BHBLK_ON_CYNHB << "Intense Black on Intense Cyan Background" << CRESET << std::endl;
    std::cout << BHBLK_ON_WHTHB << "Intense Black on Intense White Background" << CRESET << std::endl;

    return 0;
}