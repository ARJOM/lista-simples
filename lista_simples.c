#include "funcionario.h"

main(){
	Funcionario* lista = criaLista();
	char nome[255];
	char cargo[255];
	int idade;
	int op;
	do{
		printf("\n1) Adiciona funcionario\n2)Remove funcionario\n3)Desaloca lista\n4)Imprime funcionario\n5)Imprime lista\n0)Sair\nEscolha: ");
		scanf("%d", &op);
		if(op==1){
			printf("Informe o nome do funcionario: ");
			scanf("%s", &nome);
			printf("Informe o cargo do funcionario: ");
			scanf("%s", &cargo);
			printf("Informe a idade do funcionario: ");
			scanf("%d", &idade);
			lista = insereFuncionario(lista, nome, cargo, idade);
		} else if(op==2){
			printf("Informe o nome do funcionario: ");
			scanf("%s", &nome);
			lista = removeFuncionario(lista, nome);
		} else if(op==3){
			lista = desalocaLista(lista);
		} else if(op==4){
			printf("Informe o nome do funcionario: ");
			scanf("%s", &nome);
			imprimeFuncionario(lista, nome);
		} else if(op==5){
			imprimeLista(lista);
		} else if(op==0){
			printf("Saindo...");
		} else {
			printf("Operacao inexistente");
		}
	}while(op!=0);
}
