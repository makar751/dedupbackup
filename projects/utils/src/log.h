//
// Created by allex on 26.02.18.
//

#ifndef DEDUPBACKUP_LOG_H
#define DEDUPBACKUP_LOG_H

#include "log4cplus/logger.h"
#include <string>
class Log{
public:
    Log(std::string name);
private:
    log4cplus::Logger logger_;
};

#endif //DEDUPBACKUP_LOG_H
