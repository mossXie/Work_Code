#include <iostream>
using namespace std;

char c;
int count0 = 0;
int count1 = 0;

void gc();
void S();
void A();

int main() {
    try {
        gc();
        S();
        A();
        if (c == '\n') {
            for(int i = 0; i < count0; i++){
                cout << 'a';
            }
            for(int i = 0; i < count1; i++){
                cout << 'b';
            }
            cout << endl;
        } else {
            throw c;
        }
    } catch (char err) {
        cerr << "Error in: " << err << endl;
    }
    return 0;
}

void gc() {
    c = cin.get();
}

void S() {
    if (c == '0') {
        count0++;
        gc();
        A();
    } else if (c == '1') {
        count1++;
        gc();
        A();
    } else {
        throw c;
    }
}

void A() {
    if (c == '0') {
        count0++;
        gc();
        A();
    } else if (c == '1') {
        count1++;
        gc();
        A();
    }else if (c != '\n') {
        throw c;
    }
}