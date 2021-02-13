//
// Created by ahmad on 2/9/21.
//
#include <iostream>
#include "VersionConfig.h"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        // report version
        std::cout << argv[0] << " Version " << RawSocket_VERSION_MAJOR << "."
                  << RawSocket_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " [args]" << std::endl;
        return 1;
    }

    std::cout << "Hello World!\n";
    return 0;
}

