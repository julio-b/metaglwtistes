%{
#include "stdio.h"
int sxima=0;
char* names[] = {"", "γωνία", "", "τρίγωνο", "τετράγωνο"};

char uniqyytext[2*6];
int uniqyytextleng;
int uniqStr();
int f;

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
	uniqyytextleng = uniqStr();
	f = yyleng/2!=sxima;
	printf("%s %c%s%c: είναι όνομα γεωμετρικής οντότητας",uniqyytext,
			f?'(':'\0', f?yytext:"", f?')':'\0');
	if(uniqyytextleng!=sxima) printf(", αλλα δεν αντιστοιχει σε %s",names[sxima]);
	puts("");
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
