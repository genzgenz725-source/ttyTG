#include <cstring>
#include <stdint.h>
#include <sys/socket.h>   // socket(), bind(), listen(), accept(), connect(), send(), recv()
#include <netinet/in.h>   // sockaddr_in, htons(), htonl(), INADDR_ANY
#include <arpa/inet.h>    // inet_addr(), inet_pton()
#include <unistd.h>       // close()
#include <stdexcept>      // std::runtime_error()
#include <string>

#define PORT 7252

class TCP_Server {
private:
    int server_fd;
    struct sockaddr_in address;
    int addrlen;
    char startpkg[20] = "2102143011316767671";

    void log_error(const std::string error) {
        // logic of writing the log
    }
public:
    TCP_Server() {
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd < 0) {
            throw std::runtime_error("socket() failed");
        }

        int opt = 1;
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
            close(server_fd);
            throw std::runtime_error("setsockopt() failed");
        }

        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);
        addrlen = sizeof(address);

        if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
            close(server_fd);
            throw std::runtime_error("bind() failed (port is busy?)");
        }

        if (listen(server_fd, 5) < 0) {
            close(server_fd);
            throw std::runtime_error("listen() failed");
        }

    }

    void accept_client() {
        int client_fd = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
        char buffer[256];
        memset(buffer, 0, 256);
        if (client_fd < 0) {
            throw std::runtime_error("accept() failed");
        }
        recv(client_fd, buffer, 256, 0);
        if (!strcmp(buffer, startpkg)) {
            log_error("client is not verified");
            return;
        }
    }

    ~TCP_Server() {
        close(server_fd);
    }
};

class UDP_Server {};    // gonna be a udp server for calls and video stream


int main() {
    TCP_Server tcp_server_fd;
    UDP_Server udp_server_fd;
    
    tcp_server_fd.accept_client();
    // main

    return 0;
}