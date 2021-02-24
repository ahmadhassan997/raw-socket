//
// Created by ahmad on 2/18/21.
//

#ifndef RAWSOCKET_RULES_H
#define RAWSOCKET_RULES_H

#include <iostream>

#include "Log.h"
#include "Common.h"
#include "ProgramState.h"
#include "DTypes.h"

class Rules {
private:
    static int addIptableRules(const char*, u32_t, bool);
    static int clearIptableRules();
    static void* keepIptablesHandler(void*);
public:
    std::string iptable_pattern = "";
    bool rule_added = false;
    Rules();
    static void handleIptableRules(ProgramState&);
};

#endif //RAWSOCKET_RULES_H