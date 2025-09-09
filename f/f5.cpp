#include <iostream>
using namespace std;

class Parser {
private:
    int c;
    bool flag;

public:
    Parser() : c(0), flag(false) {
        gc();
    }

    void gc() {
        c = cin.get();
        if(c == EOF){
            flag = EOF;
        }
    }

    bool analyze() {
        if (S()) {
            return true;
        }else{
            return false;
        }
    }

    bool S() {
        if (c == 'a') {
            gc();
            if (A()){
                return true;
            }else{
                return false;
            }
            if (B()){
                return true;
            }else{
                return false;
            }
        } else if (c == 'b') {
            gc();
            return B();
        } else {
            return false;
        }
    }

    bool A() {
        if (c == 'a') {
            gc();
            return A();
        } else if (c == 'b') {
            gc();
            return true;
        } else {
            return false;
        }
    }

    bool B() {
        if (c == 'b') {
            gc();
            return B();
        } else if(c == '\n' || c == EOF){
            return true;
        }else{
            return false;
        }
    }
};

int main() {
    Parser parser;
    string HD;
    if(parser.analyze()){
        HD = "YES"; 
    }else{
        HD = "NO";
    }
    cout << HD << endl;
    return 0;
}