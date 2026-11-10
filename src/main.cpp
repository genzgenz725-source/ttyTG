#include "../include/main.hpp"
#include "../include/renderlib.h"
#include "../include/socket.hpp"

using namespace SOCKETHPP;

const char* HOME = getenv("HOME");
static std::string path_to_logs = std::string(HOME) + ".logs_ttyTG";


void log_error(uint8_t status, std::string error) {
    char* strType;
    switch (status) {
        case 0:
            strcpy(strType, "TYPE_EXC");
        case 1:
            strcpy(strType, "SOCKET_EXC");
        case 2:
            strcpy(strType, "RENDER_EXC");
        case 3:
            strcpy(strType, "SERVER_PING_EXC");
        case 4:
            strcpy(strType, "SERVER_ANSWER_EXC");
        case 5:
            strcpy(strType, "SYSTEM_MONITOR_EXC");
        case 6:
            strcpy(strType, "SYSTEM_VOLUME_EXC");
        case 7:
            strcpy(strType, "MASSAGE_INPUT_EXC");
        default:
            std::ofstream f(path_to_logs, std::ios::ate|std::ios::app);
            f << "status is wrong " << status << '\n';
            exit(status);
    }
    if (!RENDER_EXCEPTION(strType, error.c_str())) {
        exit(RENDER_EXC);
    }

    std::ofstream f(path_to_logs, std::ios::ate|std::ios::app);
    f << strType << ' ' << error << "\n";

    exit(status);
}

bool start_client() {
    bool ans;
    MY_SOCKET sock;
    if (!sock.ping_server()) {
        log_error(SERVER_PING_EXC, "server is not answering");
    }

    // i gotta send a package to my render lib, and ask client which one mode he wanna use (tty/gui)
    // now i gonna ask by iostream lib
    std::cout << "which one mode u wanna use (tty/gui) 0/1 ~>";
    try {
        std::cin >> ans;
    } catch (std::exception &e) {
        log_error(TYPE_EXC, "input must be 0/1 only");
    }
    std::cout << ans;

    renderConfig cfg;
    cfg.TTY = true;
    cfg.animated = true;
    if (!INIT_RENDER(cfg)) {
        log_error(RENDER_EXC, "render cant init");
    }

    return "";
}

int main() {
    if (!start_client()) {
        return 1;
    }



    return 0;
}