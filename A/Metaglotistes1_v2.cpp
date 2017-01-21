#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string getBrackets(istream* in);

int main(int argc, char** argv){
	string file_name="";
	ifstream inputfs;
	istream* in;
	bool p_Steps = false;

	for(int i=1; i<argc; i++){ //get arguments
		string ar = argv[i];
		if(ar=="-h" || ar=="--help"){
			cout<<"Usage: "<<argv[0]<<" -p [filename]\n";
			return 0;
		}else if(ar=="-p"){
			p_Steps = true;
		}else if(!file_name.compare("")){
			file_name = ar;
		}else{
			cout<<"Invalid argument: "<<ar<<".\n";
			return -1;
		}
	}
	//read from file or cin
	inputfs.open(file_name.c_str());
	in = inputfs.is_open() ? &inputfs : &cin;
	if(in == &cin){
		if(file_name.compare("")) cout<<file_name<<" file failed!";
		cout<<"Type your program.. <ENTER><CTRL-D> when you're done.\n";
	}

	////////ΝΑΣ///////////////////////////////
	string stackstring = "$";
	#define StackTop stackstring[stackstring.size()-1]
	#define StackEmpty stackstring.compare("$")==0
	#define StackPop stackstring.erase(stackstring.size()-1)
	#define StackPush(C) stackstring+=( C )

	string input = getBrackets(in);
	#define input_getch input[0]; input.erase(0,1); if(input.empty()) input="ε"
	int katastasi=1;
	#define printStep if(p_Steps) cout<<stackstring<<"\t\t\t"<<katastasi<<"\t\t"<<input<<endl

	if(p_Steps) cout<<"Περιεχομενα στοιβας\tκατασταση\tυπολειπα συμβολα εισοδου\n";
	printStep;
	while(!input.empty()&&input.compare("ε")){
		char c = input_getch;
		switch(c){
			case '(':
				StackPush('(');
				katastasi=2;
				printStep;
				break;
			case ')':
				if(StackTop!='('){
					if(p_Steps) cout<<"error: found ')' but stack is empty\n";
					goto _exit;
				}
				StackPop;
				printStep;
				if(StackEmpty){//ε-μεταβαση
					katastasi=1;
					printStep;
				}
				break;
		}
	}
	//input=="ε"
	if(!StackEmpty){
		if(p_Steps) cout<<"error: input ε, but stack isn't empty\n";
	}else if(katastasi==1){//ε-μεταβαση
		katastasi=3;
		printStep;
	}
	/////////////////////////////////////////////////////

_exit:
	string result = (katastasi==3)? "YES" : "NO";
	cout<<"\n"<<result<<"\n";
	if(inputfs.is_open()) inputfs.close();
	return katastasi-3;
}///main


//read in, till EOF
//ignore all chars from strings
//ignore all chars outside of strings, except brackets '(' & ')'
//e.g.  (adqweq"we)\"()("((')'))  returns ((())
string getBrackets(istream* in){
	bool in_String = false;
	bool escape_char = false;
	char quotes = '\0';
	char c;
	string br;
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
				case ')':
					br+=c;
					break;
				case '"':
				case '\'':
					in_String=true;
					quotes = c;
					break;
			}
		}
	}
	return br;
}
