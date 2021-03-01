//
// Created by ahmad on 2/21/21.
//

#ifndef RAWSOCKET_COMMON_H
#define RAWSOCKET_COMMON_H

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "Log.h"
#include <arpa/inet.h>

typedef unsigned long long u64_t;   //this works on most platform,avoid using the PRId64
typedef long long i64_t;
typedef unsigned int u32_t;
typedef int i32_t;
typedef unsigned short u16_t;
typedef short i16_t;
typedef u32_t my_id_t;
typedef u64_t iv_t;
typedef u64_t padding_t;
typedef u64_t anti_replay_seq_t;
typedef u64_t my_time_t;
typedef u64_t fd64_t;

const int max_addr_len=100;
extern int force_socket_buf;
extern int g_fix_gro;
class Common {
public:
    static int executeCommand(const char*, char* &);
    u32_t djb2(unsigned char *str,int len);
    u32_t sdbm(unsigned char *str,int len);
};

#endif //RAWSOCKET_COMMON_H