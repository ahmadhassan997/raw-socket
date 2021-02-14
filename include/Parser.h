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

namespace po = boost::program_options;

class Parser {
public:
    Parser();
    /// load settings from command line arguments
    po::variables_map parseArgs(int argc, char* argv[]);
    /// load settings from config file
    po::variables_map parseArgs(std::string file_name);
    /// store parsed variables in program state object
    ProgramState storeParsedArgs(po::variables_map vm);
private:
    po::options_description *desc;
};


#endif //RAWSOCKET_PARSER_H
