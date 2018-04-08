//
// Created by allex on 08.04.18.
//

#ifndef DEDUPBACKUP_MESSAGES_DICTIONARY_H
#define DEDUPBACKUP_MESSAGES_DICTIONARY_H

#include <map>

const unsigned int MessagesSize = 1024;

const char Messages[MessagesSize][MessagesSize] = {
        "success=Success",
        "unknown_error=Unknown Error"
};

const char GetMessageError[] = "Fail to get message";

std::map<unsigned int, std::string> messages_map;

void Add_Message(unsigned int code, std::string message) {
    for (int i = 0;i < MessagesSize; i++){
        std::string message_string(Messages[i]);
        std::size_t position = message_string.find("=");
        if (position != std::string::npos){
            if (std::string(message_string.begin(), message_string.begin() + position) == message)
                messages_map.insert(std::make_pair(code, std::string(message_string.begin() + position + 1, message_string.end())));
        }

    }
}

#endif //DEDUPBACKUP_MESSAGES_DICTIONARY_H
