#include "../../include/socket.hpp"

namespace SOCKETHPP {
    MY_SOCKET::MY_SOCKET() : fd(0) {
            fd = socket(AF_INET, SOCK_STREAM, 0);
        if (fd < 0) {
            throw std::runtime_error("socket() failed");
        }
        addr.sin_family = AF_INET;
        addr.sin_port   = htons(PORT);
        if (inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr) <= 0) {
            close(fd);
            throw std::runtime_error("invalid address: localhost");
        }
        if (connect(fd, reinterpret_cast<const struct sockaddr *>(&addr), sizeof(addr)) < 0) {
            close(fd);
            throw std::runtime_error("connect() failed");
        }
    }
    char* MY_SOCKET::build_pack() {
        char* result;
        return result;
    }
    bool MY_SOCKET::ping_server() {
        return true;
    }
    MY_SOCKET::~MY_SOCKET() { close(fd); }
}