#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 物体
class Figure {
public:
    virtual bool canMove(char fromName, int fromNum, char toName, int toNum) const = 0;
    virtual ~Figure();
};

Figure::~Figure() {}

// 国王
class King : public Figure {
public:
    bool canMove(char fromName, int fromNum, char toName, int toNum) const override;
};

bool King::canMove(char fromName, int fromNum, char toName, int toNum) const {
    int nameDiff = abs(fromName - toName);
    int numDiff = abs(fromNum - toNum);
    return (nameDiff <= 1 && numDiff <= 1 && (nameDiff + numDiff) >= 1);
}

// 皇后
class Queen : public Figure {
public:
    bool canMove(char fromName, int fromNum, char toName, int toNum) const override;
};

bool Queen::canMove(char fromName, int fromNum, char toName, int toNum) const {
    int nameDiff = abs(fromName - toName);
    int numDiff = abs(fromNum - toNum);
    return (nameDiff == numDiff) || (nameDiff == 0 || numDiff == 0);
}

// 战车
class Rook : public Figure {
public:
    bool canMove(char fromName, int fromNum, char toName, int toNum) const override;
};

bool Rook::canMove(char fromName, int fromNum, char toName, int toNum) const {
    return (fromName == toName) || (fromNum == toNum);
}

// 主教
class Bishop : public Figure {
public:
    bool canMove(char fromName, int fromNum, char toName, int toNum) const override;
};

bool Bishop::canMove(char fromName, int fromNum, char toName, int toNum) const {
    int nameDiff = abs(fromName - toName);
    int numDiff = abs(fromNum - toNum);
    return (nameDiff == numDiff);
}

// 骑士
class Knight : public Figure {
public:
    bool canMove(char fromName, int fromNum, char toName, int toNum) const override;
};

bool Knight::canMove(char fromName, int fromNum, char toName, int toNum) const {
    int nameDiff = abs(fromName - toName);
    int numDiff = abs(fromNum - toNum);
    return ((nameDiff == 1 && numDiff == 2) || (nameDiff == 2 && numDiff == 1));
}

// 解析器类
class Parser {
public:
    static bool parseInput(const string& input, char& piece, char& fromName, int& fromNum, char& toName, int& toNum);
};

bool Parser::parseInput(const string& input, char& piece, char& fromName, int& fromNum, char& toName, int& toNum) {
    string fromAddress = input.substr(2, 3); 
    string toAddress = input.substr(6);     

    piece = input[0];

    fromName = fromAddress[0];
    if (fromName >= 'a' && fromName <= 'z') {
        fromName = fromName - 32;
    }
    fromNum = fromAddress[1] - '0';

    toName = toAddress[0];
    if (toName >= 'a' && toName <= 'z') {
        toName = toName - 32;
    }
    toNum = toAddress[1] - '0';

    if (fromName < 'A' || fromName > 'H' || toName < 'A' || toName > 'H' ||
        fromNum < 1 || fromNum > 8 || toNum < 1 || toNum > 8) {
        return false;
    }

    return true;
}

// 主检查器类
class ChessChecker {
private:
    Figure* figures[5];

public:
    ChessChecker();
    ~ChessChecker();
    bool isValidMove(const string& input);
};

ChessChecker::ChessChecker() {
    figures[0] = new King();
    figures[1] = new Queen();
    figures[2] = new Rook();
    figures[3] = new Bishop();
    figures[4] = new Knight();
}

ChessChecker::~ChessChecker() {
    for (int i = 0; i < 5; i++) {
        delete figures[i];
    }
}

bool ChessChecker::isValidMove(const string& input) {
    char piece, fromName, toName;
    int fromNum, toNum;

    if (!Parser::parseInput(input, piece, fromName, fromNum, toName, toNum)) {
        return false;
    }

    Figure* fig = nullptr;
    switch (piece) {
        case 'K':
            fig = figures[0];
            break;
        case 'Q':
            fig = figures[1];
            break;
        case 'R':
            fig = figures[2];
            break;
        case 'B':
            fig = figures[3];
            break;
        case 'N':
            fig = figures[4];
            break;
        default:
            return false;
    }

    return fig->canMove(fromName, fromNum, toName, toNum);
}

int main() {
    string input;
    getline(cin, input);

    ChessChecker checker;
    cout << (checker.isValidMove(input) ? "YES" : "NO") << endl;

    return 0;
}