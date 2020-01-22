#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

int jogo [3][3];

int vencedor;


void iniciar(int jogo[3][3]){ //Limpa a matriz e transformar vencedor em FALSE;
	int linha, coluna;
	for(linha=0; linha<3; linha++){
		for(coluna=0;coluna<3;coluna++){
			jogo[linha][coluna] = ;
		}
	}
	vencedor = FALSE;
}

main(){
	char jogador1[50], jogador2[50];
	printf("\nDigite o nome do jogador 1: ");
	gets(jogador1);
	fflush(stdin);
	printf("\nDigite o nome do jogador 2: ");
	gets(jogador2);
	fflush(stdin);
	while(vencedor != TRUE){ //Estrutura que se repete até algum jogador vencer
		
	}
}
