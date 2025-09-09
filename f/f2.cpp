#include <iostream>
#include <string>
using namespace std;

char c;
static int flag;
void gc() { c = cin.get(); }

enum { H, N, P};

string Parser() {
    string instr;
    gc();
    int CH = H;
    do {
        switch (CH) {
            case H:// begin
                if (c == 'a') {
                    instr += c;
                    gc();
                    CH = N;
                }else {
                    flag = 1;
                    throw c;
                }
                break;
            
            case N://A
                if (c == 'a') {
                    instr += c;
                    gc();
                    CH = P;
                } else if (c == 'd') {
                    instr += c;
                    gc();
                    CH = N;
                } else {
                    flag = 1;
                    throw c;
                }
                break;
            case P:
                if(c == '\n') {
                    return instr;
                } else if(c == 'a') {
                    instr += c;
                    CH = N;
                    gc();
                } else {
                    flag = 1;
                    throw c;
                }
                break;
            default:
                flag = 1;
                throw c;
        }
    } while (true);
}

int main() {
    string str;
    try {
        str = Parser();
        cout << str << endl;
    } catch (char c) {
        if(flag){
            cerr << "Error in Lexeme: " << c << endl;
        }
    }
    return 0;
}