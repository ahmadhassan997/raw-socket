//
// Created by ahmad on 2/16/21.
//

#include "Log.h"


/**
 * @brief initialize a static member attribute in defination
 * instead of in declaration
 * 
 */
int Log::log_level = Log::LogLevel::info;
bool Log::enable_log_position = false;
bool Log::enable_log_color = true;
std::string Log::log_text[7] = {"NEVER", "ERROR", "WARN", "INFO", "DEBUG", "VERBOSE", ""};
std::string Log::log_color[6] = {RED, RED, YEL, GRN, MAG, ""};

/**
 * @brief update log info
 * 
 * @param _level log level
 * @param _pos enable/disable position flag
 * @param _color enable/disable color flag
 */
void Log::setLogInfo(int _level, bool _pos, bool _color) {
    Log::log_level = _level;
    Log::enable_log_position = _pos;
    Log::enable_log_color = _color;
}

/**
 * @brief update log level
 * 
 * @param _level log level
 */
void Log::setLogInfo(int _level) {
    Log::log_level = _level;
}

/**
 * @brief print logs on terminal based on log level
 * 
 * @param level level to print at
 * @param str formatted string
 * @param ... additional args
 */
void Log::logStdout(int level, const char* str, ...) {
    if (level < 0 || level > LogLevel::verbose) return;
    // make sure log level is less than the configured log level
    if (level > log_level) return;
    if (enable_log_color) {  // change color of stdout
        printf("%s", log_color[level].c_str());
    }
    va_list vList;
    va_start(vList, str);
    vfprintf(stdout, str, vList);
    va_end(vList);
    if (enable_log_color) {  // reset color
        printf("%s", RESET);
    }
    fflush(stdout);
}