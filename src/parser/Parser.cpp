//
// Created by ahmad on 2/9/21.
//

#include "Parser.h"

/**
 * @brief Construct a new Parser:: Parser object
 * specify argument list here
 */
Parser::Parser() {
    // Declare supported options
    std::string program_desc = "rawsocket Version " + std::to_string(rawsocket_VERSION_MAJOR) + "." 
                                + std::to_string(rawsocket_VERSION_MINOR) + "." + std::to_string(rawsocket_VERSION_PATCH) + "\n\n"
                                + "Usage as client: ./rawsocket -c ip:port [options]\n"
                                + "Usage as server: ./rawsocket -s ip:port [options]\n\n"
                                + "Available Options";
    desc = new po::options_description(program_desc);
    desc->add_options()
        ("help,h", "print help message")
        ("server,s", po::value<std::string>(), "ip address and port to listen on (for server)")
        ("client,c", po::value<std::string>(), "ip address and port to connect to (for client)")
        ("auto-ip-rule,a", "add/delete iptable rules automatically for raw socket mode")
        ("gen-ip-rule,g", "generate and print iptable rules for raw socket mode")
        ("raw-mode", po::value<std::string>()->default_value("raw-tcp"), 
                                "raw socket type: raw-tcp[default], raw-udp, raw-icmp, tcp, udp, icmp")
        ("log-level", po::value<std::string>()->default_value("info"), 
                                "log level: never, error, warn, info[default], debug, verbose")
        ("log-position", "enable file name, function name and line name in logs")
        ("source-ip", po::value<std::string>(), "source ip address (for client)")
        ("source-port", po::value<std::string>(), "source port for client")
    ;
}

/**
 * @brief Parse arguments from command line
 * 
 * @param argc 
 * @param argv 
 * @return po::variables_map 
 */
po::variables_map Parser::parseArgs(int argc, char* argv[]) {
    if (argc < 2)   // if no argument given
    { 
        std::cout << *desc << std::endl;
        exit(0);
    }
    else   // parse the command line arguments
    {
        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, *desc), vm);
        po::notify(vm);

        // do error handling and store args
        if (vm.count("help")) {
            std::cout << *desc << std::endl;
            exit(0);
        }
        return vm;
    }
}

/**
 * @brief Parse arguments from a Config file
 * 
 * @param file_name path to Config file
 * @return po::variables_map 
 */
po::variables_map Parser::parseArgs(std::string file_name) {
    // TODO
}

/**
 * @brief Store parsed args in program state object.
 * Do error checking and print relevent messages.
 * 
 * @param vm variable map of args
 * @return ProgramState 
 */
ProgramState Parser::storeArgs(po::variables_map vm) {
    
}
