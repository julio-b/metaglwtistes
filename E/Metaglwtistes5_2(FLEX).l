%{
#include "stdio.h"
int uniqStr();
int sxima=0;
%}
onoma [ΑΒΓΔΕ]+

%%

"Δίνεται" {printf("%s : είναι ρήμα \n",yytext);}

"γωνία"|"τρίγωνο"|"τετράγωνο" {
	sxima = !strcmp(yytext,"γωνία") ? 1 : !strcmp(yytext,"τρίγωνο") ? 3 :
			!strcmp(yytext,"τετράγωνο") ? 4 : 0;
	printf("%s : είναι γεωμετρική οντότητα\n",yytext);
}

{onoma} {
	if(sxima && uniqStr()==sxima)
		printf("%s : είναι όνομα γεωμετρικής οντότητας\n",yytext);
	else
		printf("%s : δεν είναι όνομα γεωμετρικής οντότητας - %d\n",yytext,yyleng);
}
.	;
%%
int uniqStr(){
	int a[]={0,0,0,0,0};
	for(int i=0; i<yyleng; i++) a[yytext[++i]-'\221']++;
	int tmp=0;
	for(int i=0; i<5; i++) tmp += a[i]?1:0;
	return tmp;
}
