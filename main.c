#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Num_Recep 1

//estrutura de dados para organizar cada pedido
typedef struct{
	int id_pedido;
	char prato[50];
	int tempo_confecao;	
} Pedido;

//Lê todos os argumentos passados pelo usuário
void ler_argumentos(char *argv[],char **nome_ficheiro, int* num_cozinheiros,int* capacidade_fila,int* num_fogoes){
	*nome_ficheiro= argv[1];
	*num_cozinheiros= atoi(argv[2]);
	*capacidade_fila= atoi(argv[3]);
	*num_fogoes= atoi(argv[4]);
}

//Lê do ficheiro e prepara um Array com todos os pedidos e suas informações
void ler_ficheiro(FILE *f, Pedido fila_pedidos[], int capacidade_fila) {
    int i = 0;
    while (i < capacidade_fila && fscanf(f, "%d;%49[^;];%d", &fila_pedidos[i].id_pedido, fila_pedidos[i].prato, &fila_pedidos[i].tempo_confecao) == 3) {
        i++;
    }
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
	
	Pedido* fila_pedidos= malloc(sizeof(Pedido)*capacidade_fila);
	
	FILE* f= fopen(nome_ficheiro,"r");
	if (f == NULL) {
    perror("Erro ao abrir o ficheiro");
    	return 1;
	}
	
	ler_ficheiro(f, fila_pedidos, capacidade_fila);
	return 0;
}
