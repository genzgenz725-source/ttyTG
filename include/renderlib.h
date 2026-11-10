#ifndef RENDERLIB
#define RENDERLIB

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

struct renderConfig {            // struct of config for initialize
    bool TTY;
    bool animated;
};

static bool TTY;

bool INIT_RENDER(const struct renderConfig cfg);
bool RENDER_EXCEPTION(const char* type, const char* error);

#endif