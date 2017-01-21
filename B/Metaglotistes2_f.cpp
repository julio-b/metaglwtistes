#include <iostream>
#include <string>
#include <random>
/*
G = ({S,A,B}, {a,b,c,+,*}, P, S)

P:	S -> A|S+A
	A -> B|A*B
	B -> a|b|c
---------------------------------
BNF:
1. <έκφραση< ::= <όρος>|<έκφραση>+<όρος>
2. <όρος> ::= <παράγοντας>|<όρος>*<παράγοντας>
3. <πααγοντας> ::= a|b|c
*/
#define S_ "<έκφραση>"
#define A_ "<όρος>"
#define B_ "<παράγοντας>"

using namespace std;

string S(int step){ return step?"S+A":"A";}//choose S->A or S->S+A
string A(int step){ return step?"A*B":"B";}
string B(int step){ return step/2?"a":step%2?"b":"c";}

string printStep(string str);
string strReplaceAll(string str, string search, string replace);

#define COLOR

int main(){
	//init random
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> rand1(0,1);
	uniform_int_distribution<> rand2(0,2);

	cout<<"Random generation:\n\n";
	string str="S";
	cout<<printStep(str);
	for(int i=0; i<str.length();){
		switch(str[i]){
		 case 'S':
			str.replace(i, 1, S(rand1(gen)) );
			break;
		 case 'A':
			str.replace(i, 1, A(rand1(gen)) );
			break;
		 case 'B':
			str.replace(i, 1, B(rand2(gen)) );
			break;
		 default://{a,b,c,*,+}
			++i;
			continue;
		}
		cout<<" =>\n"<<printStep(str);
	}
	cout<<"\n\n";
	return 0;
}

//e.g if str="A*B+A" then printStep="<όρος>*<βασικό>+<όρος>"
string printStep(string str){
	string s = str;
	s = strReplaceAll(s, "S", S_);
	s = strReplaceAll(s, "A", A_);
	s = strReplaceAll(s, "B", B_);
#ifdef COLOR  ///add red color
	if(s.find_first_of("<")!=string::npos){
		s.insert(s.find_first_of("<"), "\e[31m");
		s.insert(s.find_first_of(">")+1, "\e[0m");
	}
#endif
	return s;
}

string strReplaceAll(string str, string search, string replace){
	size_t pos = 0;
	while((pos=str.find(search, pos) )!= -1){
		str.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return str;
}
