// fs5_structures.h
/*
                    定义数据结构
    DiskBlock： 内存块
    User：      用户信息

*/
#ifndef FS5_STRUCTURES_H
#define FS5_STRUCTURES_H

#include <vector>
#include <string>

struct DiskBlock {
    int next_block = -1;        // 下一个块号，-1表示无后续块
    bool used = false;          // 是否被使用
};

struct User {
    std::string username;
    std::string password;
    std::vector<std::string> files;       // 存储文件名
    std::vector<int> file_sizes;          // 存储文件大小
    std::vector<int> file_blocks;         // 存储文件起始块号
};

#endif  // FS5_STRUCTURES_H