#include "../../include/renderlib.h"

static bool init = false;

bool INIT_RENDER(const struct renderConfig cfg) {
    

    return true;
}

bool RENDER_EXCEPTION(const char* type, const char* error) {
    if (init) {
        // gonna be a logic of output the error
    } else {
        printf("%s", type);
    }
    return true;
}