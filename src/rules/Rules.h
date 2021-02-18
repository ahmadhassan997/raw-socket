//
// Created by ahmad on 2/18/21.
//

#ifndef RAWSOCKET_RULES_H
#define RAWSOCKET_RULES_H

class Rules {
private:
    void handleIptableRules();
    void genAddIptableRules();
    void initIptableRules();
    void keepIptableRules();
    void keepIptableRulesHandler();
    void clearIptableRules();
public:
    Rules();
};

#endif //RAWSOCKET_RULES_H