//
// Create by ahmad on 2/13/21.
//

#ifndef RAWSOCKET_PROGRAMSTATE_H
#define RAWSOCKET_PROGRAMSTATE_H

#include "States.h"
#include "Modes.h"

class ProgramState {
public:
    ProgramMode programMode = ProgramMode::mode_unset;
    SocketMode socketMode = SocketMode::mode_none;
    LogLevel logLevel = LogLevel::none;
};

#endif //RAWSOCKET_PROGRAMSTATE_H