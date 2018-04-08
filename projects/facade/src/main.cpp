#include <iostream>
#include "log.h"

int main() {
    Log logg("main");
    Error error(OK);
    LOG_ERROR(error);
    return 0;
}