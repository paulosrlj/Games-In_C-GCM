#include "funcoes.h"

/* Função para preencher o tabuleiro */

void preencherTabuleiro(char *tabuleiro) {
	int i,j;
	for(i=0; i<TAM; i++){
		for(j=0; j<TAM; j++){
			tabuleiro[i*TAM+j] = '0';
		}
	}
}

/* Imprimir o tabuleiro */

void imprimirTabuleiro(char *tabuleiro){
	 int i,j,k;
	 
	printf("    ");
	printf("0   1   2   3   4   5   6   7   8   9\n");
	
	printf("   ");
	printf("---------------------------------------\n\n");
	for(i = 0 ; i < TAM ; i++){
	 	printf("%d: ", i);
	 	for(j = 0 ; j < TAM ; j++){
	 		printf(" %c %c",tabuleiro[i*TAM+j], j==TAM-1?' ':'|');
		 }
		 if(i!=TAM-1){
		 	printf("\n------------------------------------------");
		 }
		  printf("\n");
	 }
	 printf("\n\n");
}

/* Preparando as posições dos navios */




