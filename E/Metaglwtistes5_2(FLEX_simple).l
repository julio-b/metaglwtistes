%option noyywrap
%{
#include "stdio.h"
char uniqyytext[2*6];
int uniqStr();
int f;
%}
onoma [ΑΒΓΔΕ]+
%%
"Δίνεται" {printf("%s : είναι ρήμα \n",yytext);}
"γωνία"|"τρίγωνο"|"τετράγωνο" {printf("%s : είναι γεωμετρική οντότητα\n",yytext);}
{onoma} {
	f = yyleng/2!=uniqStr();
	printf("%s %c%s%c: είναι όνομα γεωμετρικής οντότητας\n",uniqyytext,
			f?'(':'\0', f?yytext:"", f?')':'\0');
}
.	;
%%
int uniqStr(){
	int a[]={0,0,0,0,0};
	for(int i=0; i<yyleng; i++) a[yytext[++i]-'\221']++;
	int tmp=0;
	for(int i=0; i<5; i++) tmp += a[i]?1:0;
	for(int i=0; i<12; i++) uniqyytext[i]='\000';
	for(int i=0, j=0; i<yyleng; i+=2)
		if(a[yytext[i+1]-'\221']){
			a[yytext[i+1]-'\221']=0;
			uniqyytext[j++]=yytext[i];
			uniqyytext[j++]=yytext[i+1];
		}
	return tmp;
}
