#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){
	
	char tabuleiro[TAM*TAM];
	
	preencherTabuleiro(tabuleiro);
	imprimirTabuleiro(tabuleiro);
	
	system("pause");
	return 0;
}
