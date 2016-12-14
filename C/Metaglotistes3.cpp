#include <iostream>
#include <vector>
#include <string>
#include <exception>

int main(){
    std::string str,str1="S";
    std::cout<<"Give the string you want to check"<<std::endl;
    std::cin>>str;
    int pos = 0;
    while(1){
        if(pos==str1.size() || str[0]!='['){
            break;
        }
        else
        if(str1[pos]=='S'){
            str1.replace(pos,1,"[A]");
            std::cout<<str1<<std::endl;
            pos++;
        }
        else
        if(str1[pos]=='A'){
            str1.replace(pos,1,"BE");
            std::cout<<str1<<std::endl;
        }
        else
        if(str1[pos]=='B'){
            if(str[pos]=='['){
                str1.replace(pos,1,"S");
                std::cout<<str1<<std::endl;
            }
            if(str[pos]=='x'){
                str1.replace(pos,1,"x");
                pos++;
                std::cout<<str1<<std::endl;
            }
            if(str[pos]=='y'){
                str1.replace(pos,1,"y");
                pos++;
                std::cout<<str1<<std::endl;
            }
            else{
                break;
            }
            
        }
        else
        if(str1[pos]=='E'){
            if(str[pos]==':'){
                str1.replace(pos,1,":A");
                std::cout<<str1<<std::endl;
            pos++;
            }
            else if(str[pos]=='+'){
                str1.replace(pos,1,"+A");
                std::cout<<str1<<std::endl;
            pos++;
            }else{
                str1.erase(pos,1);
                std::cout<<str1<<std::endl;
            }
        }
        else 
            if(str1[pos]==']')pos++;
        else
            break;
        
        }
        
    
    if(str==str1){
        std::cout<<"Analysis complete : The string belong in this languange\n";
    }else{
        std::cout<<"Analysis complete : The string does not belong in the language\n";
    }
    
    
    return 0;
}