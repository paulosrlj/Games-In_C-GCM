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

int main(void){
	setlocale(LC_ALL,"Portuguese");
	
	Tabuleiro *tab = criarTabuleiro();
	srand(time(NULL));
	
	printf("Projeto Ger�ncia de controle e mudan�as\nIntegrantes: Francisco Paulino, Paulo Sérgio, Marcio Fernandes.\n\n");
	printf("==== Jogos em C - Batalha Naval, Jogo da mem�ria, Jogo da velha. ====\n\n");
	
	unsigned int escolhaJogo = 0;
	
	int opc;
	
	while(escolhaJogo != 4){
		printf("Qual jogo deseja jogar?\n\n");
		printf("[1] - Batalha Naval\n");
		printf("[2] - Jogo da mem�ria\n");
		printf("[3] - Jogo da velha\n");
		printf("[4] - Sair\n"); 
		scanf("%u", &escolhaJogo);
		
		switch(escolhaJogo){
		
			case 1: //Batalha Naval - Paulo
				posMachineShips(tab);
				imprimir(tab);
			break;
			
			case 2:
			printf("\n=====Modos Jogo da Mem�ria=====\n\n");
    		printf("[1]-F�cil");
    		printf("\n[2]-M�dio");
    		printf("\n[3]-Dif�cil\n");
    		printf("\n===============================\n\n");
    		printf("Escolha o numero:");
    		scanf("%d",&opc); 
			menu(opc);
			break;
			
			case 3: //Jogo da velha - Marcio
				
			break;
		
			case 4:
			
			break; 
		
		}
	}
	
	system("pause");
	return 0;
}
