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
<INITIAL>"var" {printf("var\n"); BEGIN VAR;}
<VAR>{IDENTIFIER} {printf("%s id\n", yytext);BEGIN DEC;}
<DEC>"," {BEGIN VAR;}
<DEC>":" {BEGIN _TYPE;}
<_TYPE>"integer"|"real"|"boolean"|"char" {printf("%s type\n", yytext);BEGIN TYPE;}
<TYPE>";" {BEGIN VAR;}
. {printf("%s error\n", yytext); errors++;}
%%
int main(int argc, char** argv){
	if(argc<2) return 1;
	yyin = fopen(argv[1], "r");
	if(!yyin){ printf("%s: file error\n", argv[1]); return 2; }
	yylex();
	fclose(yyin);
	if(errors) printf("%d errors found in source file\n", errors);
	else printf("Source file is OK\n");
	return -errors;
}
