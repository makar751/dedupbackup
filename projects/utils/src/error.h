//
// Created by allex on 08.04.18.
//

#ifndef DEDUPBACKUP_ERROR_H
#define DEDUPBACKUP_ERROR_H

#include <string>

class Error {
public:
    Error();
    Error(unsigned int code);
    void Set_Code(unsigned int code);
    unsigned int Get_Code();
    std::string Get_Text();
private:
    void Check_Messages_Map();
    void Add_Messages();
    unsigned int code_;
    std::string text_;
};

enum ErrorCodes{
    OK = 0,
    Unknown
};

#endif //DEDUPBACKUP_ERROR_H
