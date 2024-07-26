#include <stdio.h>
#include <stdlib.h>
#include "lib/util.h"
#include <stdbool.h>

/* Feito por yesyes */


// Atualizado!

/* Programa que vai converter hexstring em binario */

/* informação que ninguem liga (quebrei a cabeça pra fazer esse programa tive que assistir um monte de video e tirando duvida com nosso velho amigo gpt) */ 


typedef unsigned char byte;  


bool install(const char * hexstr, const char * filename);
byte convert_to_bin(char c);

int main(int argc, char * argv[]){
	/* hexadecimal em string */
	
	char *hexstr;
	char *filename;
	if(argc < 3){
		hexstr = "4f6cc3a1206573637265766f206573746120636172746120646520616d6f722070617261206f206d657520616d6f727a696e686f0a0a";
		filename = "MeuAmor.txt";
	}else{
		filename = argv[1];
		hexstr = argv[2];
	}
	
	
	/* chamado a função install() para fazer a conversão e baixar o arquivo */

	bool sucesso = install(hexstr, filename);
	
	/* verificando se o arquivo foi baixado corretamente */
	if(sucesso){
		printf("Arquivo baixado!\n");
	}	

	return 0;
}


bool install(const char * hexstr, const char * filename){
	int len = strlen(hexstr) / 2;  // Cada par de caracteres hexadecimais representa um byte
	byte convert[len]; 

	//criando um ponteiro para o arquivo
	FILE *write = fopen(filename, "wb");
	
	if(write == NULL){
		err("Algo ocorreu error error: \"FileNotCreate\" \n");
	}

	

	for(int i = 0; i < len; i++){
		byte high = convert_to_bin(hexstr[2 * i]);         // Primeiro dígito hex
		byte low = convert_to_bin(hexstr[2 * i + 1]);     // Segundo dígito hex	
		convert[i] = (high << 4) | low; // Combinação dos dois digitos em um byte
	}
	

	fwrite(convert, sizeof(byte), len,write); // escreve os bytes;
	
	fclose(write); //fecha o arquivo
	
	return true;

}
byte convert_to_bin(char c){
	/* aqui esta a conversão */
	switch(c){
		case '0':
			return 0x0;
		case '1':
			return 0x1;
		case '2':
			return 0x2;
		case '3':
			return 0x3;
		case '4':
			return 0x4;
		case '5':
			return 0x5;
		case '6':
			return 0x6;
		case '7':
			return 0x7;
		case '8':
			return 0x8;
		case '9':
			return 0x9;
		case 'a':
			return 0xA;
		case 'b':
			return 0xB;
		case 'c':
			return 0xC;
		case 'd':
			return 0xD;
		case 'e':
			return 0xE;
		case 'f':
			return 0xF;
		default: return 0x0;
	}
}
