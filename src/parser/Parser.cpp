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
                                + std::to_string(rawsocket_VERSION_MINOR) + "." 
                                + std::to_string(rawsocket_VERSION_PATCH) + "\n\n"
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
        ("raw-mode", po::value<std::string>()->default_value("raw-tcp"),  // TODO: set default value in config file
                                "raw socket type:\n" 
                                "  \traw-tcp, raw-udp, raw-icmp, tcp, udp, icmp")
        ("log-level", po::value<std::string>()->default_value("info"),   // TODO: set default value in config file
                                "log level:\n" 
                                "  \tnever, error, warn, info, debug, verbose")
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
 */
void Parser::parseArgs(int argc, char* argv[]) {
    if (argc < 2)   // if no argument given
    { 
        printUsage();
        exit(0);
    }
    else   // parse the command line arguments
    {
        try
        {
            po::store(po::parse_command_line(argc, argv, *desc), vm);
            po::notify(vm);
        }
        catch(po::error e)  // print usage
        {
            // TODO: handle errors more efficiently
            Log::logStdout(Log::LogLevel::error, e.what());
            printUsage();
            exit(0);
        }
        if (vm.count("help")) {
                printUsage();
                exit(0);
            }
        return;
    }
}

/**
 * @brief Parse arguments from a Config file
 * 
 * @param file_name path to Config file
 */
void Parser::parseArgs(std::string file_name) {
    // TODO
}

/**
 * @brief Store parsed args in program state object.
 * Do error checking and print relevent messages.
 * 
 * @return ProgramState 
 */
ProgramState Parser::storeArgs() {
    ProgramState program_state;

    // parse program mode
    if (program_state.programMode == ProgramMode::mode_unset) {
        if (vm.count("server")) {
            program_state.programMode = ProgramMode::mode_server;
        }
        else if (vm.count("client"))
        {
            program_state.programMode = ProgramMode::mode_client;
        }
        else {
            Log::logStdout(Log::error, "program mode not defined\n");
            printUsage();
            exit(0);
        }        
    }
    else {
        Log::logStdout(Log::error, "program mode not right\n");
        printUsage();
        exit(0);
    }

    // parse socket mode
    if (program_state.socketMode == SocketMode::mode_none) {
        if (vm.count("raw-mode")) {
            std::string raw_mode = vm["raw-mode"].as<std::string>();
            // TODO: optimize these if statements
            if (raw_mode == "raw-tcp") {
                program_state.socketMode = SocketMode::mode_raw_tcp;
            }
            else if (raw_mode == "raw-udp")
            {
                program_state.socketMode = SocketMode::mode_raw_udp;
            }
            else if (raw_mode == "raw-icmp")
            {
                program_state.socketMode = SocketMode::mode_raw_icmp;
            }
            else if (raw_mode == "udp")
            {
                program_state.socketMode = SocketMode::mode_udp;
            }
            else if (raw_mode == "tcp")
            {
                program_state.socketMode = SocketMode::mode_tcp;
            }
            else if (raw_mode == "icmp")
            {
                program_state.socketMode = SocketMode::mode_icmp;
            }
            else {
                Log::logStdout(Log::error, "socket mode not found\n");
                printUsage();
                exit(0);
            }
        }
    }
    else {
        Log::logStdout(Log::error, "socket mode not right\n");
        printUsage();
        exit(0);
    }

    // parse log level
    // never, error, warn, info, debug, verbose
    if (vm.count("log-level")) {
        std::string log_level = vm["log-level"].as<std::string>();
        if (log_level == "never") {
            program_state.log.setLogInfo(Log::LogLevel::never);
        }
        else if (log_level == "error")
        {
            program_state.log.setLogInfo(Log::LogLevel::error);
        }
        else if (log_level == "warn")
        {
            program_state.log.setLogInfo(Log::LogLevel::warn);
        }
        else if (log_level == "info")
        {
            program_state.log.setLogInfo(Log::LogLevel::info);
        }
        else if (log_level == "debug")
        {
            program_state.log.setLogInfo(Log::LogLevel::debug);
        }
        else if (log_level == "verbose")
        {
            program_state.log.setLogInfo(Log::LogLevel::verbose);
        }
        else {
            Log::logStdout(Log::error, "log level not found\n");
            printUsage();
            exit(0);
        }
    }


    return program_state;
}
