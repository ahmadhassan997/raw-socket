//
// Created by ahmad on 2/18/21.
//

#include "Rules.h"

void Rules::handleIptableRules(ProgramState &state) {

    std::string iptables_cmd = "iptables ";

    if (state.addIprules && state.genIprules) {
        Log::logStdout(Log::LogLevel::warn, " -g option overrides -a option\n");
        state.addIprules = false;
    }

    char cmd_pattern[200];

    if (state.programMode == ProgramMode::mode_client) {
        
    }
}

int Rules::addIptableRules(const char* cmd, u32_t id, bool keep_rule) {

}