#include "funcionario.h"

struct funcionario{
	char nome[255];
	char cargo[255];
	int idade;
	struct funcionario* proximo;
}; 

Funcionario* criaLista(){
	return NULL;
}

Funcionario* desalocaLista(Funcionario* lista){
	Funcionario* func = lista;
	while (func!=NULL){
		Funcionario* aux = func->proximo;
		free(func);
		func = aux;
	}
	printf("Lista desalocada com sucesso!");
	return NULL;
}

Funcionario* insereFuncionario(Funcionario* lista, char nome[255], char cargo[255], int idade){
	Funcionario* novo;
	novo = (Funcionario*) malloc(sizeof(Funcionario));
	strcpy(novo->nome, nome);
	strcpy(novo->cargo, cargo);
	novo->idade = idade;
	novo->proximo = NULL;
	Funcionario* aux = lista;
	Funcionario* ant = NULL;
	while(aux!=NULL && strcmp(aux->nome, nome)<0){
		ant = aux;
		aux = aux->proximo;
	}
	if (ant==NULL){
		novo->proximo = lista;
		lista = novo;
	} else if (aux==NULL){
		ant->proximo = novo;
	} else {
		novo->proximo = ant->proximo;
		ant->proximo = novo;
	}
	printf("Funcionario inserido com sucesso!");
	return lista;
}


Funcionario* removeFuncionario(Funcionario* lista, char nome[255]){
	Funcionario* aux = lista;
	Funcionario*ant = NULL;
	while(aux!=NULL && strcmp(aux->nome, nome) != 0){
		ant = aux;
		aux = aux->proximo;
	}
	if(aux==NULL){
		printf("Funcionario não encontrado");
		return lista; //N?o encontrou
	}
	if(ant==NULL){
		lista = aux->proximo;
	} else{
		ant->proximo = aux->proximo;
	}
	free(aux);
	printf("Removido com sucesso!");
	return lista;
}

Funcionario* buscaFuncionario(Funcionario* lista, char nome[255]){
	Funcionario* aux = lista;
	while((aux!=NULL) && (strcmp(aux->nome, nome) != 0)){
		aux = aux->proximo;
	}
	if(aux==NULL){
		return NULL;
	}
	return aux;
}

void imprimeFuncionario(Funcionario* lista, char nome[255]){
	Funcionario* aux = buscaFuncionario(lista, nome);
	if(aux==NULL){
		printf("Funcionario nao encontrado");
	}
	else{
		printf("Nome: %s \nCargo: %s \nIdade: %d", aux->nome, aux->cargo, aux->idade);
	}
}

void imprimeLista(Funcionario* lista){
	printf("%s", lista->nome);
	Funcionario* aux = lista;
	while(aux!=NULL){
		printf("Nome: %s \nCargo: %s \nIdade: %d \n -------------------\n", aux->nome, aux->cargo, aux->idade);
		aux = aux->proximo;
	}
}
