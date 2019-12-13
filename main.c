/* Autores: Paulo S, Francisco P, Marcio Fernandes */
/* Data: 19/12*/

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){
	
	char tabuleiroJogador[TAM*TAM];
	char tabuleiroMaquina[TAM*TAM];
	
	preencherTabuleiro(tabuleiroJogador);
	preencherTabuleiro(tabuleiroMaquina);
	
	imprimirTabuleiro(tabuleiroJogador);
	imprimirTabuleiro(tabuleiroMaquina);
	system("pause");
	return 0;
}
