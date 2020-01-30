#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0

int jogo [3][3];
char jogador1[50], jogador2[50];
int vencedor;
int ganhou = 0;

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
	vencedor = verifica(jogo);
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

int verifica(int jogo[3][3]){
	int linha, coluna, resultado=0;
	for(linha=0;linha<3;linha++){
		for(coluna=0;coluna<3;coluna++){
			resultado = jogo[linha][coluna] + resultado; //Verifica as colunas
		if(resultado == 3){ //Jogador 1 vence se a soma for 3
			printf("\n*****************O jogador %s foi vencedor!!!*****************\n",jogador1);
			ganhou = 1;
			return TRUE;
		}else if(resultado == -3){ //Jogador 2 vence se a soma for -3
			printf("\n*****************O jogador %s foi o vencedor!!!*****************\n",jogador2);
			return TRUE;
		}
	}
		resultado = 0; //Após verificar e não achar vencedor ele zera o resultado
	}
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
		printf("\nVez de %s \n\n",jogador1);
		jogar(jogador1, jogo);
		if(ganhou != 1){ //Permite o jogador 2 jogar caso o 1 não tenha ganho
		printf("\nVez de %s \n\n",jogador2);
		jogar(jogador2, jogo);
		}
	}
}
