// fs5_functions.cpp
/*
                实现函数
    register_user   注册
    login           登录
    create_file     创建文件
    delete_file     删除文件
    read_file       读取文件
    write_file      写入文件
    list_files      列出文件
    display_help    显示帮助
*/
#include "fs5_functions.h"
#include "fs5_constants.h"
#include <iostream>
#include <cstring>

using namespace std;

// 用户注册
void register_user(User* users, int& user_count) {
    if (user_count >= MAX_USERS) {
        cout << "Error: Maximum number of users reached." << endl;
        return;
    }

    string username, password;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    for (int i = 0; i < user_count; ++i) {
        if (users[i].username == username) {
            cout << "Error: Username already exists." << endl;
            return;
        }
    }

    users[user_count].username = username;
    users[user_count].password = password;
    user_count++;
    cout << "User registered successfully." << endl;
}

// 用户登录
bool login(const string& username, const string& password, User* users, int user_count, User*& current_user) {
    for (int i = 0; i < user_count; ++i) {
        if (users[i].username == username && users[i].password == password) {
            current_user = &users[i];
            cout << "Login successful. Welcome, " << username << "!" << endl;
            return true;
        }
    }

    cout << "Error: Invalid username or password." << endl;
    return false;
}

// 创建文件
void create_file(User* current_user, const string& filename, DiskBlock* disk) {
    if (!current_user) {
        cout << "Error: You must be logged in to create a file." << endl;
        return;
    }

    for (const auto& file : current_user->files) {
        if (file == filename) {
            cout << "Error: File already exists." << endl;
            return;
        }
    }

    if (current_user->files.size() >= MAX_FILES) {
        cout << "Error: Maximum number of files reached." << endl;
        return;
    }

    int block = -1;
    for (int i = 0; i < TOTAL_BLOCKS; ++i) {
        if (!disk[i].used) {
            block = i;
            disk[i].used = true;
            break;
        }
    }

    if (block == -1) {
        cout << "Error: No free disk space available." << endl;
        return;
    }

    current_user->files.push_back(filename);
    current_user->file_sizes.push_back(0);
    current_user->file_blocks.push_back(block);
    cout << "File created successfully." << endl;
}

// 删除文件
void delete_file(User* current_user, const string& filename, DiskBlock* disk) {
    if (!current_user) {
        cout << "Error: You must be logged in to delete a file." << endl;
        return;
    }

    for (size_t i = 0; i < current_user->files.size(); ++i) {
        if (current_user->files[i] == filename) {
            int block = current_user->file_blocks[i];
            disk[block].used = false;  // 标记磁盘块为空闲
            current_user->files.erase(current_user->files.begin() + i);
            current_user->file_sizes.erase(current_user->file_sizes.begin() + i);
            current_user->file_blocks.erase(current_user->file_blocks.begin() + i);
            cout << "File deleted successfully." << endl;
            return;
        }
    }

    cout << "Error: File not found." << endl;
}

// 读取文件
void read_file(User* current_user, const string& filename) {
    if (!current_user) {
        cout << "Error: You must be logged in to read a file." << endl;
        return;
    }

    for (size_t i = 0; i < current_user->files.size(); ++i) {
        if (current_user->files[i] == filename) {
            int size = current_user->file_sizes[i];
            cout << "File content (size: " << size << " bytes): " << endl;
            return;
        }
    }

    cout << "Error: File not found." << endl;
}

// 写入文件
void write_file(User* current_user, const string& filename) {
    if (!current_user) {
        cout << "Error: You must be logged in to write a file." << endl;
        return;
    }

    for (size_t i = 0; i < current_user->files.size(); ++i) {
        if (current_user->files[i] == filename) {
            cout << "Enter new content: ";
            string content;
            getline(cin, content);
            current_user->file_sizes[i] = content.size();
            cout << "File written successfully." << endl;
            return;
        }
    }

    cout << "Error: File not found." << endl;
}

// 列出文件
void list_files(User* current_user) {
    if (!current_user) {
        cout << "Error: You must be logged in to list files." << endl;
        return;
    }

    cout << "Files in current directory:" << endl;
    for (const auto& file : current_user->files) {
        cout << file << endl;
    }
}

// 显示帮助
void display_help() {
    cout << "Available commands:" << endl;
    cout << "  register - Register a new user" << endl;
    cout << "  login - Login to an existing user account" << endl;
    cout << "  create - Create a new file" << endl;
    cout << "  delete - Delete a file" << endl;
    cout << "  read - Read a file" << endl;
    cout << "  write - Write to a file" << endl;
    cout << "  list - List all files in the current directory" << endl;
    cout << "  exit - Exit the file system" << endl;
}