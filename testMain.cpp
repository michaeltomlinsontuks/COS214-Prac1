//
// Created by Michael Tomlinson on 2025/08/03.
//
#include <iostream>
#include <string>
#include "loggerOCI/ANSI-color-codes.h"
#include "loggerOCI/OCI.h"

int main()
{
    try
    {
        OCI oci;
        oci.run();
    }
    catch (const char *msg)
    {
        std::cerr << "Exception: " << msg << std::endl;
    }
    return 0;
}
