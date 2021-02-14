//
// Created by ahmad on 2/9/21.
//
#include <iostream>
#include "Parser.h"

int main(int argc, char* argv[])
{
    Parser cmd_parser;
    po::variables_map vm = cmd_parser.parseArgs(argc, argv);
    
    return 0;
}

