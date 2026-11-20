#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Num_Recep 1
void ler_argumentos(char *argv[],char **nome_ficheiro, int* num_cozinheiros,int* capacidade_fila,int* num_fogoes){
	char* separador=strchr(argv[1],'.');
	*separador= '\0';
	*nome_ficheiro= argv[1];
	*num_cozinheiros= atoi(argv[2]);
	*capacidade_fila= atoi(argv[3]);
	*num_fogoes= atoi(argv[4]);
}

int main(int argc, char *argv[]) {
	if(argc!=5){
		printf("Numero de argumentos errado");
		return 0;
	}
	char* nome_ficheiro;
	int num_cozinheiros;
	int capacidade_fila;
	int num_fogoes;
	
	ler_argumentos(argv, &nome_ficheiro, &num_cozinheiros, &capacidade_fila, &num_fogoes);
	printf("%s\n", nome_ficheiro);
	printf("%i %i %i", num_cozinheiros, capacidade_fila, num_fogoes);
	
	return 0;
}
