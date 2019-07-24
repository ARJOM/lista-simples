//TAD de funcionario//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario Funcionario; 

Funcionario* criaLista();

Funcionario* desalocaLista(Funcionario* lista);

Funcionario* insereFuncionario(Funcionario* lista, char nome[255], char cargo[255], int idade);

Funcionario* removeFuncionario(Funcionario* lista, char nome[255]);

Funcionario* buscaFuncionario(Funcionario* lista, char nome[255]);

void imprimeFuncionario(Funcionario* lista, char nome[255]);

void imprimeLista(Funcionario* lista);
