//
// Created by allex on 08.04.18.
//

#ifndef DEDUPBACKUP_FILE_UTILS_H
#define DEDUPBACKUP_FILE_UTILS_H

#include <sys/stat.h>
#include <string>
#include "error.h"
#include "log.h"

class File {
public:
    File(std::string path) : path_(path) {};
    Error GetFileInfo();
    Error CalculateHash();
private:
    std::string path_;
    std::string name_;
    std::string hash_;
    mode_t access_rights_;
    uid_t user_id_;
    gid_t group_id_;

    Log Logg() {
        static Log logger_("file_utils");
        return logger_;
    }

};

#endif //DEDUPBACKUP_FILE_UTILS_H
