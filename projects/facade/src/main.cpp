#include <iostream>
#include "log.h"
#include "file_utils.h"

int main() {
    Log logg("main");
    Error error(OK);
    LOG_ERROR(error);
    Directory tmp("/var");
    tmp.Scan();
    return 0;
}