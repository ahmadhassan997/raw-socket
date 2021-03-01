//
// Created by ahmad on 2/21/21.
//

#ifndef RAWSOCKET_COMMON_H
#define RAWSOCKET_COMMON_H

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include "Log.h"
#include <assert.h>
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
const int show_none=0;
const int show_command=0x1;
const int show_log=0x2;
const int show_all=show_command|show_log;
class Common {
public:
    static int executeCommand(const char*, char* &);
    u32_t djb2(unsigned char *str,int len);
    u32_t sdbm(unsigned char *str,int len);
    u64_t get_current_time();
    u64_t pack_u64(u32_t a,u32_t b);
    u32_t get_u64_h(u64_t a);
    u32_t get_u64_l(u64_t a);
    char * my_ntoa(u32_t ip);
    u64_t get_true_random_number_64();
    u32_t get_true_random_number();
    u32_t get_true_random_number_nz();
    u64_t ntoh64(u64_t a);
    u64_t hton64(u64_t a);
    void write_u16(char *,u16_t a);// network order
    u16_t read_u16(char *);
    void write_u32(char *,u32_t a);// network order
    u32_t read_u32(char *);
    void write_u64(char *,u64_t a);
    u64_t read_u64(char *);
    bool larger_than_u16(uint16_t a,uint16_t b);
    bool larger_than_u32(u32_t a,u32_t b);
    void setnonblocking(int sock);
    int set_buf_size(int fd,int socket_buf_size);
    void myexit(int a);
    unsigned short csum(const unsigned short *ptr,int nbytes);
    unsigned short csum_with_header(char* header,int hlen,const unsigned short *ptr,int nbytes);
    int numbers_to_char(my_id_t id1,my_id_t id2,my_id_t id3,char * &data,int &len);
    int char_to_numbers(const char * data,int len,my_id_t &id1,my_id_t &id2,my_id_t &id3);
    int run_command(string command,char * &output,int flag=show_all);
    //int run_command_no_log(string command,char * &output);
    int read_file(const char * file,string &output);
    vector<string> string_to_vec(const char * s,const char * sp);
    vector< vector <string> > string_to_vec2(const char * s);
    string trim(const string& str, char c);
    string trim_conf_line(const string& str);
    vector<string> parse_conf_line(const string& s);
    int hex_to_u32_with_endian(const string & a,u32_t &output);
    int hex_to_u32(const string & a,u32_t &output);
    int create_fifo(char * file);
    void print_binary_chars(const char * a,int len);
};

#endif //RAWSOCKET_COMMON_H