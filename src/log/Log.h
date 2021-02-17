//
// Created by ahmad on 2/16/21.
//

#ifndef RAWSOCKET_LOG_H
#define RAWSOCKET_LOG_H

#include <iostream>
#include <stdio.h>
#include <stdarg.h>

// Got the implementation of colors from
// here: https://stackoverflow.com/a/23657072

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

class Log {
private:
    static int log_level;
    static bool enable_log_position;
    static bool enable_log_color;
    static std::string log_text[7];
    static std::string log_color[6];
public:

    enum LogLevel {
        never = 0,
        error = 1,
        warn = 2,
        info = 3,
        debug = 4,
        verbose = 5,
        end = 6
    };

    /// set log level, color, position
    static void setLogInfo(int, bool, bool);

    /// set log level
    static void setLogInfo(int);

    /// print on screen with given log level
    static void logStdout(int level, const char*, ...);

};

#endif //RAWSOCKET_LOG_H
