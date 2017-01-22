#include <iostream>
#include <string>
using namespace std;

#define S  "S->[A]"
#define A  "A->BE"
#define B1 "B->x"
#define B2 "B->y"
#define B3 "B->S"
#define E1 "E->:A"
#define E2 "E->+A"
#define E3 "E->ε"
#define _PS(ST) cout<<spaces<<str<<"\t\t" ST "\n"; //printStep

char peek();
bool read(char c);
bool procS();
bool procA();
bool procB();
bool procE();

string str = "";
string spaces = "";

int main(){
    cout<<"Give the string you want to test\n";
    cin>>str;
    cout<<"\n";
    if(procS() && str.empty()){
        cout<<"Analysis complete: The string belong in the language.\n";
    }else{
        cout<<"Analysis complete: Error.\n\t"<<str[0]<<" does not belong in the language.\n";
    }
}

char peek(){
    return str[0];
}

bool read(char c){
    if(str[0]==c){
        str.erase(0,1);
        spaces.append(" ");
        cout<<spaces<<str<<"\n";
        return true;
    }
    else return false;
}

bool procS(){
    _PS(S) return read('[') && procA() && read(']');
}

bool procA(){
    _PS(A) return procB() && procE();
}

bool procB(){
    switch(peek()){
    case 'x':
        _PS(B1) return read('x');
    case 'y':
        _PS(B2) return read('y');
    case '[':
        _PS(B3) return procS();
    default:
        return false;
    }
}

bool procE(){
    switch(peek()){
    case ':':
        _PS(E1) return read(':') && procA();
    case '+':
        _PS(E2) return read('+') && procA();
    default:
        _PS(E3) return true;
    }
}
