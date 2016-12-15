#include <stack>
#include <fstream>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

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
				break;
			 case ')':
				if(z.empty()) goto exit_failure;
				z.pop();
				break;
			 case '"':
				in_String=true;
				break;
			}
		}
	}

	if(!z.empty()) goto exit_failure;

exit_success:
	fs.close();
	cout<<"Yes\n";
	return 0;
exit_failure:
	fs.close();
	cout<<"No\n";
	return 1;
}
