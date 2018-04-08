//
// Created by allex on 26.02.18.
//

#include "log.h"
#include <log4cplus/configurator.h>

Log::Log(std::string name){
    log4cplus::initialize();
    log4cplus::PropertyConfigurator::doConfigure("log_config.txt");
    logger_ = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT(name));
}

log4cplus::Logger Log::GetLogger() {
    return logger_;
}
