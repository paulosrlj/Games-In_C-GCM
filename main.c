/* Autores: Paulo S, Francisco P, Marcio Fernandes */
/* Data: 19/12*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

int main(){
	srand(time(NULL));
	
	char tabuleiroJogador[TAM*TAM];
	char tabuleiroMaquina[TAM*TAM];
	

	preencherTabuleiro(tabuleiroJogador);
	preencherTabuleiro(tabuleiroMaquina);
	
	/* local onde são guardados os navios posiconados */
	char gabaritoJogador[TAM*TAM];
	char gabaritoMaquina[TAM*TAM];
	
	
	imprimirTabuleiro(tabuleiroMaquina);
	imprimirTabuleiro(tabuleiroJogador);
	
	system("pause");
	return 0;
}
