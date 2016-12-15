#include <stack>
#include <fstream>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void printMoves(string log){
    string stackstring = "$";
    cout<<"Περιεχομενα στοιβας\tκατασταση\tυπολειπα συμβολα εισοδου\n";
        
        while(!log.empty()){
            cout<<stackstring<<"\t\t\t"<<"A\t\t"<<log<<endl;
            if(log[0]=='('){
                log.erase(0,1);
                stackstring+="(";
            }
            else
            if(log[0]==')'){
                log.erase(0,1);
                stackstring.erase(stackstring.size()-1);
            }
            if(stackstring.empty())
                break;
        }
        cout<<stackstring<<"\t\t\t"<<"A\t\t"<<log<<endl;
}

int main(){
	string fname;
	string log="";
	bool in_String = false;
	bool escape_char = false;
	char c;
	stack<char> z;
	cout<<"Give the name of the file\n";
	cin>>fname;
	fstream fs;
	fs.open(fname.c_str());
	while(fs.get(c)){
		cout<<c;
		if(in_String){
			if(!escape_char){
				switch(c){
				 case '"':
				 case '\'':
					in_String=false;
					break;
				 case '\\':
					escape_char=true;
					break;
				}
			}else{
				escape_char=false;
			}
		}else{
			switch(c){
			 case '(':
				z.push(c);
                                log+=c;
				break;
			 case ')':
				if(z.empty()) goto exit_failure;
                                log+=c;
				z.pop();
				break;
			 case '"':
			 case '\'':
				in_String=true;
				break;
			}
		}
	}

	if(!z.empty()) goto exit_failure;

exit_success:
	fs.close();
	cout<<"Yes\n";
        printMoves(log);
	return 0;
exit_failure:
	fs.close();
	cout<<"No\n";
        printMoves(log);
	return 1;
}
