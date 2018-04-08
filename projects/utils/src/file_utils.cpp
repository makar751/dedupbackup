//
// Created by allex on 08.04.18.
//
#include "file_utils.h"
#include "sha512.hh"

Error File::GetFileInfo() {
    Error error(OK);
    struct stat file_info;
    if (stat(path_.c_str(), &file_info) != 0) {
        error.Set_Code(Unknown);
        return error;
    }
    access_rights_ = file_info.st_mode;
    user_id_ = file_info.st_uid;
    group_id_ = file_info.st_gid;
    return error;

}

Error File::CalculateHash() {
    hash_ = sw::sha512::file(path_);
}