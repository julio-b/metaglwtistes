#include <stack>
#include <fstream>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main(){
    string fname;
    string log="";
	bool itsFine = true;
	char c;
	stack<char> z;
	cout<<"Give the name of the file\n";
	cin>>fname;
	fstream fs;
    fs.open(fname.c_str());
	while(fs.get(c)){
            if(c=='\"'){
                fs.ignore(numeric_limits<streamsize>::max(),'\"');
            }
            if(c=='\'')
                fs.ignore(numeric_limits<streamsize>::max(),'\'');            
        if(c=='('){
            z.push(c);
        }
        if(c==')'){
            if(z.empty())
                itsFine=false;
            else
                z.pop();
        }
	}
	if(!z.empty())
        itsFine=false;

    if(itsFine)
         cout<<"Yes\n";
    else
         cout<<"No\n";
    fs.close();

	return 0;
}
