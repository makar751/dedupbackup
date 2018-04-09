//
// Created by allex on 08.04.18.
//

#ifndef DEDUPBACKUP_FILE_UTILS_H
#define DEDUPBACKUP_FILE_UTILS_H

#include <sys/stat.h>
#include <string>
#include "error.h"
#include "log.h"

class IFile {
public:
    IFile() {};
    IFile(std::string path, struct stat file_info) : path_(path), file_info_(file_info) {};
    virtual int GetType() = 0;
    virtual void CalcHash() = 0;
    ~IFile() {};
protected:
    std::string path_;
    struct stat file_info_;

    enum FileType {
        regular = 0,
        link
    };
};

class RegularFile : public IFile {
public:
    RegularFile(std::string path, struct stat file_info) : IFile(path, file_info){};
    int GetType();
    void CalcHash();
private:
    std::string hash_;
};

class LinkToFile : public IFile {
public:
    LinkToFile(std::string path, struct stat file_info) : IFile(path, file_info){};
    int GetType();
    void CalcHash();
private:
    std::string path_to_file_;
};

class File {
public:
    File(std::string path, struct stat file_info);
    void CalculateHash();
    ~File();
private:
    IFile *file_;

    Log Logg() {
        static Log logger_("file_utils");
        return logger_;
    }

};

class Directory {
public:
    Directory(std::string path) : path_(path)  {};
    Error Scan();
    std::vector<File*> GetFiles();
    std::vector<Directory*> GetSubDirs();
    ~Directory();
private:
    std::string path_;
    struct stat dir_info_;
    std::vector<File*> files_;
    std::vector<Directory*> sub_dirs_;

    Log Logg() {
        static Log logger_("file_utils");
        return logger_;
    }
};

#endif //DEDUPBACKUP_FILE_UTILS_H
