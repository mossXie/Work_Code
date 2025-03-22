#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// 物体
class Figure {
public:
    virtual bool canMove(char fromFile, int fromRank, char toFile, int toRank) const = 0;
    virtual ~Figure() {}
};

// 国王
class King : public Figure {
public:
    bool canMove(char fromFile, int fromRank, char toFile, int toRank) const override {
        int fileDiff = abs(fromFile - toFile);
        int rankDiff = abs(fromRank - toRank);
        return (fileDiff <= 1 && rankDiff <= 1 && (fileDiff + rankDiff) >= 1);
    }
};

// 皇后
class Queen : public Figure {
public:
    bool canMove(char fromFile, int fromRank, char toFile, int toRank) const override {
        int fileDiff = abs(fromFile - toFile);
        int rankDiff = abs(fromRank - toRank);
        return (fileDiff == rankDiff) || (fileDiff == 0 || rankDiff == 0);
    }
};

// 战车
class Rook : public Figure {
public:
    bool canMove(char fromFile, int fromRank, char toFile, int toRank) const override {
        return (fromFile == toFile) || (fromRank == toRank);
    }
};

// 主教
class Bishop : public Figure {
public:
    bool canMove(char fromFile, int fromRank, char toFile, int toRank) const override {
        int fileDiff = abs(fromFile - toFile);
        int rankDiff = abs(fromRank - toRank);
        return (fileDiff == rankDiff);
    }
};

// 骑士
class Knight : public Figure {
public:
    bool canMove(char fromFile, int fromRank, char toFile, int toRank) const override {
        int fileDiff = abs(fromFile - toFile);
        int rankDiff = abs(fromRank - toRank);
        return ((fileDiff == 1 && rankDiff == 2) || (fileDiff == 2 && rankDiff == 1));
    }
};

// 解析器类
class Parser {
public:
    static bool parseInput(const string& input, char& piece, char& fromFile, int& fromRank, char& toFile, int& toRank) {
        size_t space1 = input.find(' ');
        size_t space2 = input.find(' ', space1 + 1);
        
        if (space1 == string::npos || space2 == string::npos) {
            return false;
        }
        
        piece = input[0];
        if (piece >= 'a' && piece <= 'z') {
            piece = piece - 32;
        }
        
        string fromSquare = input.substr(space1 + 1, space2 - space1 - 1);
        string toSquare = input.substr(space2 + 1);
        
        if (fromSquare.length() != 2 || !isalpha(fromSquare[0]) || !isdigit(fromSquare[1])) {
            return false;
        }
        fromFile = fromSquare[0];
        if (fromFile >= 'a' && fromFile <= 'z') {
            fromFile = fromFile - 32;
        }
        fromRank = fromSquare[1] - '0';
        
        if (toSquare.length() != 2 || !isalpha(toSquare[0]) || !isdigit(toSquare[1])) {
            return false;
        }
        toFile = toSquare[0];
        if (toFile >= 'a' && toFile <= 'z') {
            toFile = toFile - 32;
        }
        toRank = toSquare[1] - '0';
        
        if (fromFile < 'A' || fromFile > 'H' || toFile < 'A' || toFile > 'H' ||
            fromRank < 1 || fromRank > 8 || toRank < 1 || toRank > 8) {
            return false;
        }
        
        return true;
    }
};

// 主检查器类
class ChessChecker {
    private:
        Figure* figures[5]; 
    
    public:
        ChessChecker() {
            figures[0] = new King();
            figures[1] = new Queen();
            figures[2] = new Rook();
            figures[3] = new Bishop();
            figures[4] = new Knight();
        }
    
        ~ChessChecker() {
            for (int i = 0; i < 5; i++) {
                delete figures[i];
            }
        }
    
        bool isValidMove(const string& input) {
            char piece, fromFile, toFile;
            int fromRank, toRank;
            
            if (!Parser::parseInput(input, piece, fromFile, fromRank, toFile, toRank)) {
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
            
            return fig->canMove(fromFile, fromRank, toFile, toRank);
        }
};

int main() {
    string input;
    getline(cin, input);
    
    ChessChecker checker;
    cout << (checker.isValidMove(input) ? "YES" : "NO") << endl;
    
    return 0;
}