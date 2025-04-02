#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ExceptionPlayer{
    private:
        string msg_;

};

class Player{
    public:
        Player(string name = " ", int num = 0);
        void Print() const {cout << name_ << " " << num_ << endl;}
    private:
        string name_;
        int num_;
};


void Players()
{
        Player pl1("Zenit", 10);
        Player pl2("Zenit", 11);
        Player pl3("CSKA", 23);
        Player pl4("CSKA", 10);
        Player pl5("Zenit", 4);
        Player pl6("Zenit", 1);
        Player pl7("CSKA", 7);
        Player pl8("Zenit", 8);

        pl1.Print();
        pl3.Print();
        Player::Print_teams();
}

int main(){
    try{
        Players();
    }catch(...){
        cerr << "Unknown error" << endl;
        return 1;
    }

    return 0;
}