#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/util.h"

/* Feito pelo yesyespro */

/* programa que lera hexadecimal */

typedef unsigned char byte;


#define VERSAO "0.0"




int main(int argc, char * argv[]){
	/* Pegando hora atual */
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	char *ola;

	/* criando uma variavel para ler os bytes */
	byte codigo[1024];

	/* Verificando que horas é */

	if(tm.tm_hour < 13){
		ola = "Bom dia";
	}else if(tm.tm_hour < 18){
		ola = "Boa tarde";
	}else if(tm.tm_hour > 6){
		ola = "Boa noite";
	}
	
	/* Verificando argumento */
	if(argc < 2){
		printf("%s%s%s\n", RED, getenv("USER"),RESET);
		err("Por favor coloque argumento\n");
	}

	//	printf("%s%s %s %s\n", GREEN, ola, getenv("USER"), RESET);

	/* Verificando se o ponteiro do arquivo existe */

	FILE *read_hex = fopen(argv[1], "rb");
	
	if(read_hex == NULL){
		err("Arquivo não existe\n");
	}

	/* lendo os bytes com fread */
	size_t n;
	while((n = fread(codigo, 1, sizeof(codigo), read_hex)) > 0 ){
		for(size_t i = 0; i < n; i++){
			printf("%02x", codigo[i]);
		}
	}
	printf("\n");
	return 0;
}
