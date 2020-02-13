/* Autores: Paulo S, Francisco P, Marcio Fernandes */
/* Data: 19/12*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include "jogoMemoria.h"
#include "batalhaNaval.h"
#include "jogoDaVelha.h"

int main(void){
	setlocale(LC_ALL,"Portuguese");
	
	Tabuleiro *tab = criarTabuleiro();
	srand(time(NULL));
	
	printf("Projeto Gerência de controle e mudanças\nIntegrantes: Francisco Paulino, Paulo SÃ©rgio, Marcio Fernandes.\n\n");
	printf("==== Jogos em C - Batalha Naval, Jogo da memória, Jogo da velha. ====\n\n");
	
	unsigned int escolhaJogo = 0;
	
	int opc;
	
	//questão de marcio
	
	int jogo[3][3];
	char jogador1[50], jogador2[50];
	int vencedor;
	int resultado;
	int ganhou = 0;
	
	while(escolhaJogo != 4){
		printf("Qual jogo deseja jogar?\n\n");
		printf("[1] - Batalha Naval\n");
		printf("[2] - Jogo da memória\n");
		printf("[3] - Jogo da velha\n");
		printf("[4] - Sair\n"); 
		scanf("%u", &escolhaJogo);
		
		switch(escolhaJogo){
		
			case 1: //Batalha Naval - Paulo
				posMachineShips(tab);
				imprimir(tab);
			break;
			
			case 2:
			printf("\n=====Modos Jogo da Memória=====\n\n");
    		printf("[1]-Fácil");
    		printf("\n[2]-Médio");
    		printf("\n[3]-Difícil\n");
    		printf("\n===============================\n\n");
    		printf("Escolha o numero:");
    		scanf("%d",&opc); 
			menu(opc);
			break;
			
			case 3: //Jogo da velha - Marcio
			printf("\nDigite o nome do jogador 1: ");
			gets(jogador1);
			fflush(stdin);
			printf("\nDigite o nome do jogador 2: ");
			gets(jogador2);
			fflush(stdin);
			iniciar(jogo);
			while(ganhou != TRUE){ //Estrutura que se repete até algum jogador vencer
			printf("\nVez de %s \n\n",jogador1);
			jogar(jogador1, jogo);
			if(ganhou != 1){ //Permite o jogador 2 jogar caso o 1 não tenha ganho
			printf("\nVez de %s \n\n",jogador2);
			jogar(jogador2, jogo);
			}
		}
			printf("Fim do jogo, obrigado por jogar!!");
			break;
		
			case 4:
			
			break; 
		
		}
	}
	
	system("pause");
	return 0;
}
