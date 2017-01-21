%{
#include "stdio.h"
int sxima=0;
char* names[] = {"", "γωνία", "", "τρίγωνο", "τετράγωνο"};
%}
onoma [ΑΒΓΔΕ]+
%s RIMA
%s GEONTOTITA
%%

[ \t\n]+

<INITIAL>"Δίνεται" {printf("%s : είναι ρήμα \n",yytext);BEGIN RIMA;}

<RIMA>"γωνία"|"τρίγωνο"|"τετράγωνο" {
	sxima = !strcmp(yytext,"γωνία") ? 1 : !strcmp(yytext,"τρίγωνο") ? 3 :
			!strcmp(yytext,"τετράγωνο") ? 4 : 0;
	printf("%s : είναι γεωμετρική οντότητα\n",yytext);
	BEGIN GEONTOTITA;
}

<GEONTOTITA>{onoma} {
	printf("%s : είναι όνομα γεωμετρικής οντότητας",yytext);
	if(yyleng/2!=sxima) printf(", αλλα δεν αντιστοιχει σε %s",names[sxima]);
	puts("");
	BEGIN INITIAL;
}

[^ \t\n]+	{printf("Unexpected %s\n", yytext);}//test 

%%
