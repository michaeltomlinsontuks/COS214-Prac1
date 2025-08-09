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

int main() {
    OCI oci;
    oci.run();
    return 0;

}