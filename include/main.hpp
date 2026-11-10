#ifndef MAINLIB
#define MAINLIB

#include <iostream>
#include "../include/socket.hpp"
#include "../include/renderlib.h"
#include <exception>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <string>

#define TYPE_EXC            0
#define SOCKET_EXC          1
#define RENDER_EXC          2

#define SERVER_PING_EXC     3
#define SERVER_ANSWER_EXC   4

#define SYSTEM_MONITOR_EXC  5
#define SYSTEM_VOLUME_EXC   6

#define MASSAGE_INPUT_EXC   7

#define OK_SOCK_INIT        8
#define OK_RENDER_INIT      9

extern const char* HOME;

void log_error(uint8_t status, std::string error) __attribute__((noreturn));
bool start_client();
int main();

#endif