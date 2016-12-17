#include <iostream>
#include <string>
#include <stack>
/*
S -> A|S+A
A -> B|A*B
B -> a|b|c
 */
#define S_ "<έκφραση>"
#define A_ "<όρος>"
#define B_ "<παράγοντας>"
using namespace std;
typedef stack<string> strStack;

bool isValidInput(string str);
string S(strStack& s);
string A(strStack& s);
string B(strStack& s);
void printSteps(string str);
string strReplaceAll(string str, string search, string replace);

int main(int argc, char** argv){
	strStack st;
	string input="";
	string p="S";
	if(argc>=2) input=argv[1];
	if(!isValidInput(input)) do{
		//cout<<"Δωσε την εκφραση\n";
		cout<<"Type your expression\n";
		cin>>input;
	}while(!isValidInput(input) && (cout<<"Invalid expression. ", true));
	st.push(input);
	cout<<"\n";
	printSteps(p);
	for(int i=0; i<p.length();){
		switch(p[i]){
		 case 'S':
			p.replace(i,1, S(st));
			break;
		 case 'A':
			p.replace(i,1, A(st));
			break;
		 case 'B':
			p.replace(i,1, B(st));
			break;
		 default:
			++i;
			continue;
		}
		//cout<<p<<"\n";
		cout<<" =>\n";
		printSteps(p);
	}
	cout<<"\n\n";
	return 0;
}

bool isValidInput(string str){
	char c1, c2;
	//for(int i=0; i<str.length();i++)
	//	if((c=str[i])!='a'&&c!='b'&&c!='c'&&c!='+'&&c!='*') return false;
	for(int i=0; i<str.length()-1;i++)
		if(((c1=str[i])==(c2=str[i+1]))
		 ||(!((c1=='+'||c1=='*')&&(c2=='a'||c2=='b'||c2=='c'))
		 &&!((c2=='+'||c2=='*')&&(c1=='a'||c1=='b'||c1=='c'))))
		 	return false;
	return true;
}
//!!Code duplicate S, A
string S(strStack& s){
	string str = s.top();s.pop();
	size_t i;
	if((i = str.find_last_of("+") ) != -1){
		s.push(str.substr(i+1));
		s.push(str.substr(0,i));
		return "S+A";
	}
	s.push(str);
	return "A";
}

string A(strStack& s){
	string str = s.top();s.pop();
	size_t i;
	if((i = str.find_last_of("*") )!= -1){
		s.push(str.substr(i+1));
		s.push(str.substr(0,i));
		return "A*B";
	}
	s.push(str);
	return "B";
}

string B(strStack& s){
	string str = s.top();s.pop();
	return str;
}

void printSteps(string str){
	string s = str;
	s = strReplaceAll(s, "S", S_);
	s = strReplaceAll(s, "A", A_);
	s = strReplaceAll(s, "B", B_);
	cout<<s;
}

string strReplaceAll(string str, string search, string replace){
	size_t pos = 0;
	while((pos=str.find(search, pos) )!= -1){
		str.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return str;
}
