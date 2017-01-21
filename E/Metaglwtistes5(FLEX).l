%{
#include "stdio.h"
int sxima=0;
char* names[] = {"", "γωνία", "", "τρίγωνο", "τετράγωνο"};
%}
onoma [ΑΒΓΔΕ]+

%%

[ \t\n]+

"Δίνεται" {printf("%s : είναι ρήμα \n",yytext);}

"γωνία"|"τρίγωνο"|"τετράγωνο" {
	sxima = !strcmp(yytext,"γωνία") ? 1 : !strcmp(yytext,"τρίγωνο") ? 3 :
			!strcmp(yytext,"τετράγωνο") ? 4 : 0;
	printf("%s : είναι γεωμετρική οντότητα\n",yytext);
}

{onoma} {
	printf("%s : είναι όνομα γεωμετρικής οντότητας",yytext);
	if(yyleng/2!=sxima) printf(", αλλα δεν αντιστοιχει σε %s",names[sxima]);
	puts("");
}
.	;
%%
