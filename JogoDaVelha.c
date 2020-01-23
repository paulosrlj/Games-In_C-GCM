#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0

int jogo [3][3];
char jogador1[50], jogador2[50];
char jogando[50];
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
		system("cls");
		printf("**********IMPOSSIVEL ADICIONAR NESSA POSICAO********** \n\n");
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
	jogando = jogador1;
}

int verifica(int jogo[3][3]){
	int linha, coluna, resultado=0;
	for(linha=0;linha<3;linha++){
		for(coluna=0;coluna<3;coluna++){
			resultado = jogo[linha][coluna] + resultado;
		if(resultado == 3){
			printf("O jogador %s foi vencedor!!! ",jogador1);
			return TRUE;
		}else if(resultado == -3){
			printf("O jogador %s foi o vencedor!!! ",jogador2);
			return TRUE;
		}
	}
		resultado = 0;
	}
	jogando = jogador2;
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
	if(jogando == jogador1){
		printf("\nVez de %s \n\n",jogando);
		jogar(jogando, jogo);	
	}else{
		printf("\nVez de %s \n\n",jogando);
		jogar(jogando, jogo);
		jogando = jogador1;
	}
	}
}
