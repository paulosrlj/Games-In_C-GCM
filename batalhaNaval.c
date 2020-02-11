/* Implementação das funções */

#include "batalhaNaval.h"

void inicializaTab(char *tab){
	int i, j;
	for(i = 0; i< TAM; i++)
		for(j = 0; j < TAM; j++)
			tab[i*TAM+j] = '~';
}

void prepareMShips(char *machineTab, char *machineGab){
	int i, j, k;
	int num = 0;
		
	/* Corveta */
	num = rand() % (TAM*TAM) + 1;
	
	while(checkShip(machineTab, num, 'c') == TRUE)
		num = rand() % (TAM*TAM) + 1;

	setShip(machineTab, machineGab, 'c', num);
	
	/* Submarino */
	num = rand() % (TAM*TAM) + 1;
	while(checkShip(machineTab, num, 's') == TRUE)
		num = rand() % (TAM*TAM) + 1;
	
	setShip(machineTab, machineGab, 's', num);

	
	/* Fragrata */
	num = rand() % (TAM*TAM) + 1;
	while(checkShip(machineTab, num, 'f') == TRUE)
		num = rand() % (TAM*TAM) + 1;
	
	setShip(machineTab, machineGab, 'f', num);

	
	/* Destroyer */
	num = rand() % (TAM*TAM) + 1;
	while(checkShip(machineTab, num, 'd') == TRUE)
		num = rand() % (TAM*TAM) + 1;
	
	setShip(machineTab, machineGab, 'd', num);

	
	/* Porta aviões */
	num = rand() % (TAM*TAM) + 1;
	while(checkShip(machineTab, num, 'p') == TRUE)
		num = rand() % (TAM*TAM) + 1;
	
	setShip(machineTab, machineGab, 'p', num);

	/* Bóia */
	for(k = 0; k < 3; k++){
		num = rand() % (TAM*TAM) + 1;
		while(checkShip(machineTab, num, 'b') == TRUE)
			num = rand() % (TAM*TAM) + 1;
	
		setShip(machineTab, machineGab, 'b', num);
	}
	
}

void setShip(char *playTab, char *gabTab, char type, int pos){
	
	int i, j, k;
	
	switch(type){
		//Seta a corveta nos dois tabuleiros
		case 'c':
			for(k=0; k < C; k++){
				playTab[(pos/10) * TAM + (pos%10+k)] = 'C';
				gabTab[(pos/10) * TAM + (pos%10+k)] = 'C';
			}
		break;
		
		case 's':
			for(k = 0; k < S; k++){
				playTab[(pos/10) * TAM + (pos%10+k)] = 'S';
				gabTab[(pos/10) * TAM + (pos%10+k)] = 'S';
			}
		break;
		
		case 'f':
			for(k = 0; k < F; k++){
				playTab[(pos/10) * TAM + (pos%10+k)] = 'F';
				gabTab[(pos/10) * TAM + (pos%10+k)] = 'F';
			}
		break;
		
		case 'd':
			for(k = 0; k < D; k++){
				playTab[(pos/10) * TAM + (pos%10+k)] = 'D';
				gabTab[(pos/10) * TAM + (pos%10+k)] = 'D';
			}
		break;
		
		case 'p':
			for(i = 0; i < Pi; i++){
				for(j = 0; j < Pj; j++){
					playTab[(pos/10+i) * TAM + (pos%10+j)] = 'P';
					gabTab[(pos/10+i) * TAM + (pos%10+j)] = 'P';
				}
			}
		break;
		
		case 'b':
			playTab[(pos/10) * TAM + (pos%10+k)] = 'B';
			gabTab[(pos/10) * TAM + (pos%10+k)] = 'B';
		break;
	}
}

