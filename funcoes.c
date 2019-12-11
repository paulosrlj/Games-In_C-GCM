#include "funcoes.h"

void preencherTabuleiro(char *tabuleiro) {
	int i,j;
	for(i=0; i<TAM; i++){
		for(j=0; j<TAM; j++){
			tabuleiro[i*TAM+j] = '0';
		}
	}
}

void tabuleiro(char *tabuleiro){
	 int i,j;
	 for(i = 0 ; i < TAM ; i++){
	 	for(j = 0 ; j < TAM ; j++){
	 		printf("%c %c",mat[i][j],j==TAM-1?' ':'|');
		 }
		 if(i!=TAM-1){
		 	printf("\n-----------------------------");
		 }
		  printf("\n");
	 }
}


