// fs5_constants.h

/*
    MAX_USERS：定义最大用户数
    MAX_FILES：定义每个用户最大文件数
    BLOCK_SIZE：定义磁盘块大小
    TOTAL_BLOCKS：定义总磁盘块数
*/

#ifndef FS5_CONSTANTS_H
#define FS5_CONSTANTS_H

const int MAX_USERS = 16;
const int MAX_FILES = 64;
const int BLOCK_SIZE = 512;
const int TOTAL_BLOCKS = 1024;

#endif  // FS5_CONSTANTS_H