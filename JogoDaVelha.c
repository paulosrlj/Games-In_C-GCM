#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "jogoDaVelha.h"

	int jogo [3][3];
	char jogador1[50], jogador2[50];
	int vencedor;
	int resultado;
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
	vencedor = verificaL(jogo); //Verifica se o jogador ganhou por linha
	 //Verifica se o jogador ganhou por coluna se não tiver ganho por linha
	vencedor = verificaC(jogo);
	 //Verifica se o jogador ganhou por Diagonal caso não ganhou por linha ou coluna.
	vencedor = verificaD(jogo);
	
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
int verificaL(int jogo[3][3]){
	int linha, coluna;
	for(linha=0;linha<3;linha++){
		resultado=0;
		for(coluna=0;coluna<3;coluna++){
				resultado = resultado + jogo[linha][coluna];
		}
		if(resultado == 3){ //Verifica se o jogador 1 ganhou por linha
		system("cls");
		printf("O vencedor foi %s!!\n",jogador1);
		ganhou=1;
		imprimir(jogo);
		return TRUE;	
		}else if(resultado == -3){
			system("cls");
			printf("O vencedor foi %s!!\n",jogador2);//Verifica se o jogador 2 ganhou por linha
			ganhou=1;
			imprimir(jogo);
			return TRUE;
	}	}
}


int verificaC(int jogo[3][3]){
	int linha, coluna; 
	for(coluna=0;coluna<3;coluna++){
		resultado=0;
		for(linha=0;linha<3;linha++){
			resultado += jogo[linha][coluna];
		}
		if(resultado == 3){ 
		system("cls");
		printf("O vencedor foi %s!!\n",jogador1);
		ganhou=1;
		imprimir(jogo);
		return TRUE;	
		}else if(resultado == -3){
			system("cls");
			printf("O vencedor foi %s!!\n",jogador2);
			ganhou=1;
			imprimir(jogo);
			return TRUE;
		}
	}
}

int verificaD(int jogo[3][3]){
	int k, resultado2 =0;
	resultado=0;
		for(k=0;k<3;k++){
			resultado = resultado + jogo[k][k];
		}
		resultado2 = jogo[0][2] + jogo[2][0] + jogo[2][0];
		if(resultado == 3 || resultado2 ==3) { 
		system("cls");
		printf("O vencedor foi %s!!\n",jogador1);
		imprimir(jogo);
		ganhou=1;
		return TRUE;	
		}else if(resultado == -3 || resultado2 == -3){
			system("cls");
			printf("O vencedor foi %s!!\n",jogador2);
			imprimir(jogo);
			ganhou=1;
			return TRUE;
		}
}

void menuVelha(){
	fflush(stdin);
	printf("\nDigite o nome do jogador 1: ");
	gets(jogador1);
	fflush(stdin);
	printf("\nDigite o nome do jogador 2: ");
	gets(jogador2);
	fflush(stdin);
	iniciar(jogo);
	while(vencedor != TRUE){ 
		//Estrutura que se repete até algum jogador vencer
		printf("\nVez de %s \n\n",jogador1);
		jogar(jogador1, jogo);
		printf("\nVez de %s \n\n",jogador2);
		jogar(jogador2, jogo);
	}
}

