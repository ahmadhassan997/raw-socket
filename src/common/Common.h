//
// Created by ahmad on 2/21/21.
//

#ifndef RAWSOCKET_COMMON_H
#define RAWSOCKET_COMMON_H

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "Log.h"

class Common {
public:
    static int executeCommand(const char*, char* &); 
};

#endif //RAWSOCKET_COMMON_H