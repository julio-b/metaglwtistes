%{
#include <stdio.h>
%}
IDENTIFIER [a-zA-Z_][a-zA-Z_0-9]*
%%

[ \t\n]+
"var" {printf("%s is a keyword (variables declaration)\n", yytext); }
"integer"|"real"|"boolean"|"char" {printf("%s is a keyword (type definition)\n", yytext);}
{IDENTIFIER} {printf("%s is an identifier\n", yytext);}
","|":"|";" {printf("%s is a separator symbol\n", yytext);}
. ;

%%
int main(int argc, char** argv){
	//read from file or stdin
	if(argc>1){
		yyin = fopen(argv[1], "r");
		if(!yyin){ printf("%s: file error\n", argv[1]);  yyin = stdin;}
	}

	yylex();
	if(yyin) fclose(yyin);
	return 0;
}
