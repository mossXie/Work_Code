#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class MyException {
    private:
        string ErrorFunctionName;
        int ErrorArg1;
        int ErrorArg2;
    
    public:
        MyException(const string& func, int code1, int code2 = 0)
            : ErrorFunctionName(func), ErrorArg1(code1), ErrorArg2(code2) {}
    
        void print() const {
            if (ErrorArg2 == 0) {
                cerr << "Exception: problem in " << ErrorFunctionName << " incorrect parameter:" << ErrorArg1 << endl;
            } else {
                cerr << "Exception: problem in " << ErrorFunctionName << " incorrect parameter:" << ErrorArg1 << " " << ErrorArg2 << endl;
            }
        }
};

class mstring {
    private:
        char* data;
        int size;
    public:
        mstring();
        mstring(const char* str);
        mstring(const mstring& other);
        ~mstring();
        int length();
        bool isempty();
        void add(char c);
        void add(const char* c);
        void insert(char c, int i);
        void insert(const char* c, int i);
        void del(int i);
        void del(int i, int j);
        int search(const char* str);
        void print();
};

mstring::mstring() : size(0) {
    data = new char[1];
    data[0] = '\0';
}

mstring::mstring(const char* str) {
    size = strlen(str);
    data = new char[size + 1];
    strcpy(data, str);
}

mstring::mstring(const mstring& other) {
    size = other.size;
    data = new char[size + 1];
    strcpy(data, other.data);
}

mstring::~mstring() {
    delete[] data;
}

int mstring::length() {
    return size;
}

bool mstring::isempty() {
    return size == 0;
}

void mstring::add(char c) {
    int new_size = size + 1;
    char* newData = new char[new_size + 1];
    strncpy(newData, data, size);
    newData[size] = c;
    newData[new_size] = '\0';
    delete[] data;
    data = newData;
    size = new_size;
}

void mstring::add(const char* c) {
    int cLength = strlen(c);
    char* newData = new char[size + cLength + 1];
    strcpy(newData, data);
    strcat(newData, c);
    delete[] data;
    data = newData;
    size += cLength;
}

void mstring::insert(char c, int i) {
    if (i < 0 || i > size) throw MyException("insert", i);

    char* newData = new char[size + 2];
    strncpy(newData, data, i);
    newData[i] = c;
    strcpy(newData + i + 1, data + i);
    delete[] data;
    data = newData;
    size++;
}

void mstring::insert(const char* c, int i) {
    if (i < 0 || i > size) throw MyException("insert", i);

    int cLength = strlen(c);
    char* newData = new char[size + cLength + 1];
    strncpy(newData, data, i);
    strcpy(newData + i, c);
    strcpy(newData + i + cLength, data + i);
    delete[] data;
    data = newData;
    size += cLength;
}

void mstring::del(int i) {
    if (i < 0 || i >= size) throw MyException("del", i);

    char* newData = new char[size];
    strncpy(newData, data, i);
    strcpy(newData + i, data + i + 1);
    delete[] data;
    data = newData;
    size--;
}

void mstring::del(int i, int j) {
    if (i < 0 || j >= size || i > j) throw MyException("del", i, j);

    char* newData = new char[size - (j - i + 1) + 1];
    strncpy(newData, data, i);
    strcpy(newData + i, data + j + 1);
    delete[] data;
    data = newData;
    size -= (j - i + 1);
}

int mstring::search(const char* str) {
    if (str == nullptr || *str == '\0') return -1;
    
    int zlength = size;
    int sonLength = strlen(str);
    
    if (sonLength > zlength) return -1;
    
    for (int i = 0; i <= zlength - sonLength; i++) {
        int j;
        for (j = 0; j < sonLength; j++) {
            if (data[i + j] != str[j]) {
                break;
            }
        }
        if (j == sonLength) { 
            return i; 
        }
    }
    return -1; 
}

void mstring::print() {
    cout << data << endl;
}

void error() {
    mstring s("hello world");
    mstring s1 = s;
    mstring s2;
    if (!s1.isempty()) {
        s1.insert(' ', 5);
        s1.insert('m', 6);
        s1.insert('y', 7);
        s.insert(" my", 5);
        s.print();
        s1.print();
    }
    s.del(-1);
}
int main() {
    try {
        error();
    } catch (const MyException& e) {
        e.print();
    } catch (...) { 
        cerr << "Exception: unknown error" << endl;
        return 2;
    }
    return 0;
}