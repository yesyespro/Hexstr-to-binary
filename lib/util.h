#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>


/* biblioteca criada para ajudar no hexstr */

#define RED "\e[0;31m"
#define GREEN "\e[0;32m"

#define RESET "\e[0;m"


bool cmp(const char * veri, const char * veri2);
char * input();
void debug(const char * texto, int num,...);
void err(const char * err);
void note(const char * texto);

#ifndef BUCETA_H
#define BUCETA_H

bool cmp(const char * veri, const char * veri2){
	int usado = 0;
	int tamanho1 = strlen(veri);
	int tamanho2 = strlen(veri2);

	if(tamanho1 == tamanho2){
		return true;
	}else{
		return false;
	}
	
	for(int i = 0; i < tamanho2; i++){
		if(veri[i] ==  veri2[i]){
			usado += 1;
		}
	}
	
	if(usado >= tamanho2){
		return true;
	}else{
		return false;
	}

}

char * input(){
	int tamanho = 50;
	char *p = (char*) malloc(tamanho+1*sizeof(char));
	
	if(p == NULL){
		err("alocação de memoria não sucedida\n");
	}


	int usado = 0;
	int ch;
	while( (ch = getchar()) != EOF && ch != '\n' ){
		p[usado++] = (char) ch;
		
		if(usado >= tamanho){
			tamanho *= 2;
			char *p_novo = (char*) realloc(p, tamanho+1*sizeof(char));
			if(p_novo == NULL){
				err("erro ao realocar memoria\n");
			}

			p = p_novo;			

		}
	
	}
	p[usado] = '\0';
	return p;

}
void debug(const char * texto, int num,...){
	
	// COLOCANDO TEXTO NO MODO VERDE 
	printf("%s", GREEN);

	va_list args;
	va_start(args, num);

	for(int i = 0; i < strlen(texto); i++){
		
		if(texto[i] == '%'){
			printf("%s", va_arg(args, char*));
		}else{
			putchar(texto[i]);
		}
	}


	//finalizando
	printf("%s", RESET);	
	va_end(args);

}

void err(const char * err){
	printf("%s%s%s", RED, err, RESET);
	exit(1);
}

void note(const char * texto){
	printf("%s%s%s", RED, texto, RESET);
}

#endif
