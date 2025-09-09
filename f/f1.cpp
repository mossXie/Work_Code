#include <iostream>
using namespace std;
char c;//текущий анализируемый символ
enum {H,N,P,S};
void gc(){ c = cin.get(); }
double Parser(){
	double num = 0., dec = 0.1;
	int CS = H;
	gc();//read 1 char
	do{
		switch(CS){
			case H:{
				if(c=='0'||c=='1'){
					num = c-'0';
					gc();
					CS = N;
				}else throw c;break;
			}
			case N:{
				if(c=='0'||c=='1'){
					num = num*10+c-'0';
					gc();
					CS = N;
				}else if(c=='.'){
					gc();
					CS = P;
				}else throw c;break;

			}
			case P:{
				if(c=='0'||c=='1'){
					num += dec*(c-'0');
					gc();
					CS = S;
				}else throw c;break;
			}
			case S:{
				
				if(c=='0'||c=='1'){
					dec *= 0.1;
					num+=dec*(c-'0');
					gc();
					CS = S;
				}else if(c=='\n') return num;
				else throw c;break;
			}default: break;
		}
	}while(true);
}
int main(){

	double num = 0.;
	try{
		num = Parser();
		cout << fixed << num << endl;
	}catch(char c){
		cerr << "Error in Lexeme: " << c << endl;
	}
	return 0;
}