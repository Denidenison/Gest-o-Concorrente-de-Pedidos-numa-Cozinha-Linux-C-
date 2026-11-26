#ifndef RECEPCIONISTA_H
#define RECEPCIONISTA_H
#Define Max_tam_prato 50
//estrutura de dados para organizar cada pedido
typedef struct{
	int id_pedido;
	char prato[Max_tam_prato];
	int tempo_confecao;	
} Pedido;

#endif
