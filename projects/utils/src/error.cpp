//
// Created by allex on 08.04.18.
//
#include "error.h"
#include "messages_dictionary.h"

Error::Error() {
    Check_Messages_Map();
}

Error::Error(unsigned int code) {
    Check_Messages_Map();
    Set_Code(code);
}

void Error::Check_Messages_Map() {
    if (messages_map.empty())
        Add_Messages();
}

void Error::Set_Code(unsigned int code) {
    auto map_find = messages_map.find(code);
    if (map_find == messages_map.end()){
        text_ = GetMessageError;
    }
    else {
        text_ = map_find->second;
    }
    code_ = code;
}

unsigned int Error::Get_Code() {
    return code_;
}

std::string Error::Get_Text() {
    return text_;
}

void Error::Add_Messages() {
    Add_Message(ErrorCodes::OK, "success");
    Add_Message(ErrorCodes::Unknown, "unknown_error");
}
