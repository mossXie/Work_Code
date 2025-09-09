#include <iostream>
#include <stack>
using namespace std;

int c;
void gc();

int main(){
    int n1 = 0, n2 = 0, num = 0;
    int res = 0;
    stack<int> P1;
    gc();
    while(c != '\n' && c != EOF){
        if(c >= '0' && c <= '9'){
            num = c - '0';
            P1.push(num);
            gc();
        }else if(c == ' '){
            gc();
        }else{
            switch(c){
                case '+':   
                    n1 = P1.top();
                    P1.pop();
                    n2 = P1.top();
                    P1.pop();
                    res = n1 + n2;
                    P1.push(res);
                    gc();
                    break;
                case '-':
                    n1 = P1.top();
                    P1.pop();
                    n2 = P1.top();
                    P1.pop();
                    res = n1 - n2;
                    P1.push(res);
                    gc();
                    break;
                case '*':
                    n1 = P1.top();
                    P1.pop();
                    n2 = P1.top();
                    P1.pop();
                    res = n1 * n2;
                    P1.push(res);
                    gc();
                    break;
                case '/':
                    n1 = P1.top();
                    P1.pop();
                    n2 = P1.top();
                    P1.pop();
                    res = n1 / n2;
                    P1.push(res);
                    gc();
                    break;
                case '@':
                    n1 = -P1.top();
                    P1.pop();
                    P1.push(n1);
                    gc();
                    break;
                default:
                    break;
            }
        }
    }
    res = P1.top();
    P1.pop();
    cout << res << endl;
    return 0;
}

void gc(){
    c = cin.get();
}
