#include <iostream>
#include <string>
using namespace std;
int main(){
    string str,str1="S";
    cout<<"Give the string you want to check"<<endl;
    cin>>str;
    int pos = 0;
    while(1){
        if(pos==str1.size() || str[0]!='[') break;
        switch(str1[pos]){
        case 'S':
            str1.replace(pos,1,"[A]");
            pos++;
            break;
        case 'A':
            str1.replace(pos,1,"BE");
            break;
        case 'B':
            switch(str[pos]){
            case '[':
                str1.replace(pos,1,"S");
                break;
            case 'x':
                str1.replace(pos,1,"x");
                pos++;
                break;
            case 'y':
                str1.replace(pos,1,"y");
                pos++;
                break;
            default:
                goto f;
            }
            break;
        case 'E':
            switch(str[pos]){
            case ':':
                str1.replace(pos,1,":A");
                pos++;
                break;
            case '+':
                str1.replace(pos,1,"+A");
                pos++;
                break;
            default:
                str1.erase(pos,1);
            }
            break;
        case ']':
            pos++;
        }
        cout<<str1<<endl;
    }
    if(str==str1){
        cout<<"Analysis complete : The string belong in this language\n";
    }else{
        f:
        cout<<"Analysis complete : The string does not belong in the language\n";
    }
    return 0;
}
