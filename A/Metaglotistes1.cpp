#include <stack>
#include <fstream>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void printSteps(string log);

int main(int argc, char** argv){
	string file_name="";
	ifstream inputfs;
	istream* in;
	bool p_Moves = false;
	bool in_String = false;
	bool escape_char = false;
	char quotes = '\0';
	int errcode;
	string log="";
	stack<char> z;
	char c;

	for(int i=1; i<argc; i++){
		string ar = argv[i];
		if(ar=="-h" || ar=="--help"){
			cout<<"Usage: "<<argv[0]<<" -p [filename]\n";
			return 0;
		}else if(ar=="-p"){
			p_Moves = true;
		}else if(!file_name.compare("")){
			file_name = ar;
		}else{
			cout<<"Invalid argument: "<<ar<<".\n";
			return 1;
		}
	}

	inputfs.open(file_name.c_str());
	in = inputfs.is_open() ? &inputfs : &cin;
	
	if(in == &cin){
		if(file_name.compare("")) cout<<file_name<<" file failed!";
		cout<<"Type your program.. <ENTER><CTRL-D> when you're done.\n";
	}

	while(in->get(c)){
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

exit_success:
	cout<<"\nYES\n";
	errcode=0;
	goto _exit;
exit_failure:
	cout<<"\nNO\n";
	errcode=1;
_exit:
	if(p_Moves) printSteps(log);
	if(inputfs.is_open()) inputfs.close();
	return errcode;
}

void printSteps(string log){
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

