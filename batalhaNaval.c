/* Implementação das funções */

#include "batalhaNaval.h"

void inicializaTab(char *tab){
	int i, j;
	for(i = 0; i< TAM; i++)
		for(j = 0; j < TAM; j++)
			tab[i*TAM+j] = '~';
}

void prepareMShips(char *machineGab){
	int k;
	int num = 0;
	
	char navios[] = {'c', 's', 'f', 'd', 'p', 'b', 'b', 'b'};
	
	for(k = 0; k < 8; k++){
		num = rand() % (TAM*TAM) + 1;
		
		while(num / 10 >= TAM)
			num = rand() % (TAM*TAM) + 1;
		
		while(checkShip(machineGab, num, navios[k]) == TRUE){
			num = rand() % (TAM*TAM) + 1;
			while(num / 10 >= TAM)
				num = rand() % (TAM*TAM) + 1;
		}
		setShip(machineGab, navios[k], num);	
	}	

}

void setShip(char *gabTab, char type, int pos){
	
	int i, j, k;
	
	switch(type){
		//Seta a corveta nos dois tabuleiros
		case 'c':
			for(k=0; k < C; k++)
				gabTab[(pos/10) * TAM + (pos%10+k)] = 'C';
		break;
		
		case 's':
			for(k = 0; k < S; k++)
				gabTab[(pos/10) * TAM + (pos%10+k)] = 'S';
			
		break;
		
		case 'f':
			for(k = 0; k < F; k++)
				gabTab[(pos/10) * TAM + (pos%10+k)] = 'F';
			
		break;
		
		case 'd':
			for(k = 0; k < D; k++)
				gabTab[(pos/10) * TAM + (pos%10+k)] = 'D';
			
		break;
		
		case 'p':
			for(i = 0; i < Pi; i++)
				for(j = 0; j < Pj; j++)
					gabTab[(pos/10+i) * TAM + (pos%10+j)] = 'P';
		break;
		
		case 'b':
			gabTab[(pos/10) * TAM + (pos%10)] = 'B';
		break;
		
		default:
			printf("Não foi posicionado.");
		break;
	}
}

