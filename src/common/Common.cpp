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

u64_t get_current_time_us()
{
        static u64_t value_fix=0;
        static u64_t largest_value=0;

        u64_t raw_value=(u64_t)(ev_time()*1000*1000);

        u64_t fixed_value=raw_value+value_fix;

        if(fixed_value< largest_value)
        {
                value_fix+= largest_value- fixed_value;
        }
        else
        {
                largest_value=fixed_value;
        }

	//printf("<%lld,%lld,%lld>\n",raw_value,value_fix,raw_value + value_fix);
        return raw_value + value_fix; //new fixed value
}

u64_t get_current_time()
{
	return get_current_time_us()/1000;
}

u64_t pack_u64(u32_t a,u32_t b)
{
	u64_t ret=a;
	ret<<=32u;
	ret+=b;
	return ret;
}

u32_t get_u64_h(u64_t a)
{
	return a>>32u;
}
u32_t get_u64_l(u64_t a)
{
	return (a<<32u)>>32u;
}

char * my_ntoa(u32_t ip)
{
	in_addr a;
	a.s_addr=ip;
	return inet_ntoa(a);
}

/* Following 3 functions need creating dependancy functions
u64_t get_true_random_number_64()
{
	u64_t ret;
	int size=read(random_fd.get_fd(),&ret,sizeof(ret));
	if(size!=sizeof(ret))
	{
		mylog(log_fatal,"get random number failed %d\n",size);
		myexit(-1);
	}
	return ret;
}
u32_t get_true_random_number()
{
    u32_t ret;
    int size=read(random_fd.get_fd(),&ret,sizeof(ret));
    if(size!=sizeof(ret))
    {
        mylog(log_fatal,"get random number failed %d\n",size);
        myexit(-1);
    }
return ret;
}
u32_t get_true_random_number_nz() //nz for non-zero
{
	u32_t ret=0;
	while(ret==0)
	{
		ret=get_true_random_number();
	}
	return ret;
}
*/
u64_t ntoh64(u64_t a)
{
	#ifdef UDP2RAW_LITTLE_ENDIAN
		u32_t h=get_u64_h(a);
		u32_t l=get_u64_l(a);
		return pack_u64(ntohl(l),ntohl(h));
		//return bswap_64( a);
	#else
	return a;
	#endif

}
u64_t hton64(u64_t a)
{
	return ntoh64(a);
}

void write_u16(char * p,u16_t w)//@qflag what is this? and why the need to shift w, number conversion?
{
	*(unsigned char*)(p + 1) = (w & 0xff);
	*(unsigned char*)(p + 0) = (w >> 8);
}
u16_t read_u16(char * p)
{
	u16_t res;
	res = *(const unsigned char*)(p + 0);
	res = *(const unsigned char*)(p + 1) + (res << 8);
	return res;
}

void write_u32(char * p,u32_t l)
{
	*(unsigned char*)(p + 3) = (unsigned char)((l >>  0) & 0xff);
	*(unsigned char*)(p + 2) = (unsigned char)((l >>  8) & 0xff);
	*(unsigned char*)(p + 1) = (unsigned char)((l >> 16) & 0xff);
	*(unsigned char*)(p + 0) = (unsigned char)((l >> 24) & 0xff);
}
u32_t read_u32(char * p)
{
	u32_t res;
	res = *(const unsigned char*)(p + 0);
	res = *(const unsigned char*)(p + 1) + (res << 8);
	res = *(const unsigned char*)(p + 2) + (res << 8);
	res = *(const unsigned char*)(p + 3) + (res << 8);
	return res;
}

void write_u64(char * s,u64_t a)
{
	assert(0==1);
}
u64_t read_u64(char * s)
{
	assert(0==1);
	return 0;
}
bool larger_than_u32(u32_t a,u32_t b)
{
	return ((i32_t(a-b)) >0);
}
bool larger_than_u16(uint16_t a,uint16_t b)
{
	return ((i16_t(a-b)) >0);
}
void setnonblocking(int sock) {
	int opts;
	opts = fcntl(sock, F_GETFL);

	if (opts < 0) {
    	mylog(log_fatal,"fcntl(sock,GETFL)\n");
		//perror("fcntl(sock,GETFL)");
		myexit(1);
	}
	opts = opts | O_NONBLOCK;
	if (fcntl(sock, F_SETFL, opts) < 0) {
    	mylog(log_fatal,"fcntl(sock,SETFL,opts)\n");
		//perror("fcntl(sock,SETFL,opts)");
		myexit(1);
	}
}