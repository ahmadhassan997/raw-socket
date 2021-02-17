//
// Created by ahmad on 2/9/21.
//
#include <iostream>
#include "Parser.h"
#include "Log.h"
#include "ProgramState.h"

int main(int argc, char* argv[])
{
    Parser cmd_parser;
    cmd_parser.parseArgs(argc, argv);
    ProgramState current_program_state = cmd_parser.storeArgs();
    return 0;
}