int posPlayerShips(char *playerGab){
	int i, j, k;
	int menuNavio, menuPos = 0;
	int corv = 1;
	int sub = 1;
	int frag = 1;
	int dest = 1;
	int port = 1;
	int boia = 3;
	int pos = 0;
	
	//Menu principal
	while (menuNavio != 4){
		printf("Escolha o que deseja fazer: \n");
		printf("[1] - Posicionar navios\n");
		printf("[2] - Apagar todos os navios posicionados\n");
		printf("[3] - Imprimir tabuleiro\n");
		printf("[4] - Voltar\n");  scanf("%d", &menuNavio);
		
		//Menu de posicionamento
		switch(menuNavio){
			case 1:
				system("cls");
				while(menuPos != 7){
					printf("Existem %d navios para serem posicionados.\n", corv+sub+frag+dest+port+boia);
					printf("[1] - Posicionar corveta | %dx\n", corv);
					printf("[2] - Posicionar submarino | %dx\n", sub);
					printf("[3] - Posicionar fragrata | %dx\n", frag);
					printf("[4] - Posicionar destroyer | %dx\n", dest);
					printf("[5] - Posicionar porta-aviões | %dx\n", port);
					printf("[6] - Posicionar bóia | %dx\n", boia);
					printf("[7] - Voltar\n"); scanf("%d", &menuPos);
					
					switch(menuPos){
						case 1:
							system("cls");
							if(corv != 1){
								printf("Corveta já posicionada.\n");
								break;
							}
							
							imprimirTab(playerGab);
							printf("Informe a posição onde deseja posicionar: "); scanf("%d", &pos);
							
							while(posicaoValida(pos) == FALSE){
								printf("Posição inválida, informe outra: "); scanf("%d", &pos);
							}
							
							while(checkShip(playerGab, pos, 'c') == TRUE){
								printf("Posição já utilizada, informe outra: "); scanf("%d", &pos);
								
								while(posicaoValida(pos) == FALSE){
									printf("Posição inválida, informe outra: "); scanf("%d", &pos);
								}
							}
							
							setShip(playerGab, 'c', pos);
							corv--;
							system("cls");
							imprimirTab(playerGab);
						break;
						
						//Submarino
						case 2:
							system("cls");
							if(sub != 1){
								printf("Submarino já posicionado.\n");
								break;
							}
							imprimirTab(playerGab);
							printf("Informe a posição onde deseja posicionar: "); scanf("%d", &pos);
							
							while(posicaoValida(pos) == FALSE){
								printf("Posição inválida, informe outra: "); scanf("%d", &pos);
							}
							
							while(checkShip(playerGab, pos, 's') == TRUE){
								printf("Posição já utilizada, informe outra: "); scanf("%d", &pos);
								while(posicaoValida(pos) == FALSE){
									printf("Posição inválida, informe outra: "); scanf("%d", &pos);
								}
							}
							
							setShip(playerGab, 's', pos);
							sub--;
							system("cls");
							imprimirTab(playerGab);
						break;
						
						//Fragrata
						case 3:
							system("cls");
							if(frag != 1){
								printf("Fragrata já posicionado.\n");
								break;
							}
							imprimirTab(playerGab);
							printf("Informe a posição onde deseja posicionar: "); scanf("%d", &pos);
							
							while(posicaoValida(pos) == FALSE){
								printf("Posição inválida, informe outra: "); scanf("%d", &pos);
							}
							
							while(checkShip(playerGab, pos, 'f') == TRUE){
								printf("Posição já utilizada, informe outra: "); scanf("%d", &pos);
								while(posicaoValida(pos) == FALSE){
									printf("Posição inválida, informe outra: "); scanf("%d", &pos);
								}
							}
							
							setShip(playerGab, 'f', pos);
							frag--;
							system("cls");
							imprimirTab(playerGab);
						break;
						
						//Destroyer
						case 4:
							system("cls");
							if(dest != 1){
								printf("Destroyer já posicionado.\n");
								break;
							}
							imprimirTab(playerGab);
							printf("Informe a posição onde deseja posicionar: "); scanf("%d", &pos);
							
							while(posicaoValida(pos) == FALSE){
								printf("Posição inválida, informe outra: "); scanf("%d", &pos);
							}
							
							while(checkShip(playerGab, pos, 'd') == TRUE){
								printf("Posição já utilizada, informe outra: "); scanf("%d", &pos);
								while(posicaoValida(pos) == FALSE){
									printf("Posição inválida, informe outra: "); scanf("%d", &pos);
								}
							}
							
							setShip(playerGab, 'd', pos);
							dest--;
							system("cls");
							imprimirTab(playerGab);
						break;
						
						//Porta aviões
						
						case 5:
							system("cls");
							if(port != 1){
								printf("Porta-aviões já posicionado.\n");
								break;
							}
							imprimirTab(playerGab);
							printf("Informe a posição onde deseja posicionar: "); scanf("%d", &pos);
							
							while(posicaoValida(pos) == FALSE){
								printf("Posição inválida, informe outra: "); scanf("%d", &pos);
							}
							
							while(checkShip(playerGab, pos, 'p') == TRUE){
								printf("Posição já utilizada, informe outra: "); scanf("%d", &pos);
								
								while(posicaoValida(pos) == FALSE){
									printf("Posição inválida, informe outra: "); scanf("%d", &pos);
								}
							}
							
							setShip(playerGab, 'p', pos);
							port--;
							system("cls");
							imprimirTab(playerGab);
						break;
						
						//Bóia
						case 6:
							system("cls");
							if(boia == 0){
								printf("Bóias já posicionadas.\n");
								break;
							}
							
							for(k = 0; k < 3; k++){
								imprimirTab(playerGab);
								printf("Informe a posição onde deseja posicionar: "); scanf("%d", &pos);
								
								while(posicaoValida(pos) == FALSE){
									printf("Posição inválida, informe outra: "); scanf("%d", &pos);
								}
								
								while(checkShip(playerGab, pos, 'b') == TRUE){
									printf("Posição já utilizada, informe outra: "); scanf("%d", &pos);
									while(posicaoValida(pos) == FALSE){
										printf("Posição inválida, informe outra: "); scanf("%d", &pos);
									}
								}
								setShip(playerGab, 'b', pos);
								boia--;
								system("cls");
							}
							system("cls");
							imprimirTab(playerGab);
						break;
						
						case 7:
							system("cls");
						break;
						
						default:
						break;
					}
				}
				
			break;
			
			case 2:
				system("cls");
				inicializaTab(playerTab);
				inicializaTab(playerGab);
				corv++; sub++; frag++, dest++; port++; boia+=3;
				printf("Posições apagadas com sucesso.\n");
			break;
			
			case 3:
				imprimirTab(playerGab);
			break;
			
			case 4:
				system("cls");
			break;
				
		}
	}
	
	return corv+sub+frag+dest+port+boia;
}

