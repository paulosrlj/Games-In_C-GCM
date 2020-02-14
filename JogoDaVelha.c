#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

int jogo [3][3];
char jogador1[50], jogador2[50];
int vencedor;
int ganhou = 0;
int resultado;

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

void jar(char jogador[50], int jogo[3][3]){
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
	vencedor = verifica1(jogo);
	vencedor = verificar2(jogo);
	vencedor = empate(jogo);
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

int verifica1(int jogo[3][3]){
	int linha, coluna;
	for(linha=0;linha<3;linha++){
		resultado=0;
		for(coluna=0;coluna<3;coluna++){
			resultado = jogo[linha][coluna] + resultado; //Verifica as colunas
			if(resultado != 3 || resultado != -3){//Caso o resultado não tenha vencedor executar isso
				resultado = 0;
				for(linha=0; linha<3; linha++){ //
				resultado = jogo[linha][linha] + resultado;
				}
			}
		if(resultado == 3){ //Jogador 1 vence se a soma for 3
			printf("\n*****************O jogador %s foi vencedor!!!*****************\n",jogador1);
			ganhou = 1;
			return TRUE;
		}else if(resultado == -3){ //Jogador 2 vence se a soma for -3
			printf("\n*****************O jogador %s foi o vencedor!!!*****************\n",jogador2);
			return TRUE;
			}
		}
	}	
}

int verificar2(int jogo[3][3]){ //Verifica se o jogador ganha por linha
	int linha, coluna;
	for(linha=0; linha<3; linha++){
		resultado =0;//Inicia resultado com 0 / Zera a variavel após atualizar a linha
		for(coluna=0; coluna<3; coluna++){
			resultado = resultado + jogo[linha][coluna];
			}
		if(resultado == 3){ //Jogador 1 vence se a soma for 3
			printf("\n*****************O jogador %s foi vencedor!!!*****************\n",jogador1);
			ganhou = 1;
			return TRUE;
		}else if(resultado == -3){ //Jogador 2 vence se a soma for -3
			printf("\n*****************O jogador %s foi o vencedor!!!*****************\n",jogador2);
			return TRUE;
		}
	}
}

int empate(int jogo[3][3]){
	int k, l; int contador=0;
	for(k=0; k<3; k++){
		for(l=0;l<3; l++){
			if(jogo[k][l] == 0){
			contador++;
			}
		}
	}
	if(contador == 0 && ganhou != 1){
		printf("O JOGO DEU EMPATE!!!");
		ganhou=1;
		return TRUE;
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