void posPlayerShips(char *playerTab, char *playerGab){
	int i, j, k;
	int menuNavio, menuPos, menuRepos = 0;
	int corv = 1;
	int sub = 1;
	int frag = 1;
	int dest = 1;
	int port = 1;
	int boia = 3;
	int pos = 0;
	
	//Menu principal
	while (menuNavio != 6){
		printf("Escolha o que deseja fazer: \n");
		printf("[1] - Posicionar navios\n");
		printf("[2] - Reposicionar navios\n");
		printf("[3] - Apagar todos os navios posicionados\n");
		printf("[4] - Imprimir tabuleiro\n");
		printf("[5] - Sair\n"); scanf("%d", &menuNavio);
		
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
							
							printf("Informe a posição onde deseja posicionar: "); scanf("%d", &pos);
							while(checkShip(playerTab, pos, 'c') == TRUE){
								printf("Posição já utilizada, informe outra: "); scanf("%d", &pos);
							}
							
							setShip(playerTab, playerGab, 'c', pos);
							corv--;
						break;
						
						//Submarino
						case 2:
							system("cls");
							if(sub != 1){
								printf("Submarino já posicionado.\n");
								break;
							}
							
							printf("Informe a posição onde deseja posicionar: "); scanf("%d", &pos);
							while(checkShip(playerTab, pos, 's') == TRUE){
								printf("Posição já utilizada, informe outra: "); scanf("%d", &pos);
							}
							
							setShip(playerTab, playerGab, 's', pos);
							sub--;
						break;
						
						//Fragrata
						case 3:
							system("cls");
							if(frag != 1){
								printf("Submarino já posicionado.\n");
								break;
							}
							
							printf("Informe a posição onde deseja posicionar: "); scanf("%d", &pos);
							while(checkShip(playerTab, pos, 'f') == TRUE){
								printf("Posição já utilizada, informe outra: "); scanf("%d", &pos);
							}
							
							setShip(playerTab, playerGab, 'f', pos);
							frag--;
						break;
						
						//Destroyer
						case 4:
							system("cls");
							if(dest != 1){
								printf("Destroyer já posicionado.\n");
								break;
							}
							
							printf("Informe a posição onde deseja posicionar: "); scanf("%d", &pos);
							while(checkShip(playerTab, pos, 'd') == TRUE){
								printf("Posição já utilizada, informe outra: "); scanf("%d", &pos);
							}
							
							setShip(playerTab, playerGab, 'd', pos);
							dest--;
						break;
						
						//Porta aviões
						
						case 5:
							system("cls");
							if(port != 1){
								printf("Porta-aviões já posicionado.\n");
								break;
							}
							
							printf("Informe a posição onde deseja posicionar: "); scanf("%d", &pos);
							while(checkShip(playerTab, pos, 'p') == TRUE){
								printf("Posição já utilizada, informe outra: "); scanf("%d", &pos);
							}
							
							setShip(playerTab, playerGab, 'p', pos);
							port--;
						break;
						
						//Bóia
						case 6:
							system("cls");
							if(boia == 0){
								printf("Bóias já posicionadas.\n");
								break;
							}
							
							for(k = 0; k < 3; k++){
								printf("Informe a posição onde deseja posicionar: "); scanf("%d", &pos);
								
								while(checkShip(playerTab, pos, 'b') == TRUE){
									printf("Posição já utilizada, informe outra: "); scanf("%d", &pos);
								}
								
								setShip(playerTab, playerGab, 'b', pos);
							}
							boia--;
						break;
						
						default:
						break;
					}
				}
				
			break;
			
			case 2:
				system("cls");
				printf("[1] - reposicionar corveta\n", corv);
				printf("[2] - reposicionar submarino\n", sub);
				printf("[3] - reposicionar fragrata\n", frag);
				printf("[4] - reposicionar destroyer\n", dest);
				printf("[5] - reposicionar porta-aviões\n", port);
				printf("[6] - reposicionar bóia\n", boia);
				printf("[7] - Voltar\n"); scanf("%d", &menuRepos);
				
				switch(menuRepos){
					case 1:
						printf("Informe a nova posição da corveta: "); scanf("%d", &pos);
						while(checkShip(playerTab, pos, 'c') == TRUE){
							printf("Posição já utilizada, informe outra: "); scanf("%d", &pos);
						}
						setShip(playerTab, playerGab, 'c', pos);
						printf("Corveta reposicionada com sucesso.\n");
					break;
					
					case 2:
						printf("Informe a nova posição do submarino: "); scanf("%d", &pos);
						while(checkShip(playerTab, pos, 's') == TRUE){
							printf("Posição já utilizada, informe outra: "); scanf("%d", &pos);
						}
						setShip(playerTab, playerGab, 's', pos);
						printf("Submarino reposicionado com sucesso.\n");
					break;
					
					case 3:
						printf("Informe a nova posição da fragrata: "); scanf("%d", &pos);
						while(checkShip(playerTab, pos, 'f') == TRUE){
							printf("Posição já utilizada, informe outra: "); scanf("%d", &pos);
						}
						setShip(playerTab, playerGab, 'f', pos);
						printf("Fragrata reposicionado com sucesso.\n");
					break;
					
					case 4:
						printf("Informe a nova posição do destroyer: "); scanf("%d", &pos);
						while(checkShip(playerTab, pos, 'd') == TRUE){
							printf("Posição já utilizada, informe outra: "); scanf("%d", &pos);
						}
						setShip(playerTab, playerGab, 'd', pos);
						printf("Destroyer reposicionado com sucesso.\n");
					break;
					
					case 5:
						printf("Informe a nova posição do porta-aviões: "); scanf("%d", &pos);
						while(checkShip(playerTab, pos, 'p') == TRUE){
							printf("Posição já utilizada, informe outra: "); scanf("%d", &pos);
						}
						setShip(playerTab, playerGab, 'p', pos);
						printf("Porta-aviões reposicionado com sucesso.\n");
					break;
					
					case 6:
						printf("Informe a nova posição da bóia: "); scanf("%d", &pos);
						while(checkShip(playerTab, pos, 'b') == TRUE){
							printf("Posição já utilizada, informe outra: "); scanf("%d", &pos);
						}
						setShip(playerTab, playerGab, 'b', pos);
						printf("Boia reposicionada com sucesso.\n");
					break;
					
					default:
					break;
				}
			break;
			
			case 3:
				system("cls");
				inicializaTab(playerTab);
				inicializaTab(playerGab);
				printf("Posições apagados com sucesso.\n");
			break;
			
			case 4:
				imprimir(playerTab);
			break;
			
			default:
			break;
		}
	}
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

/* Imprimir */
void imprimir(char *tab){
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