int posicaoValida(int pos){
	if(pos / 10 >= TAM)
		return FALSE; //INVÁLIDO
	return TRUE;
}
int checkShip(char *tab, int num, char tipo){
	int i, j, k;
	
	switch(tipo){
		//Corveta
		case 'c':
			for(k = 0; k < C; k++){
				if(tab[(num/10) * TAM + (num%10+k)] != '~')
					return TRUE;
			}
			return FALSE;
		break;
		
		//Submarino
		case 's':
			for(k = 0; k < S; k++){
				if(tab[(num/10) * TAM + (num%10+k)] != '~')
					return TRUE;
			}
			return FALSE;		
		break;
		
		//Fragrata
		case 'f':
			for(k = 0; k < F; k++){
				if(tab[(num/10) * TAM + (num%10+k)] != '~')
					return TRUE;
			}
			return FALSE;		
		break;
		
		//Destroyer
		case 'd':
			for(k = 0; k < D; k++){
				if(tab[(num/10) * TAM + (num%10+k)] != '~')
					return TRUE;
			}
			return FALSE;		
		break;
		
		//Porta aviões
		case 'p':
			for(i = 0; i < Pi; i++){
				for(j = 0; j < Pj; j++){
					if(tab[(num/10+i) * TAM + (num%10+j)] != '~')
						return TRUE;
				}		
			}
			return FALSE;		
		break;
		
		//Bóia
		case 'b':
			if(tab[(num/10) * TAM + (num%10)] != '~')
				return TRUE;
			return FALSE;
		break;
	}
}

void play(char *playerTab, char *playerGab, char *machineTab, char *machineGab){
	system("cls");
	int k;
	int moves = 20;
	int position = 0;
	int playerScore = 0;
	int machineScore = 0;
	int playAgain = 0;
	
	inicializaTab(machineTab);
	inicializaTab(machineGab);
	inicializaTab(playerTab);
	inicializaTab(playerGab);
					
	srand(time(NULL));
	prepareMShips(machineGab);

	int shipPos = posPlayerShips(playerGab);

	while(shipPos != 0){
		printf("Ainda existem navios a serem posicionados.\n");
		int shipPos = posPlayerShips(playerGab);
	}
		
	for(k = 0; k < moves; k++){
		//system("cls");
		printf("Seu tabuleiro: \n");
		imprimirTab(playerTab);
		
		printf("Tabuleiro inimigo: \n");
		imprimirTab(machineTab);
		printf("Informe uma posição para bombardear: "); scanf("%d", &position);
		
		while(checkMove(machineTab, position) != TRUE){
			printf("Você já fez uma jogada nessa posição.\n");
			printf("Informe outra posição para bombardear: "); scanf("%d", &position);
		}
		
		if(hitAShip(machineGab, position) == TRUE){
			printf("\a");
			playerScore++;
			machineTab[(position/10) * TAM + (position%10)] = machineGab[(position/10) * TAM + (position%10)];
		} else
			machineTab[(position/10) * TAM + (position%10)] = 'X';
		
		//A máquina joga
		int num = rand() % (TAM*TAM) + 1;
		while(num / 10 >= TAM)
			num = rand() % (TAM*TAM) + 1;
			
		while(checkMove(playerTab, num) != TRUE){
			num = rand() % (TAM*TAM) + 1;
			while(num / 10 >= TAM)
				num = rand() % (TAM*TAM) + 1;
		}
		
		if(hitAShip(playerGab, num) == TRUE){
			machineScore++;
			playerTab[(num/10) * TAM + (num%10)] = playerGab[(num/10) * TAM + (num%10)];
		} else
			playerTab[(num/10) * TAM + (num%10)] = 'X';
	}
	
	//Mostrar quem ganhou
	printf("Jogador - %d pontos.\nMáquina - %d pontos.\n", playerScore, machineScore);
	if(playerScore > machineScore)
		printf("Parabéns, você ganhou!\n");
	else if(playerScore < machineScore)
		printf("A máquina ganhou!\n");
	else
		printf("Empate!\n\n");
	
	system("pause");
}

int checkMove(char *tab, int position){
	if(tab[(position/10) * TAM + (position%10)] == 'X')
		return FALSE;
	return TRUE;
}

int hitAShip(char *gabTab, int position){
	int navio = gabTab[(position/10) * TAM + (position%10)];
	
	switch(navio){
		case 'C':
			return TRUE;
		break;
		case 'S':
			return TRUE;
		break;
		case 'F':
			return TRUE;
		break;
		case 'D':
			return TRUE;
		break;
		case 'P':
			return TRUE;
		break;
		case 'B':
			return TRUE;
		break;
		case '~':
			return FALSE;
		break;
	}
}

/* Imprimir */
void imprimirTab(char *tab){
	int i, j;
	printf("    ");
	printf("0 1 2 3 4 5 6 7 8 9 10 11 12 13\n");


	printf("     ");
	printf("------------------------------\n");
		
	for(i = 0; i < TAM; i++){
		if(i <= 9)
			printf(" [%d]| ",i);
		else
			printf("[%d]| ",i);
		
		for(j = 0; j< TAM; j++){
			printf("%c ", tab[i*TAM+j]);
		} 
		printf("\n");
	}
	printf("\n");
}

