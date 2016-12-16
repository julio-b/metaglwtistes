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
                stackstring+="I";
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

int main(int argc, char** argv){
	string fname;
	string log="";
	bool p_Moves = false;
	bool in_String = false;
	bool escape_char = false;
	char quotes = '\0';
	char c;
	stack<char> z;
	fstream fs;

	for(int i=1; i<argc; i++){ //! recheck loop
		string ar = argv[i];
		//cout<<ar;
		if(ar=="-h" || ar=="--help"){
			//print help here and exit
			//break;
			return 0;
		}else if(ar=="-p"){
			p_Moves = true;
		}else{
			fname = ar;
			//break;
		}
	}
	//change this to stdin pipe
	while(fs.open(fname.c_str()) , !fs.is_open()){
		cout<<"Give the name of the file\n";
		cin>>fname;
	}

	while(fs.get(c)){
		if(in_String){
			if(!escape_char){
				switch(c){
				 case '"':
				 case '\'':
					if(quotes == c) in_String=false;
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
				quotes = c;
				break;
			}
		}
	}

	if(!z.empty()) goto exit_failure;

//!! fix code duplicate
exit_success:
	fs.close();
	cout<<"YES\n";
	if(p_Moves) printMoves(log);
	return 0;
exit_failure:
	fs.close();
	cout<<"NO\n";
	if(p_Moves) printMoves(log);
	return -1;
}
