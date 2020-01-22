#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

int jogo [3][3];
char jogador1[50], jogador2[50];
int vencedor;

void imprimir(int jogo[3][3]){
	int linha, coluna;
	for(linha=0; linha<3; linha++){
		for(coluna=0; coluna<3; coluna++){
			if(jogo[linha][coluna] == 1){
				printf(" X |");
			}else if(jogo[linha][coluna] == -1){
			printf(" O |" );	
			}else{
				printf("   |");
			}
		}
		printf("\n");
	}
}

void jogar(char jogador[50], int jogo[3][3]){
	int linha, coluna;
	imprimir(jogo);
	printf("\n Digite em ordem a linha e a coluna que deseja marcar: ");
	scanf("%d%d",&linha, &coluna);
	linha--;
	coluna--;
	if(jogo[linha][coluna] == 0){
		if(jogador == jogador1){
			jogo[linha][coluna] = 1;
		}else{
			jogo[linha][coluna] = -1;
		}
	}else{
		printf("Impossivel marcar na posicao! ");
	}
}

void iniciar(int jogo[3][3]){ //Limpa a matriz e transformar vencedor em FALSE;
	int linha, coluna;
	for(linha=0; linha<3; linha++){
		for(coluna=0;coluna<3;coluna++){
			jogo[linha][coluna] = 0;
		}
	}
	vencedor = FALSE;
}

main(){
	printf("\nDigite o nome do jogador 1: ");
	gets(jogador1);
	fflush(stdin);
	printf("\nDigite o nome do jogador 2: ");
	gets(jogador2);
	fflush(stdin);
	iniciar(jogo);
	while(vencedor != TRUE){ //Estrutura que se repete até algum jogador vencer
		printf("\nVez de %s \n",jogador1);
		jogar(jogador1, jogo);
		printf("\nVez de %s \n",jogador2);
		jogar(jogador2, jogo);
	}
}
