#include <iostream>
#include <string>
#include <random>
/*
S -> A|S+A
A -> B|A*B
B -> a|b|c
 */
#define S_ "<έκφραση>"
#define A_ "<όρος>"
#define B_ "<παράγοντας>"
using namespace std;

#define COLOR

void printSteps(string str);
string strReplaceAll(string str, string search, string replace);
string S(bool step){ return step?"S+A":"A";}
string A(bool step){ return step?"A*B":"B";}
string B(int step){ return step/2?"a":step%2?"b":"c";}

int main(int argc, char** argv){
	string p="S";
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dib(0,1);
	uniform_int_distribution<> dit(0,2);
	cout<<"\n";
	printSteps(p);
	for(int i=0; i<p.length();){
		switch(p[i]){
		 case 'S':
			p.replace(i,1, S(dib(gen)));
			break;
		 case 'A':
			p.replace(i,1, A(dib(gen)));
			break;
		 case 'B':
			p.replace(i,1, B(dit(gen)));
			break;
		 default://{a,b,c,*,+}
			++i;
			continue;
		}
		cout<<" =>\n";
		printSteps(p);
	}
	cout<<"\n\n";
	return 0;
}

void printSteps(string str){
	string s = str;
	s = strReplaceAll(s, "S", S_);
	s = strReplaceAll(s, "A", A_);
	s = strReplaceAll(s, "B", B_);
#ifdef COLOR
	if(s.find_first_of("<")!=string::npos){
		s.insert(s.find_first_of("<"), "\e[31m");
		s.insert(s.find_first_of(">")+1, "\e[0m");
	}
#endif
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
