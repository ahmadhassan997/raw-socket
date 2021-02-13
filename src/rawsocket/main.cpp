//
// Created by ahmad on 2/9/21.
//
#include <iostream>
#include "VersionConfig.h"
#include "ArgumentParser.h"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        // report version
        std::cout << argv[0] << " Version " << rawsocket_VERSION_MAJOR << "."
                  << rawsocket_VERSION_MINOR << "."
                  << rawsocket_VERSION_PATCH << std::endl;
        std::cout << "Usage: " << argv[0] << " [args]" << std::endl;
        return 1;
    }

    std::cout << "Hello World!\n";
    return 0;
}

