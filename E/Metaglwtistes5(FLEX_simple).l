%option noyywrap
%{
#include "stdio.h"
%}
onoma [ΑΒΓΔΕ]+
%%
[ \t\n]+
"Δίνεται" {printf("%s : είναι ρήμα \n",yytext);}
"γωνία"|"τρίγωνο"|"τετράγωνο" {printf("%s : είναι γεωμετρική οντότητα\n",yytext);}
{onoma} {printf("%s : είναι όνομα γεωμετρικής οντότητας\n",yytext);}
.	;
%%
