//
// Created by ahmad on 2/9/21.
//

#ifndef RAWSOCKET_PARSER_H
#define RAWSOCKET_PARSER_H

#include <boost/program_options.hpp>
#include <string>
#include <iostream>

#include "VersionConfig.h"
#include "ProgramConfig.h"
#include "ProgramState.h"
#include "Log.h"

namespace po = boost::program_options;

class Parser {
public:
    Parser();
    /// load settings from command line arguments
    void parseArgs(int argc, char* argv[]);
    /// load settings from config file
    void parseArgs(std::string file_name);
    /// store argument values in program state object and do error checking
    ProgramState storeArgs();
    /// print usage
    inline void printUsage() {
        std::cout << std::endl << *desc << std::endl;
    }
private:
    po::options_description *desc;
    po::variables_map vm;
};


#endif //RAWSOCKET_PARSER_H
