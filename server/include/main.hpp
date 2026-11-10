#ifndef MAINHPP
#define MAINHPP

#include <cstring>
#include <stdint.h>
#include <sys/socket.h>   // socket(), bind(), listen(), accept(), connect(), send(), recv()
#include <netinet/in.h>   // sockaddr_in, htons(), htonl(), INADDR_ANY
#include <arpa/inet.h>    // inet_addr(), inet_pton()
#include <unistd.h>       // close()
#include <stdexcept>      // std::runtime_error()
#include <string>

void log_error(const std::string error);

int main();

#endif