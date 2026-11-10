#ifndef SOCKETLIB
#define SOCKETLIB

#include <sys/socket.h>   // socket(), bind(), listen(), accept(), connect(), send(), recv()
#include <netinet/in.h>   // sockaddr_in, htons(), htonl(), INADDR_ANY
#include <arpa/inet.h>    // inet_addr(), inet_pton()
#include <unistd.h>       // close()
#include <stdexcept>      // std::runtime_error()

#define PORT 7252

namespace SOCKETHPP {
    class MY_SOCKET{
    private:
        struct msgType;
        int fd;
        sockaddr_in addr;
    public:
        MY_SOCKET();
        char* build_pack();
        bool ping_server();
        ~MY_SOCKET();
    };
}

#endif