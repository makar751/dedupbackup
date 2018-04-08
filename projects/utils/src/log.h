//
// Created by allex on 26.02.18.
//

#ifndef DEDUPBACKUP_LOG_H
#define DEDUPBACKUP_LOG_H

#include "log4cplus/logger.h"
#include <log4cplus/loggingmacros.h>
#include "error.h"
#include <string>

#define LOG_ERROR(error)\
    LOG4CPLUS_ERROR(logg.GetLogger(), error.Get_Text());\


class Log {
public:
    Log(std::string name);
    log4cplus::Logger GetLogger();
private:
    log4cplus::Logger logger_;
};

#endif //DEDUPBACKUP_LOG_H
