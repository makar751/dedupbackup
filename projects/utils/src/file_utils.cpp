//
// Created by allex on 08.04.18.
//
#include "file_utils.h"
#include "sha512.hh"
#include <dirent.h>
#include <future>
#include <map>


void RegularFile::CalcHash()  {
    hash_ = sw::sha512::file(path_);
}

int RegularFile::GetType() {
    return FileType::regular;
}

void LinkToFile::CalcHash() {
    path_to_file_ = realpath(path_.c_str(), NULL);
}

int LinkToFile::GetType() {
    return FileType::link;
}

File::File(std::string path, struct stat file_info) {
    if (S_ISLNK(file_info.st_mode)){
        file_ = static_cast<IFile*>(new LinkToFile(path, file_info));
    }
    if (S_ISREG(file_info.st_mode)){
        file_ = static_cast<IFile*>(new RegularFile(path, file_info));
    }
}

void File::CalculateHash() {
    if (file_)
        file_->CalcHash();
}

File::~File() {
    delete file_;
}

Error Directory::Scan() {
    DIR *dir;
    dir = opendir (path_.c_str());
    if (dir != NULL)
    {
        lstat(path_.c_str(), &dir_info_);
        struct dirent *dir_inf;
        std::vector<std::thread*> threads;
        while (dir_inf = readdir (dir)){
            if(strcmp(dir_inf->d_name, ".") == 0 || strcmp(dir_inf->d_name, "..") == 0)
                continue;
            struct stat st_info;
            memset(&st_info, 0, sizeof(struct stat));
            std::string full_path = path_ + "/" + dir_inf->d_name;
            LOG4CPLUS_ERROR(Logg().GetLogger(), full_path);
            int status = lstat(full_path.c_str(), &st_info);
            if (S_ISDIR(st_info.st_mode)){
                Directory *dir_el = new Directory(full_path.c_str());

                std::thread *t = new std::thread(&Directory::Scan, dir_el);
                threads.push_back(t);
                sub_dirs_.push_back(dir_el);
            }
            else {
                struct stat file_info;
                int file_status = stat(full_path.c_str(), &file_info);
                if (file_status == 0) {
                    File *file_el = new File(full_path.c_str(), st_info);
                    std::thread *t = new std::thread(&File::CalculateHash, file_el);
                    threads.push_back(t);
                    files_.push_back(file_el);
                }
            }
        }
        closedir (dir);
        for(auto const& value: threads)
            value->join();
    }
    else
        perror ("Couldn't open the directory");
    return Error(OK);

}

std::vector<File*> Directory::GetFiles(){
    return files_;
}
std::vector<Directory*> Directory::GetSubDirs(){
   return sub_dirs_;
}

Directory::~Directory() {
    for(auto const& value: files_)
        delete value;
    for(auto const& value: sub_dirs_)
        delete value;
}