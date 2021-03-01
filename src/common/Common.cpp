//
// Created by ahmad on 2/21/21.
//

#include "Common.h"

int force_socket_buf=0;

int Common::executeCommand(const char* command, char* &output) {
    
    FILE *in;
    Log::logStdout(Log::LogLevel::debug, "exec command: [%s]\n", command);
    static __thread char buf[1024*1024];
    buf[sizeof(buf) - 1] = 0;
    
    in = popen(command, "r");
    if (in == NULL) {
        Log::logStdout(Log::LogLevel::error, 
                    "exec command [%s] failed, error: %s\n", command, strerror(errno));
        return -1;
    }
    
    int len = fread(buf, 1024*1024, 1, in);
    if (len == 1024*1024) {
        Log::logStdout(Log::LogLevel::error, 
                    "exec command [%s] failed, buffer too large\n", command);
        return -2;
    }
    buf[len] = 0;
    
    int ret = ferror(in);
    if (ret) {
        Log::logStdout(Log::LogLevel::error, 
                    "exec command [%s] failed, ferror: %d\n", command, ret);
        return -3;
    }
    
    output = buf;
    ret = pclose(in);
    int ret2 = WEXITSTATUS(ret);
    if (ret != 0 || ret2 != 0) {
        Log::logStdout(Log::LogLevel::error, 
                    "exec command [%s] failed, pclose returned %d, EXIT(%d), error: %s \n",
                    command, ret, ret2, strerror(errno));
        return -4;
    }

    return 0;
}

u32_t djb2(unsigned char *str,int len)
{
	 u32_t hash = 5381;
     int c;
     int i=0;
    while(c = *str++,i++!=len)
    {
         hash = ((hash << 5) + hash)^c;
    }

     hash=htonl(hash);
     return hash;
}

u32_t sdbm(unsigned char *str,int len)
{
     u32_t hash = 0;
     int c;
     int i=0;
	while(c = *str++,i++!=len)
	{
		 hash = c + (hash << 6) + (hash << 16) - hash;
	}
     return hash;
 }