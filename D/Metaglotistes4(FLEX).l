%{
#include <stdio.h>
int errors=0;
%}

IDENTIFIER [a-zA-Z_][a-zA-Z_0-9]*
%s VAR 
%s DEC
%s _TYPE
%s TYPE

%%

[ \t\n]+
<INITIAL>"var" {printf("%s is a keyword (variables declaration)\n", yytext); BEGIN VAR;}
<_TYPE>"integer"|"real"|"boolean"|"char" {printf("%s is a keyword (type definition)\n", yytext);BEGIN TYPE;}
<VAR>{IDENTIFIER} {printf("%s is an identifier\n", yytext);BEGIN DEC;}
<DEC>"," {printf("%s is a separator symbol\n", yytext);BEGIN VAR;}
<DEC>":" {printf("%s is a separator symbol\n", yytext);BEGIN _TYPE;}
<TYPE>";" {printf("%s is a separator symbol\n", yytext);BEGIN VAR;}
[^ \t\n,:;]+ {printf("Unexpected word %s\n", yytext); errors++;}
. {printf("Unexpected symbol %s\n", yytext); errors++;}

%%

int main(int argc, char** argv){
	//read from file or stdin
	if(argc>1){
		yyin = fopen(argv[1], "r");
		if(!yyin){ printf("%s: file error\n", argv[1]);  yyin = stdin;}
	}

	yylex();
	if(yyin) fclose(yyin);
	if(errors) printf("\n%d errors found in source file\n", errors);
	return errors;
}
