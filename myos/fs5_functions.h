// fs5_functions.h
/*
    声明函数
*/
#ifndef FS5_FUNCTIONS_H
#define FS5_FUNCTIONS_H

#include <string>
#include "fs5_structures.h"

// 用户管理
void register_user(User* users, int& user_count);
bool login(const std::string& username, const std::string& password, User* users, int user_count, User*& current_user);

// 文件管理
void create_file(User* current_user, const std::string& filename, DiskBlock* disk);
void delete_file(User* current_user, const std::string& filename, DiskBlock* disk);
void read_file(User* current_user, const std::string& filename);
void write_file(User* current_user, const std::string& filename);
void list_files(User* current_user);

// 其他
void display_help();

#endif  // FS5_FUNCTIONS_H