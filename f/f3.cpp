#include <iostream>
using namespace std;

char c;
static int size;
enum {H,A,B,C,D,E,S};
void gc(){ c = cin.get(); }

int Parser(){
    int res = 0;
    int cs = H;
    do{
        gc();
        switch(cs){
            case H: {
                if(c == '-'){
                    res = 5;
                    gc();
                    cs = A;
                }else if(c == '.'){
                    res = 0;
                    gc();
                    cs = B;
                }else throw c;
                break;
            }

            case A:{//-
                if(c == '-'){
                    res++;
                    gc();
                    cs = A;
                }
            }

            case B:{//-
                
            }

            case C:{//._-

            }

            case S:{

            }

            default: break;

        }


    }while(true);
}

int main(){

    try{
        int num;
        num = Parser();
		cout << fixed << num << endl;
    }catch(char c){
		cerr << "Error in Lexeme: " << c << endl;
	}
	return 0;
}