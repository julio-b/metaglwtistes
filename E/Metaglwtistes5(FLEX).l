%{
#include "stdio.h"
int sxima=0;
%}
onoma [ΑΒΓΔΕ]+

%%

"Δίνεται"		{printf("%s : είναι ρήμα \n",yytext);}
"γωνία"			{printf("%s : είναι γεωμετρική οντότητα\n",yytext);sxima=1;}
"τρίγωνο"		{printf("%s : είναι γεωμετρική οντότητα\n",yytext);sxima=2;}
"τετράγωνο"		{printf("%s : είναι γεωμετρική οντότητα\n",yytext);sxima=3;}
{onoma}			{if(sxima==1 && yyleng==2)
					printf("%s : είναι όνομα γεωμετρικής οντότητας\n",yytext);
				 else if(sxima==2 && yyleng==6)
					printf("%s : είναι όνομα γεωμετρικής οντότητας\n",yytext);
				 else if(sxima==3 && yyleng==8)
					printf("%s : είναι όνομα γεωμετρικής οντότητας\n",yytext);
				 else
					printf("%s : δεν είναι όνομα γεωμετρικής οντότητας\n%d",yytext,yyleng);
				}
.				;
%%
