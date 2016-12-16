#include <iostream>
#include <string>
using namespace std;
string s = "";
bool read(char c){
    if(s[0]==c){
        s.erase(0,1);
        cout<<c<<" found\n";
        return true;
    }
    else return false;
}
char peek(){
    return s[0];
}
bool procE();
bool procB();
bool procA(){
    return procB() && procE();
}
bool procS(){
    return read('[') && procA() && read(']');
}
bool procB(){
    switch(peek()){
    case 'x':
        return read('x');
    case 'y':
        return read('y');
    case '[':
        return procS();
    default:
        return false;
    }
}
bool procE(){
    switch(peek()){
    case ':':
        return read(':') && procA();
    case '+':
        return read('+') && procA();
    default:
        return true;
    }
}
int main(){
    cout<<"Give the string you want to test\n";
    cin>>s;
    if(procS() && s.empty()){
        cout<<"Analysis complete: The string belong in the language.";
    }else{
        cout<<"Analysis complete: Error.\n\t"<<s[0]<<" does not belong in the language.";
    }
}
