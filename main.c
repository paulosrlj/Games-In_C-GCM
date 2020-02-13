/* Autores: Paulo S, Francisco P, Marcio Fernandes */
/* Data: 19/12*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include "batalhaNaval.h"
#include "jogoMemoria.h"
#include "JogoDaVelha.h"

int main(void){
	setlocale(LC_ALL,"");
	
	srand(time(NULL));

	printf("Projeto Gerência de controle e mudanças\nIntegrantes: Francisco Paulino, Paulo Sérgio, Marcio Fernandes.\n\n");
	printf("==== Jogos em C - Batalha Naval, Jogo da memória, Jogo da velha. ====\n\n");
	
	unsigned int escolhaJogo = 0;
	unsigned int opc = 0;
	
	while(escolhaJogo != 4){
		printf("Qual jogo deseja jogar?\n\n");
		printf("[1] - Batalha Naval\n");
		printf("[2] - Jogo da memória\n");
		printf("[3] - Jogo da velha\n");
		printf("[4] - Sair\n"); 
		scanf("%u", &escolhaJogo);
		
		switch(escolhaJogo){
		
			case 1: //Batalha Naval - Paulo
				system("cls");	
				play(playerTab, playerGab, machineTab, machineGab);
	
			break;
				
			case 2: //Jogo da memória - Francisco
				system("cls");
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
				system("cls");
				menuVelha();
				
			break;
		
			case 4:
			
			break; 
		
		}
	}
	
	system("pause");
	return 0;
}
